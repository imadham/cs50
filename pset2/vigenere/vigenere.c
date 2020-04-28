// vigenere cipher

#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
    //if the number of arg incorrett
    if (argc != 2)
    {
        printf("error");
        return 1;
    }
    //copy key to string
    string keystr = argv[1];

    int n = strlen(keystr);
    int key[n] ;

    for (int i = 0; i < n; i++)
    {
        if (islower(keystr[i]))
        {
            key[i] = ((int)keystr[i] - (int)'a') % 26;
        }

        else
        {
            key[i] = ((int)keystr[i] - (int)'A') % 26;
        }

        if (!isalpha(keystr[i]))
        {
            printf("error");
            return 1;
        }
    }
    //temp to store changed car
    int temp = 0;
    //to go throght key
    int j = 0;

    //get text
    string plainText = get_string("plaintext:  ");
    //change each char in plain text
    for (int i = 0 ; i < strlen(plainText) ; i++)
    {
        //to change only alphabitic char
        if (isalpha(plainText[i]))
        {
            if (islower(plainText[i]))
            {
                temp = (int) plainText[i] - 'a';
                temp += key[(j++) % n];
                temp %= 26;
                plainText[i] = (char)(temp + (int) 'a');
            }

            else
            {
                temp = (int) plainText[i] - 'A';
                temp += key[(j++) % n];
                temp %= 26;
                plainText[i] = (char)(temp + (int) 'A');
            }
        }

    }

    //orint text
    printf("ciphertext: %s\n", plainText);

}