#include <stdio.h>
#define TABSTOP 8

int opt_i;

void
opt(int c, char **v)
{
   int i, j;

   for (i = 1; i < c; i++)
      for (j = 1; v[i][j]; j++)
         if (v[i][j] == 'i')
            opt_i = 1;
}

void
print_spaces(int n)
{
   if (n > 0) {
      putchar(' ');
      return print_spaces(n - 1); }
}

int
round_up(int n)
{
   return (n / TABSTOP + 1) * TABSTOP;
}

int
main(int argc, char **argv)
{
   int col = 0;
   int c;
   int r;
   int sup = 0; /* suppress */

   opt(argc, argv);

   while (c = getchar(), c != EOF)
      if (c == '\t') {
         r = round_up(col);
         if (sup && opt_i)
            putchar(c);
         else
            print_spaces(r - col);
         col = r; }
      else {
         putchar(c);
         if (c == '\n')
            col = sup = 0;
         else {
            col++;
            sup = 1; } }

   return 0;
}
