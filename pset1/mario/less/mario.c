#include<stdio.h>
#include<cs50.h>
int main(void)
{
    int height;
    //promote to inter height
    do
    {

        height = get_int("Height: ");

    }
    while (height < 0 || height > 23);

    //for empty left for heigest rows
    int n = height - 1;

    //draw half piramid rows
    for (int i = 0 ; i < height; i++)
    {
        //draw columns
        for (int j = 0 ; j < height + 1; j++)
        {

            if (j < n)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        n--;

        printf("\n");
    }


}