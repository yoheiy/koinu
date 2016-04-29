#include <stdio.h>
int
main(void)
{
   int i = 0, c;

   while (c = getchar(), c != EOF) {
      i++;
      if (c == '\n') i = 0;
      if (i <= 80) putchar(c); }

   return 0;
}
