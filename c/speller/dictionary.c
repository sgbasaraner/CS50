/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dictionary.h"

typedef struct node{
	char word[51];
	struct node* next;
}node;

node* head;


node* create(char word[51], node* next){
	// creates a new linked list node
	node* new_node = (node*)malloc(sizeof(node));
	if (new_node == NULL){
		printf("Node could not be created.\n");
	}
	for (int i = 0; i < 51; i++){
	    new_node -> word[i] = word[i];
	}
	new_node -> next = next;

	return new_node;
}

node* prepend(node* head, char word[51]){
	// adds a new node to the beginning of the linked list
	node* new_node = create(word, head);
	head = new_node;
	return head;
}

node* append(node* head, char word[51]){
    // adds a new node to the end of the linked list
    node *cursor = head;
    while(cursor->next != NULL)
        cursor = cursor->next;

    node* new_node =  create(word,NULL);
    cursor->next = new_node;

    return head;
}

bool search(node* head, const char* word){
	// searches for a word through the linked list
	int size = strlen(word);
	char *str = calloc (size, 1);
    strcpy (str, word);
    for (int i=0; str[i]; i++){
        str[i] = tolower((unsigned char)str[i]);
    }

    node* cursor = head;
	while (cursor != NULL){
	    if (strcmp(str, cursor -> word) == 0){
	    	free(str);
	        return true;
	    }
		cursor = cursor -> next;
	}
	free(str);
	return false;
}

void traverse(node* head){
	// traverses through the linked list
	node* cursor = head;
	while (cursor != NULL){
	    printf("traversin': %s\n", cursor -> word);
		cursor = cursor -> next;
	}
}

unsigned int count(node *head){
	// counts the elements of the linked list
	node *cursor = head;
	unsigned int count = 0;
	while (cursor != NULL){
		count++;
		cursor = cursor -> next;
	}
	return count;
}

void delete_list(node *head){
	// deletes the whole linked list and frees the memory
	node *cursor, *tmp;
	if (head != NULL){
		cursor = head -> next;
		head -> next = NULL;
		while (cursor != NULL){
			tmp = cursor -> next;
			free(cursor);
			cursor = tmp;
		}
	}
}

unsigned int count_dict_words(const char *dictionary){
	int c;
	FILE *file;
	file = fopen(dictionary, "r");
	unsigned int count = 0;
	if (file) {
    	while ((c = getc(file)) != EOF){
        	if (c == '\n'){
        		count++;
        	}
    	}
    	fclose(file);
	}
	return count;
}
/**
 * Returns true if word is in dictionary else false.
 */

bool check(const char *word)
{
	return search(head, word);
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
	FILE *fp = fopen(dictionary, "r");

	if (!(fp)){
		return false;
	}

	int tmp = 0;
	char tmp_string[51];
	bool first_node_added = false;
	int c;
	while ((c = fgetc(fp)) != EOF){
       	if (c != '\n'){
       		tmp_string[tmp] = c;
        	tmp++;
        } else {
        	if (!first_node_added){
        		tmp_string[tmp] = '\0';
        		printf("%s will be sent to prepend\n", tmp_string);
        		head = prepend(head, tmp_string);
        		first_node_added = true;
        		tmp = 0;
        		memset(tmp_string,0,51);
        	} else {
        		head = append(head, tmp_string);
        		tmp = 0;
        		memset(tmp_string, 0, 51);
        	}
        }
    }
    // TODO: make it recognize 'a'
    fclose(fp);
	return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
	return count(head);
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    delete_list(head);
	return true;
}
