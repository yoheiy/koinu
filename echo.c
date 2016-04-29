#include <stdio.h>
int
main(int argc, char **argv)
{
   int i;

   if (argc == 1) goto out;

   for (i = 1;;) {
      fputs(argv[i++], stdout);
      if (i == argc) break;
      putchar(' '); }

out:
   putchar('\n');

   return 0;
}
