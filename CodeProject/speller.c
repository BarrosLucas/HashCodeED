#include <stdio.h>
#include "dictionary.h"
int main(){
    if(load()){
        printf("Carregou o dicion�rio\n");
    }else{
        printf("Falha ao carregar\n");
    }

    if(check("ANEEL")){
        printf("Tem\n");
    }else{
        printf("Tem nao\n");
    }


    if(unload()){
        printf("Descarregou o dicion�rio\n");
    }else{
        printf("Falha ao descarregar\n");
    }
    return 0;
}
