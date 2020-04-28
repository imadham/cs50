// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

#define hash_size 1000003


// Returns true if word is in dictionary else false

//to count words in dictionary
int counter = 0;
//to open dictionary
FILE *dic;

//char *new_worda;
char new_worda[46];

node *hash[hash_size];
//int count[hash_size] = {0};

//to check if the word in dectionary
bool check(const char *word)
{

    // for (int i = 0, j = strlen(word); i < j; i++)
    // {
    //     if (!isalpha(word[i]) && word[i] != '\'')
    //     {

    //         return false;
    //     }
    // }
    int length;
    int hashnum ;
    length = strlen(word);
    word = to_lower(word, length);
    hashnum = hash_func(word, length);


     if (find_word(word, hash[hashnum]))
     {
         return true;
     }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    int length;
    int hashnum;
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
        length = strlen(name);
        strcpy(name, to_lower(name, length));
        hashnum = hash_func(name, length);
        node *temp = create_node(name);
        hash[hashnum] = add_node(temp, hash[hashnum]);
        //count[hashnum]++;

    }
    fclose(dic);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{

    // int c=0;

    // for(int i = 0; i < hash_size;i ++)
    // {
    //     if(count[i] > 1)
    //     {
    //         c++;
    //     }
    // }

    // printf("%i\n",c);
    return counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    freen();
    return true;
}

//this to change all word to lower case for simplicity
char *to_lower(const char *word, int length)
{
    //int length = strlen(word);

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


node *create_node(char *word)
{
    node *new_node = malloc(sizeof(node));
    strcpy(new_node -> word, word);
    new_node -> next = NULL;
    return new_node;
}

node *add_node(node *node1, node *head)
{

    if(head == NULL)
    {
        head = node1;
    }
    else
    {
        node1 -> next = head;
        head = node1;
    }
    return head;
}


bool find_word(const char* word, node *head)
{
    node *temp = head;

    if(temp == NULL)
    {
        return false;
    }

    else
    {

        while(temp -> next != NULL)
        {
            if(strcmp(temp -> word, word) == 0)
            {
                return true;
            }
            temp = temp -> next;
        }
    }

             if(strcmp(temp -> word, word) == 0)
            {
                return true;
            }
    return false;
}


void freen (void)
{
    node *temp;
    for(int i=0;i<hash_size;i++)
    {
        if(hash[i] == NULL)
        {
            continue;
        }

        while(hash[i] -> next != NULL)
        {
            temp = hash[i];
            hash[i] = hash[i] -> next;
            free(temp);
        }

        if(hash[i] != NULL)
        {
            free(hash[i]);
        }
    }
}

int hash_func(const char *str, int length)
{
    unsigned long long hashnum = 5381;
    int temp = 0;

    for(int i=0;i<length;i++)
    {
        temp = (int)str[i] - (int)'a';
        if(str[i] == '\'')
        {
            temp = 26;
        }
        hashnum = hashnum * 33 + (int)str[i];
    }

    return hashnum % hash_size;
}

