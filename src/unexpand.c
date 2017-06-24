#include <stdio.h>
#define TABSTOP 8

int opt_a;

void
opt(int c, char **v)
{
   int i, j;

   for (i = 1; i < c; i++)
      for (j = 1; v[i][j]; j++)
         if (v[i][j] == 'a')
            opt_a = 1;
}

void
print_spaces(int n)
{
   if (n > 0) {
      putchar(' ');
      return print_spaces(n - 1); }
}

int
main(int argc, char **argv)
{
   int count = 0;
   int col = 0;
   int c;
   int sup = 0; /* suppress */

   opt(argc, argv);

   while (c = getchar(), c != EOF) {
      if (c == ' ') {
         count++;
         col++; }
      else {
         print_spaces(count);
         putchar(c);
         if (c == '\n')
            count = col = sup = 0;
         else {
            count = 0;
            col++;
            sup = 1; } }

      if (sup && !opt_a) continue;
      if (count && col % TABSTOP == 0) {
         putchar(count > 1 ? '\t' : ' ');
         count = 0; } }

   return 0;
}
