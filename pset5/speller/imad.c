#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct trie
{
    int found;
    int counter;
    const char *words[100];
    struct trie *chars[26];
} trie;

trie* create();
void fill(char *word, trie *head);
int find(char *word, trie *head);
void freee(char *word, trie* head);

FILE *doc;

int main(void)
{

    char *x[3]={"cat","caterpillar","cc"};

    trie* head = create();

    for(int i=0;i<3;i++)
    {
        fill(x[i], head);
    }

    char str[22];

    while(1)
    {
         scanf("%s", str);

         if(find(str, head) == 1)
         {
             printf("true\n");
         }
         else printf("false\n");

         for(int i=0;i<3;i++)
        {
          //  freee(x[i], head);
        }
    }

    return 0;


}

void fill(char *word, trie *head)
{

    trie* current=head;
    //trie* save = head;

    int z=0;
    int j=strlen(word);
    trie* temp = NULL;
    for(int i=0;i<j;i++)//i<4 && i < (j - 1);i++)
    {
            int index=(int)word[i] - (int)'a';

            if(current -> chars[index]==NULL)
            {
                temp = create();
                current->chars[index]=temp;
                current = temp;
                z++;
            }
            else
            {
                current = current -> chars[index];
            }

    }
    // if(j <= 4)
    // {
        current->found=1;
    // }
    // else
    // {
    //   current -> words[current -> counter++] = word;
    // }

    //printf("found: %i\t length: %i\nthe address is:%p", current -> found, z, &current);

   // return save;
}

trie* create()
{
    trie* head=malloc (sizeof(trie));

    for(int i=0;i<26;i++)
    {
        head -> chars[i] = NULL;
    }

    // for(int i=0;i<100;i++)
    // {
    //     head -> words[i] ="";
    // }

    head -> found = 0;

    head -> counter=0;

    return head;
}

int find(char *word, trie *head)
{
    trie* current = head;

    // int z=0;
    int j=strlen(word);
    for(int i=0; i<j ;i++)//&& i<4; i++)
    {
     //   printf("this is z in the find: %i\n", z++);
        int index=(int)word[i] - (int)'a';
     //       printf("sec %i\n",index);
        if(current -> chars[index] == NULL)
        {
            return 0;
        }

        current = current-> chars[index];

    }
    if(current -> found == 1)// && j <= 4)
    {
        return 1;
    }

    // else if(j > 4)
    // {
    //     for(int i=0; i< current -> counter - 1;i++)
    //     {
    //         if(strcmp(word, current -> words[i]))
    //         {
    //             return 1;
    //         }
    //     }
    // }


     //   printf("sec found: %i\n", current -> found);
        return 0;
}

void freee(char *word, trie* head)
{   trie* current = head;
    for(int i=0,j=strlen(word);i<j;i++)
    {
            int index=(int)word[i] - (int)'a';
         //   printf("%i\n",index);
            current = current -> chars[index];
    }
    free(current);
}