#include <stdio.h>
#include "dictionary.h"
int main(){
    bool loadDic;
    loadDic = load();
    printf("load? %d",loadDic);
    return 0;
}
