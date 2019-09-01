/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 *
 * Functions/definitions in this program are used in speller.c to help create a
 * spellchecker.  Functions include load, unload, check, and size.  Load runs
 * through a text file full of words and loads them into memory as a hash table
 * (dictionary).  Unload frees the memory the hash table is using after it is
 * no longer needed.  Check performs a lookup on the hash table to determine
 * if a word is in the dictionary (if not it's mispelled).  Size counts the number
 * of words in the dictionary.
 *
 * I implemented dictionary.c myself, but take no credit for speller.c as it was
 * already implemented as a part this assignment for edx cs50.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

// Number of linked lists in hash table.
#define HASH_SIZE 49999

typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

node* hashtable[HASH_SIZE];

int hash_function(const char* word);

int number_of_words = 0;


bool check(const char* word)
{
    int word_length = strlen(word);
    char lower_word[LENGTH+1];

    int i;
    for (i = 0; i < word_length; i++)
    {
        if(isupper(word[i]))
        {
            lower_word[i] = tolower(word[i]) ;
        }
        else
        {
            lower_word[i] = word[i];
        }
    }
    lower_word[word_length] = '\0';
    int bucket = hash_function(lower_word);
    node* cursor = hashtable[bucket];
    while (cursor != NULL)
    {
        if (!strcmp(lower_word, cursor->word)){
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
    while (fscanf(the_dictionary, "%s", buffer) > 0)
    {
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
    printf("uai");
    fclose(the_dictionary);
    // Everything seems to have gone well, return true.
    return true;
}


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return number_of_words;
}


/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // Iterate over all linked lists in hash table.  Set
    // cursor to point at each one's location in memory.
    int i;
	for (i = 0; i < HASH_SIZE;i++)
    {
        node* cursor = hashtable[i];
        while (cursor != NULL)
        {
            // Set temporary pointer to point at cursor's
            // location in memory.  Move cursor to the next node
            // so we don't lose track of it before freeing
            // the current node's (temp's) memory.
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}

// Maps a word to an integer value to place it in the hash table.
// Sum the value of each character in the word, then find the
// remainder after dividing by the size of the hash table.
int hash_function(const char* word)
{
    int sum = 0;
    int word_length = strlen(word);
	int i;
    for (i = 0; i < word_length; i++){
        sum += word[i]*(pow(26,i));
    }
    return sum % HASH_SIZE;
}
