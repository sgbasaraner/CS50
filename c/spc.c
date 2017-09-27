/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"



/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
	char *dict[MAX_DICT_SIZE][LENGTH];
	FILE *ptr = fopen(dictionary, "r");
	int i = 0;
	for (int i = 0; i < MAX_DICT_SIZE; ++i){
		for (int c = fgetc(ptr); c != EOF; c = fgetc(ptr)){
			for (int j = 0; j < LENGTH; ++j){
				if (c != '\n'){
					dict[i][j] = c
				} else {
					break;
				}
			}
    	}
	}
	
	for (<#initialization#>; <#condition#>; <#increment#>) {
		<#statements#>
	}
    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
