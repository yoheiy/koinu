#include <stdio.h>
#include <limits.h>
int
main(void)
{
   int n, i, x;

   for (n = 2; n < INT_MAX; n++) {
      for (i = 2; i < n; i++)
         if (n % i == 0)
            break;
      if (i == n) printf("%d\n", n); }

   return 0;
}
