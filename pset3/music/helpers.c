// Helper functions for music

#include <cs50.h>
#include <math.h>
#include<string.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    double x;
    int z;
    x = 8.0;
    z = (int)fraction[2] - (int)'0';
    x /= (double)z;
    z = (int)fraction[0] - (int)'0';
    return (x * (double)z);
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int n = 0, len = strlen(note);
    double temp = 0.0;
    //for numbers
    switch (note[0])
    {
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
            n = (int)note[len - 1] - (int)'0' - 5;
            break;

        default:
            n = (int)note[len - 1] - (int)'0' - 4;
            break;
    }
    n *= 12;
    //for the first char in note
    switch (note[0])
    {
        case 'A':
            break;
        case 'B' :
            n += 2;
            break;
        case 'C' :
            n += 3;
            break;
        case 'D' :
            n += 5;
            break;
        case 'E' :
            n += 7;
            break;
        case 'F' :
            n += 8;
            break;
        case 'G' :
            n += 10;
            break;
    }
    //for the # and b
    if (note[1] == '#')
    {
        n++;
    }

    else if (note[1] == 'b')
    {
        n--;
    }
    //devide by 12 then pow o 2 yhen round the result
    temp = n / 12.0;
    temp = pow(2.0, temp);
    temp *= 440;
    return round(temp);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    //user press enter
    if (strlen(s) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
