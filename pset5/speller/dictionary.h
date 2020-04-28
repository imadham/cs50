// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

typedef struct trie
{
    int found;
    struct trie *chars[27];
} trie;

typedef struct node
{
    char word[46];
    struct node *next;
} node;


// Prototypes
bool check(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);
int find(const char *word, trie *head);
trie* create();
void fill(char *word, trie *head);
char* to_lower(const char *word, int length);
int freeee(trie *first);
int hashing(const char *word, int length);

node *add_node(node *node1, node *head);
node *create_node(char *word);
bool find_word(const char* word, node *head);
void freen (void);
void add_word(node *head, char *word);
int hash_func(const char *str, int length);




#endif // DICTIONARY_H
