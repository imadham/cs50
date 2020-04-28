#include <cs50.h>
#include <math.h>
#include<string.h>
#include<stdio.h>


int frequency(string note);
int duration(string fraction);
bool is_rest(string s);
int main(void)
{
    while(true)
    {
        string s=get_string("enter string :");
        printf("%i \n",duration(s));
    }
}


int frequency(string note)
{
    int n=0,len=strlen(note);
    double temp=0.0;

    switch (note[0])
    {
        case 'C': case 'D': case 'E': case 'F':case 'G':
        n=(int)note[len-1]-(int)'0'-5;
        break;

        default:
         n=(int)note[len-1]-(int)'0'-4;
         break;
    }
    n*=12;

    switch (note[0])
    {
        case 'A':
        break;
        case 'B' :
        n+=2; break;
        case 'C' :
        n+=3; break;
        case 'D' :
        n+=5; break;
        case 'E' :
        n+=7; break;
        case 'F' :
        n+=8; break;
        case 'G' :
        n+=10; break;
    }

    if(note[1]=='#')
    {
        n++;
    }

    else if(note[1]=='b')
    {
        n--;
    }

    temp=n/12.0;
    temp = pow(2.0,temp);
    temp*=440;
    return round(temp);

}

int duration(string fraction)
{
    double x;
    int z;
    x=8.0;
    z=(int)fraction[2]-(int)'0';
    printf("this is z : %i\n",z);
    x/=(double)z;
    printf("this is x : %d\n",z);
    z=(int)fraction[0]-(int)'0';
    printf("this is second z : %i\n",z);
    return (x*(double)z);
}

bool is_rest(string s)
{
    if(s[0]=='\n')
    {
        return true;
    }
    else
    {
        return false;
    }
}