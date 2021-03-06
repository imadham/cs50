// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 3)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    uint8_t x=1;


  while (fread(&x, 1, 1, inptr)==1)
  {
      if(x==0x00)break;
      fwrite(&x, 1, 1, outptr);
  }

    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
