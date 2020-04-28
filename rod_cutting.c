#include<stdio.h>


int cutRod(int price[], int n);
int dynamicCutRod(int price[], int n);
int max(int x, int y)
{
    if(x > y) return x;
    return y;
}
int main(void)
{
    int price[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 10, 25, 30, 33, 35, 40, 44, 55, 55, 56, 60, 66, 88, 91 , 93, 94, 99, 100, 101, 110, 114, 117, 118, 118, 120};
    printf("%i\n", dynamicCutRod(price, sizeof(price)/sizeof(*price)));
}

int cutRod(int price[], int n)
{
   if (n <= 0)
     return 0;
   int max_val = -1000;

   // Recursively cut the rod in different pieces and compare different
   // configurations
   for (int i = 0; i<n; i++)
         max_val = max(max_val, price[i] + cutRod(price, n-i-1));

   return max_val;
}

int dynamicCutRod(int price[], int n)
{
   int val[n+1];
   val[0] = 0;
   int i, j;

   // Build the table val[] in bottom up manner and return the last entry
   // from the table
   for (i = 1; i<=n; i++)
   {
       int max_val = -1000;
       for (j = 0; j < i; j++)
         max_val = max(max_val, price[j] + val[i-j-1]);
       val[i] = max_val;
   }

   return val[n];
}