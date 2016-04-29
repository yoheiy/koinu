/* incompat */
#include <stdio.h>
int
main(int argc, char **argv)
{
   int c, f = 0, z = 0;

   if (argc != 2) return 2;

   while (c = getchar(), c != EOF)
      switch (c) {
      case '\n':
         f = z = 0; putchar(c); break;
      case ':':
         if (argv[1][f]) f++;
         if (argv[1][f] == ':' && z) putchar(c);
         break;
      default:
         if (argv[1][f] == ':') putchar(c), z = 1; }

   return 0;
}
