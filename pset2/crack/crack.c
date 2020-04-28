// crack

#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include<crypt.h>
//#include<time.h>
#define _XOPEN_SOURCE

int main(int argc, char *argv[])
{
    //if the number of arg incorrett
    if (argc != 2)
    {
        printf("error");
        return 1;
    }



    string hash = argv[1];

    char salt[2];
    salt[0] = hash[0];
    salt[1] = hash[1];




    char generate[6] = "abcde";



    // every for loop is for on of the 5 chars in the password
    // in order to make program more efficient from the first loop the program test one char pasword
    // in the secend it test 2 chars password and so on

    //to test word from one char

   // clock_t befor = clock();

    for (generate[0] = 'A'; generate[0] < 'z'; generate[0]++)
    {
        char password[6] ;
        if (isalpha(generate[0]))
        {
            password[0] = generate[0];
            password[1] = '\0';
            if (strcmp(crypt(password, salt), hash) == 0)
            {
                printf("%s\n", password);
                return 0;
            }
            //to test word from 2 chars
            for (generate[1] = 'A' ; generate[1] < 'z'; generate[1]++)
            {
                if (isalpha(generate[1]))
                {
                    password[0] = generate[0];
                    password[1] = generate[1];
                    password[2] = '\0';
                    //printf("trying words start with : %s\n",password);
                    if (strcmp(crypt(password, salt), hash) == 0)
                    {
                        printf("%s\n", password);
                        return 0;
                    }
                    //to test word from 3 chars
                    for (generate[2] = 'A'; generate[2] < 'z'; generate[2]++)
                    {
                        if (isalpha(generate[2]))
                        {
                            password[0] = generate[0];
                            password[1] = generate[1];
                            password[2] = generate[2];
                            password[3] = '\0';
                            if (strcmp(crypt(password, salt), hash) == 0)
                            {
                                printf("%s\n", password);
                                return 0;
                            }
                            //to test word from 4 chars
                            for (generate[3] = 'A'; generate[3] < 'z'; generate[3]++)
                            {
                                if (isalpha(generate[3]))
                                {
                                    password[0] = generate[0];
                                    password[1] = generate[1];
                                    password[2] = generate[2];
                                    password[3] = generate[3];
                                    password[4] = '\0';
                                    if (strcmp(crypt(password, salt), hash) == 0)
                                    {
                                        printf("%s\n", password);
                                        return 0;
                                    }
                                    //to test word from 5 chars
                                    for (generate[4] = 'A'; generate[4] < 'z'; generate[4]++)
                                    {

                                        if (isalpha(generate[4]))
                                        {

                                            password[0] = generate[0];
                                            password[1] = generate[1];
                                            password[2] = generate[2];
                                            password[3] = generate[3];
                                            password[4] = generate[4];
                                            password[5] = '\0';


                                            if (strcmp(crypt(password, salt), hash) == 0)
                                            {
                                                printf("%s\n", password);
                                                return 0;
                                            }
                                        }


                                    }
                                }
                            }
                        }
                    }

                }
            }

        }
    }

    //clock_t after = clock();

   // printf("%li", after - befor);


}