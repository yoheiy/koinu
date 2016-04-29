#include <stdio.h>
int
main(void)
{
   int i = 0, c = 0;

   for (;;) {
      printf("%07o", i);

      for (;;) {
         c = getchar();
         if (c == EOF) break;
         printf(" %03o", c);
         i++;
         if (i % 16 == 0) break; }

      putchar('\n');
      if (c == EOF) break; }

   return 0;
}
