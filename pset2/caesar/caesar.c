#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("error");
        return 1;
    }

    int key = atoi(argv[1]);
    //make key less than 26
    key = key % 26;
    //temp to store changed car
    int temp = 0;
    //get text
    string plainText = get_string("plaintext:  ");
    //change each char in plain text
    for (int i = 0 ; i < strlen(plainText) ; i++)
    {
        if (isalpha(plainText[i]))
        {
            if (islower(plainText[i]))
            {
                temp = (int) plainText[i] - 'a';
                temp += key;
                temp %= 26;
                plainText[i] = (char)(temp + (int) 'a');
            }

            else
            {
                temp = (int) plainText[i] - 'A';
                temp += key;
                temp %= 26;
                plainText[i] = (char)(temp + (int) 'A');
            }
        }
    }

    //orint text
    printf("ciphertext: %s\n", plainText);

}