#include <stdio.h>
#include <stdlib.h>
#ifdef __linux__
    #include "dictionary.c"
    #include <sys/time.h>
#else
    #include "dictionary.h"
#endif // __linux__
#include "dictionary.h"
#include <string.h>
#include <time.h>
#include <math.h>
//#include "Fila.h"

int have=0,dont_have=0, qtdWord=0;


int main(){
    struct Node* words = NULL;
    struct timespec start, end;
    uint64_t total_time = 0;
    //__int64 freq,start,stop;



    double time = 0;
    //QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
    if(load()){
        printf("Carregou o dicionário\n");
    }else{
        printf("Falha ao carregar\n");
    }

    char word[LENGTH+1];
    //char words[60714][38];
    FILE* the_constitution = fopen("../Anexos/constituicao.txt", "r");
    FILE* relatorio = fopen("../Anexos/relatorio.txt", "w");

    while (fscanf(the_constitution, "%s", word) > 0){
        //QueryPerformanceCounter((LARGE_INTEGER *)&start);
        clock_gettime(CLOCK_MONOTONIC_RAW, &start);
        bool exist = check(word);
        clock_gettime(CLOCK_MONOTONIC_RAW, &end);

        if (exist){
            have++;
        }else{
            //strcpy(words[dont_have],word);
  //          Append(&words,word);
            dont_have++;
        }

        //QueryPerformanceCounter((LARGE_INTEGER *)&stop);
        //time += ((double)stop-(double)start)/CLOCKS_PER_SEC;
         total_time += (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;
    }

    qtdWord = have + dont_have;

    fprintf(relatorio, "Numero total de palavras do texto: %d\n", qtdWord);
    fprintf(relatorio, "Número de palavras que falharam no spell check: %d\n", dont_have);
    fprintf(relatorio, "Tempo total da verificação: %ld\n", myTime);
    fprintf(relatorio, "Lista de palavras que falharam no spell check:\n");
    fprintf(relatorio, "Num. Ocorrencia - Palavra\n");
    fprintf(relatorio, "-----------------------------------------\n");

    printf("Palavras que nao tem: \n");
    int i;
    //printList(&words);


    /*relatorio<<"Numero total de palavras: "<<qtdWord<<"\n";
    relatorio<<"Numero de palavras que falharam no spell check:"<<dont_have;
    relatorio<<"Tempo de execucao: "<<myTime<<"\n"; */

    if(unload()){
        printf("Descarregou o dicionário\n");
    }else{
        printf("Falha ao descarregar\n");
    }

    printf("Tem: %d\nNao tem: %d\n",have,dont_have);
    //printf("Total ms: %g ms.\n",total);
    printf("Clock: %lf\n",total_time);
    fclose(the_constitution);
    return 0;
}

