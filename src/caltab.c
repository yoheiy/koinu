#include <stdio.h>
#include <stdlib.h>
void
caltab(int skip, int max)
{
   int i;

   for (i = 0; i < 3 * skip; i++)
      putchar(' ');

   for (i = 1; i <= max; i++) {
      printf("%2d", i);
      putchar((i + skip) % 7 ? ' ' : '\n'); }
      //if (!((i + skip) % 7)) putchar('\n'); }

   //if ((max + skip) % 7)
      putchar('\n');
}

int
main(int argc, char **argv)
{
   if (argc != 3) return 2;

   caltab(atoi(argv[1]), atoi(argv[2]));

   return 0;
}
