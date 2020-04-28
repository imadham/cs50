{"filter":false,"title":"Untitled1.c","tooltip":"/Untitled1.c","undoManager":{"mark":1,"position":1,"stack":[[{"start":{"row":0,"column":0},"end":{"row":63,"column":1},"action":"insert","lines":["#include <cs50.h>       ","#include <stdio.h>","#include <stdlib.h>","","#define BUFFER_SIZE 512","","int main(void)","{","    // open memory card file","    FILE* input = fopen(\"card.raw\", \"r\");","    if (input == NULL)","    {","        printf(\"Could not open card.raw.\\n\");","        return 2;","    }","    ","    // create buffer","    unsigned char buffer[BUFFER_SIZE];","    ","    // filename counter","    int filecount = 0;","    ","    FILE* picture = NULL; ","    ","    // check if we've found a jpeg yet or not","    int jpg_found = 0; //false","    ","    // go through cardfile until there aren't any blocks left","    while (fread(buffer, BUFFER_SIZE, 1, input) == 1)","    {","        // read first 4 bytes of buffer and see if jpg signature using bitwise on last byte","        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)","        {","            if (jpg_found == 1)","            {","                // We found the start of a new pic so close out current picture","                fclose(picture);","            }","            else","            {","                // jpg discovered and now we have the green light to write","                jpg_found = 1;","            }","            ","            char filename[8];","            sprintf(filename, \"%03d.jpg\", filecount);","            picture = fopen(filename, \"a\");","            filecount++;","        }","        ","        if (jpg_found == 1)","        {","            // write 512 bytes to file once we start finding jpgs","            fwrite(&buffer, BUFFER_SIZE, 1, picture);","        }","        ","    }","","    // close files","    fclose(input);","    fclose(picture);","","    return 0;","}"],"id":2}],[{"start":{"row":0,"column":17},"end":{"row":0,"column":24},"action":"remove","lines":["       "],"id":3},{"start":{"row":15,"column":0},"end":{"row":15,"column":4},"action":"remove","lines":["    "]},{"start":{"row":18,"column":0},"end":{"row":18,"column":4},"action":"remove","lines":["    "]},{"start":{"row":21,"column":0},"end":{"row":21,"column":4},"action":"remove","lines":["    "]},{"start":{"row":22,"column":25},"end":{"row":22,"column":26},"action":"remove","lines":[" "]},{"start":{"row":23,"column":0},"end":{"row":23,"column":4},"action":"remove","lines":["    "]},{"start":{"row":26,"column":0},"end":{"row":26,"column":4},"action":"remove","lines":["    "]},{"start":{"row":43,"column":0},"end":{"row":43,"column":12},"action":"remove","lines":["            "]},{"start":{"row":49,"column":0},"end":{"row":49,"column":8},"action":"remove","lines":["        "]},{"start":{"row":55,"column":0},"end":{"row":55,"column":8},"action":"remove","lines":["        "]}]]},"ace":{"folds":[],"scrolltop":624,"scrollleft":0,"selection":{"start":{"row":63,"column":1},"end":{"row":63,"column":1},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":43,"state":"start","mode":"ace/mode/c_cpp"}},"timestamp":1531254211693,"hash":"7aa17494595059ab39ff9628edffb5fe316f2561"}