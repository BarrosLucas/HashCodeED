#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fila.h"



void DestroiLista(struct Node *node){
	if(!node){
		return;
	}else{
		struct Node *n = node->next;
		free(node);
		return DestroiLista(n);
	}
}

void Append(struct Node **node, const char *value){
    printf("%s\n",value);
	if(!*node){
		*node = (struct Node*) malloc(sizeof(struct Node));
		//(*node)->value = value;
		printf("Vai imprimir....\n");
		strcpy((*node)->value,value);
		printf("...%s\n",(*node)->value);
		(*node)->next = NULL;
	}else{
		struct Node *outroNode = *node;
		while(outroNode->next){
			outroNode = outroNode->next;
			//printf("teste");
		}
		outroNode->next = (struct Node*) malloc(sizeof(struct Node));
		//outroNode->next->value = value;
		printf("Vai imprimir...\n");
		strcpy(outroNode->next->value,value);
		printf("%s\n",outroNode->next->value);
		outroNode->next->next = NULL;
	}
}

void Prepend(struct Node **node, const char *value){
	if(!*node){
		*node = (struct Node*) malloc(sizeof(struct Node));
		//(*node)->value = value;
		strcpy((*node)->value,value);

		(*node)->next = NULL;
	}else{
		struct Node* outroNode = (struct Node*) malloc(sizeof(struct Node));
		//outroNode->value = value;
		strcpy(outroNode->value,value);
		outroNode->next = *node;
		*node = outroNode;
	}
}



void printList(struct Node **node){
	if(!*node){
		printf("Lista vazia\n");
	}else{
		struct Node *aux = (*node);
		do{
			printf("%s ",aux->value);
			aux = aux->next;
		}while(aux->next);
		printf("%s ",aux->value);
	}
}
