// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include<cs50.h>
#include<stdint.h>


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }
    // remember filenames
    char *infile = argv[1];
    //unsigned char buffer[256];

    uint8_t* buffer = malloc(512);
    //open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    char name[8];


    FILE *img = NULL;
    int counter = 1;
    int isimg = 0;
    while (fread(buffer, 256, 1, inptr) == 1)
    {
    //printf("%u",buffer[0]);
        if (buffer[0] == 0xff && buffer [1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (isimg == 0)
            {
                //first time see the sign of jpg
                sprintf(name, "%03i.jpg", 0);
                img = fopen(name, "w");
                fwrite(buffer, 256, 1, img);
                isimg = 1;
            }

            else if (isimg == 1)
            {
                //end of img and start another one
                fclose(img);
                sprintf(name, "%03i.jpg", counter++);
                img = fopen(name, "w");
                fwrite(buffer, 256, 1, img);
            }

        }

        else if (isimg == 1)
        {
            //new sigment but same image
            fwrite(buffer, 256, 1, img);
        }
    }

    //close the last image
    fclose(img);

    // close infile
    fclose(inptr);
    free(buffer);
    // success
    return 0;
}
