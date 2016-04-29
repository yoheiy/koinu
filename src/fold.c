#include <stdio.h>
int
main(void)
{
   int i = 0, c;

   while (c = getchar(), c != EOF) {
      putchar(c);
      i++;
      if (c == '\n') i = 0;
      if (i == 80) putchar('\n'); }

   return 0;
}
