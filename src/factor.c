#include <stdio.h>
#include <stdlib.h>
int
main(int argc, char **argv)
{
   long n, i;

   if (argc != 2) return 2;
   n = atol(argv[1]);

   for (i = 2; i <= n; i++) /* 1 is not a prime */
      while (n % i == 0) {
         n /= i;
         printf("%d\n", i); }

   return 0;
}
