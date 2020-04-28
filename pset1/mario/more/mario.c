
#include<stdio.h>
#include<cs50.h>
int main(void)
{
    int height = 0;
    //promote to inter height
    do
    {

        height = get_int("Height: ");

    }
    while (height < 0 || height > 23);

    //for empty left for heigest rows
    int n = height - 1;

    int r = 1;

    //draw half piramid rows
    for (int i = 0 ; i < height; i++)
    {
        //draw columns
        for (int j = 0 ; j < (2 * height) + 2; j++)
        {

            if ((j > n - 1 && j <= height - 1) || ((j > height + 1) && (j < (2 * height) + 2 - n)))
            {
                printf("#");
            }
            //else if (j > height + 2 + r)
            //{
            //  printf(" ");

            //}
            else if (j < height + 2)
            {
                printf(" ");
            }
        }

        n--;

        printf("\n");
        r++;
    }


}