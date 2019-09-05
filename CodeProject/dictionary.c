#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"
#include <math.h>

#define HASH_SIZE 49999

typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

int buckets[49999+1] = {0};
node* hashtable[HASH_SIZE+1];

int hash_function(const char* word);
int number_of_words = 0;


bool check(const char* word)
{
    int word_length = strlen(word);
    int bucket = hash_function(word);
    node* cursor = hashtable[bucket];
    while (cursor != NULL)
    {
        if (!strcmp(word, cursor->word)){
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}


bool load(){
    int i;
	for(i = 0; i < HASH_SIZE; i++)
    {
        hashtable[i] = NULL;
    }

    FILE* the_dictionary;
    the_dictionary = fopen("../Anexos/dictionary.txt", "r");

    if (the_dictionary == NULL)
    {
        printf("Failed to load dictionary");
        return false;
    }

    char buffer[LENGTH+1];

    while (fscanf(the_dictionary, "%s", buffer) > 0){
        node* new_node = malloc(sizeof(node));
        new_node->next = NULL;
        strcpy(new_node->word, buffer);
        int bucket = hash_function(new_node->word);

        if (hashtable[bucket] == NULL)
        {
            hashtable[bucket] = new_node;
        }

        else
        {
            new_node->next = hashtable[bucket];
            hashtable[bucket] = new_node;
        }

        number_of_words++;
    }
    fclose(the_dictionary);

    return true;
}


unsigned int size(void)
{
    return number_of_words;
}


bool unload(void)
{
    int i;
	for (i = 0; i < HASH_SIZE;i++)
    {
        node* cursor = hashtable[i];
        while (cursor != NULL)
        {
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
int hash_function(const char* word)
{
    unsigned long long int sum = 0;
    int word_length = strlen(word);
	int i;
    for (i = 0; i < word_length; i++){
        sum += floor(word[i]*31*word_length);
    }

    return sum%HASH_SIZE;
}
