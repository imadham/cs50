#include<stdio.h>
#include<cs50.h>
#include<math.h>
int main(void)
{
    float money = 0;
    //promote to inter height
    do
    {

        money = get_float("Change owed: ");

    }

    // calculate number of change
    while (money <= 0);
    //to change and round to nearest cent
    int cents = round((money * 1000) / 10);

    //counter to count number off coin nedded
    int counter = 0;
    while (cents > 0)
    {
        if (cents >= 25)
        {
            counter++ ;
            cents -= 25;

        }
        else if (cents >= 10)
        {
            counter++ ;
            cents -= 10;

        }
        else if (cents >= 5)
        {
            counter++;
            cents -= 5;

        }
        else
        {
            counter++ ;
            cents -= 1;

        }
    }
    // print the result
    printf("%i\n", counter);


}