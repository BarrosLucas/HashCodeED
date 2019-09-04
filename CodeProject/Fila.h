#ifndef FILA_H
#define FILA_H

struct Node {
	char *value;
	struct Node *next;
};

void DestroiLista(struct Node *node);
void Append(struct Node **node, const char *value);
void Prepend(struct Node **node, const char *value);
void printList(struct Node **node);
#endif
