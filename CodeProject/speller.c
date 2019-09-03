#include <windows.h>
#include <winbase.h>
#include <stdio.h>
#include "dictionary.h"

int have=0,dont_have=0;
int main(){
    __int64 freq,start,stop;
    double time = 0;
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
    if(load()){
        printf("Carregou o dicionário\n");
    }else{
        printf("Falha ao carregar\n");
    }

    char word[LENGTH+1];
    FILE* the_constitution = fopen("../Anexos/constituicao.txt", "r");

    while (fscanf(the_constitution, "%s", word) > 0){
        QueryPerformanceCounter((LARGE_INTEGER *)&start);
        (check(word)? have++:dont_have++);
        QueryPerformanceCounter((LARGE_INTEGER *)&stop);
        time += ((double)stop-(double)start)/(double)freq;
    }


    if(unload()){
        printf("Descarregou o dicionário\n");
    }else{
        printf("Falha ao descarregar\n");
    }

    printf("Tem: %d\nNao tem: %d\n",have,dont_have);
    //printf("Total ms: %g ms.\n",total);
    printf("Clock: %lf\n",time);
    return 0;
}
