#include <stdio.h>
int
main(void)
{
   int c, s = 0;
   int l = 0, w = 0, n = 0; /* count */

   while (c = getchar(), c != EOF) {
      if (c == '\n') l++;
      if (c == '\n' || c == '\t' || c == ' ')
         s = 0;
      else if (!s) {
         s = 1;
         w++; }
      n++; }

   printf("%7d %7d %7d\n", l, w, n);
   return 0;
}
