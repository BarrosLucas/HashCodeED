#include <stdio.h>
#include <stdlib.h>
#include "dictionary.c"
#include <time.h>
#include <math.h>

int have=0,dont_have=0, qtdWord=0;
int main(){
    //__int64 freq,start,stop;
    time_t inicio,fim, myTime;


    double time = 0;
    //QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
    if(load()){
        printf("Carregou o dicionário\n");
    }else{
        printf("Falha ao carregar\n");
    }

    char word[LENGTH+1];
    char words[60714][38];
    FILE* the_constitution = fopen("../Anexos/constituicao.txt", "r");
    FILE* relatorio = fopen("../Anexos/relatorio.txt", "w");

    while (fscanf(the_constitution, "%s", word) > 0){
        //QueryPerformanceCounter((LARGE_INTEGER *)&start);
        inicio = clock();
        bool exist = check(word);
        fim = clock();
        if (exist){
            have++;
        }else{
            strcpy(words[dont_have],word);
            dont_have++;
        }
        
        //QueryPerformanceCounter((LARGE_INTEGER *)&stop);
        //time += ((double)stop-(double)start)/CLOCKS_PER_SEC;
        myTime += (inicio-fim)/CLOCKS_PER_SEC;
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
    for(i=0;i<dont_have;i++){
        fprintf(relatorio, "%d - %s\n",i+1,words[i]);
    }


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
    printf("Clock: %ld\n",myTime);
    fclose(the_constitution);
    return 0;
}
