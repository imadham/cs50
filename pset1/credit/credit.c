#include<stdio.h>
#include<cs50.h>
#include<math.h>
#include<string.h>
int main(void)
{

    long long card = 0;
    //promote to enter number
    do
    {

        card = get_long_long("Number: ");

    }
    while (card <= 0);

    int counter = 0, numbers = 0;
    //copy of card number
    long long temp;
    temp = card;
    //to help when multiplying number
    int help = 0;
    // firs and second number (last and befor last fom the right)
    int blast = 0, last = 0;
    //x to mutiply every other number from the right
    bool x = false;
    //go thought all numbers in card number
    while (temp > 0)
    {
        numbers++ ;
        if (temp < 100 && temp > 9)
        {
            blast = temp % 10;
        }
        else if (temp < 10 && temp >= 0)
        {
            last = temp;
        }
        help = temp % 10;
        temp /= 10;
        if (x)
        {
            help *= 2;
            if (help > 9)
            {
                help -= 9;
            }
            counter += help;

        }

        else
        {
            counter += help;
        }
        x = !x ;

    }
//if result dividable by 10 check other condition
    if (counter % 10 == 0)
    {
        if (numbers == 15 && last == 3 && (blast == 4 || blast == 7))
        {
            printf("AMEX\n");
        }
        else if ((numbers == 16 || numbers == 13) && last == 4)
        {
            printf("VISA\n");
        }
        else if (numbers == 16 && last == 5 && (blast == 1 || blast == 2 || blast == 3 || blast == 4 || blast == 5))
        {
            printf("MASTERCARD\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    //printf("%i",counter);

}