// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

// Returns true if word is in dictionary else false

//first node in the trie
trie *root = NULL;
//to count words in dictionary
int counter = 0;
//to open dictionary
FILE *dic;

//char *new_worda;
char new_worda[46];

//to check if the word in dectionary
bool check(const char *word)
{

    int length = strlen(word);
    if (find(to_lower(word, length), root) == 1)
    {
        return true;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    root = create();

    //open file
    dic = fopen(dictionary, "r");
    if (dic == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", "dic");
        return false;
    }
    //create string and read string by string from a file
    char name[46];
    while (fscanf(dic, "%s", name) != EOF)
    {
        counter++;
        int length = strlen(name);
        strcpy(name, to_lower(name, length));


        fill(name, root);
    }
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{

    freeee(root);
   // free(root);
    fclose(dic);
    counter = 0;
    return true;
}

//this to change all word to lower case for simplicity
char *to_lower(const char *word, int length)
{

    for (int i = 0; i < length; i++)
    {
        if (isalpha(word[i]))
        {
            new_worda[i] = tolower(word[i]);
        }
        else if (word[i] == '\'')
        {
            new_worda[i] = word[i];
        }

    }
    new_worda[length] = '\0';

    return new_worda;
}

//this function to fill the trie
void fill(char *word, trie *first_node)
{

    trie *current = first_node;

    int j = strlen(word);
    trie *temp = NULL;
    for (int i = 0; i < j; i++)
    {
        int index = (int)word[i] - (int)'a';

        if (word[i] == '\'')
        {
            index = 26;
        }

        if (current -> chars[index] == NULL)
        {
            temp = create();
            current->chars[index] = temp;
            current = temp;
        }
        else
        {
            current = current -> chars[index];
        }

    }
    //if we reach the last node for this word put there number 1
    current -> found = 1;

}
//create node in the trie
trie *create()
{
    trie *first_node = malloc(sizeof(trie));

    for (int i = 0; i < 27; i++)
    {
        first_node -> chars[i] = NULL;
    }

    first_node -> found = 0;

    return first_node;
}
//find if the word is in the trie
int find(const char *word, trie *first_node)
{
    trie *current = first_node;
    for (int i = 0, j = strlen(word); i < j; i++)
    {
        int index = (int)word[i] - (int)'a';
        if (word[i] == '\'')
        {
            index = 26;

        }

        if (current -> chars[index] == NULL)
        {
            return 0;
        }

        current = current-> chars[index];
    }

    if (current -> found == 1)
    {
        return 1;
    }

    else
    {

        return 0;
    }
}
//free memory (I'm not sure if it work right)

int freeee(trie *first)
{
    int a=0;
    for(int i=0;i<27;i++)
    {
        if(first -> chars[i] != NULL)
        {
           a = freeee(first -> chars[i]);
        }
    }
    free (first);
    return a;
}