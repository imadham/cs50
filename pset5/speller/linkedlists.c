#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<cs50.h>

typedef struct node
{
    char word[46];
    struct node *next;
} node;

void print(node *head);
int hash_func(char *word,int length);
node *create_node(char *word);
node *add_node(node *node1, node *head);
bool find_word(const char* word, node *head);



node *hash[29000];
//static int ishash[29000] = {0};

int main(void)
{

   // char *x[5]={"to","the","big","abcddd","abcdf"};

    int index=0,length;

    // for(int i=0;i<5;i++)
    // {
    //     length = strlen(x[i]);
    //     index = hash_func(x[i], length);
    //     node *temp = create_node(x[i]);
    //     hash[index] = add_node(temp, hash[index]);

    // }


    for(int i=0; i<29000;i++)
    {
        for(int j=0;j<15;j++)
        {
            char x[10];
            char y[10];
            sprintf(x, "%d", i);
            sprintf(y, "%d", j);
            strcat(x, " ");
            strcat(x, y);
            node *temp = create_node(x);
            hash[i] = add_node(temp, hash[i]);
        }
    }

    for(int i=0; i<29000;i+=1000)
    {
        print(hash[i]);
        printf("\n");
    }

    char str[22];

    while(1)
    {
         scanf("%s", str);
         length = strlen (str);
         index = hash_func(str, length);

         if(find_word(str, hash[index]))
         {
             printf("true\n");
         }
         else printf("false\n");

        print(hash[index]);
    }

    return 0;


}

int hash_func(char *word,int length)
{
    int a=1;
    int result=0, temp;
    for(int i=0;i<4 && i<length;i++)
    {
        temp = (int)word[i] - (int)'a';
        if(temp<0)
        {
            temp = 26;
        }
        temp *= a;
        a*=10;
        result += temp;
    }

    printf("result is :%i\n", result);

    return result;
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
        node1 -> next = head ;
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

    else if(temp != NULL)
    {

        if(strcmp(temp -> word, word) == 0)
        {
            return true;
        }

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


void print(node *head)
{
    node *temp=head;
    if(temp == NULL)
    {
        return;
    }

    while(temp -> next != NULL)
    {
        printf("%s, ",temp -> word);
        temp = temp -> next;
    }
    printf("%s, ",temp -> word);
}