#include <stdio.h>
#define N_LINES 10
int
main(void)
{
   int c, l = 0;

   while (c = getchar(), c != EOF) {
      putchar(c);
      if (c == '\n' && ++l == N_LINES) break; }

   return 0;
}
