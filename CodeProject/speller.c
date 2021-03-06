#include <stdio.h>
#include <stdlib.h>
#ifdef __linux__
    #include "dictionary.c"
    #include <sys/time.h>
#else
    #include "dictionary.h"
    #include <sys/timeb.h>
#endif // __linux__
#include "dictionary.h"
#include <string.h>
#include <time.h>
#include <math.h>

int have=0,dont_have=0, qtdWord=0;


int main(){

    #ifdef __linux__
        struct timespec start, end;
        uint64_t total_time = 0;
    #else
        struct timeb start, end;
        long int total_time = 0;
    #endif

    double time = 0;
    if(load()){
        printf("Carregou o dicion�rio\n");
    }else{
        printf("Falha ao carregar\n");
    }
    char word[LENGTH+1];
    char words[60714][38];
    FILE* the_constitution = fopen("../Anexos/constituicao.txt", "r");
    FILE* relatorio = fopen("../Anexos/relatorio.txt", "w");

    while (fscanf(the_constitution, "%s", word) > 0){
        #ifdef __linux__
            clock_gettime(CLOCK_MONOTONIC_RAW, &start);
        #else
            ftime(&start);
        #endif // __linux__

        bool exist = check(word);

        #ifdef __linux__
            clock_gettime(CLOCK_MONOTONIC_RAW, &end);
            total_time += (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000;
        #else
            ftime(&end);
            total_time += (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
        #endif // __linux__


        if (exist){
            have++;
        }else{
            strcpy(words[dont_have],word);
            dont_have++;
        }
    }

    qtdWord = have + dont_have;

    fprintf(relatorio, "Numero total de palavras do texto: %d\n", qtdWord);
    fprintf(relatorio, "N�mero de palavras que falharam no spell check: %d\n", dont_have);
    fprintf(relatorio, "Tempo total da verifica��o: %ld ms\n", total_time);
    fprintf(relatorio, "Lista de palavras que falharam no spell check:\n");
    fprintf(relatorio, "Num. Ocorrencia - Palavra\n");
    fprintf(relatorio, "-----------------------------------------\n");

    printf("Palavras que nao tem: \n");
    int i;
    for(i=0;i<dont_have;i++){
        fprintf(relatorio, "%s\n", words[i]);
    }

    if(unload()){
        printf("Descarregou o dicion�rio\n");
    }else{
        printf("Falha ao descarregar\n");
    }

    printf("Tem: %d\nNao tem: %d\n",have,dont_have);
    printf("Clock: %ld ms\n",total_time);
    fclose(the_constitution);
    return 0;
}

