#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

#define LENGTH 38

bool check(const char* word);
bool load();
unsigned int size(void);
bool unload(void);

#endif // DICTIONARY_H
