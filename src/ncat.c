/* notcat */
#include <stdio.h>
#define N  1 /* number */
#define B  2 /* number nonblank */
#define E  4 /* show ends */
#define T  8 /* show tabs */
#define V 16 /* show nonprinting */
#define S 32 /* squeeze blank */
int
number(int opt, int c, int n, int l)
{
   if (opt & N && n == 0)
      printf("%6d  ", l);
   if (opt & B && n == 0)
      if (c != '\n')
         printf("%6d  ", l);
      else
         l--;

   return l;
}

int
show(int opt, int c)
{
   if (opt & E && c == '\n')
      putchar('$');
   if (opt & T && c == '\t') {
      putchar('^');
      c = 'I'; }
   if (opt & V) {
      if (c >= 0x80) {
         putchar('M');
         putchar('-');
         c &= 0x7f; }
      if (c < 0x20 && c != '\n' && c != '\t') {
         putchar('^');
         c |= 0x40; }
      if (c == 0x7f) {
         putchar('^');
         c = '?';} }

   return c;
}

int
squeeze(int opt, int c, int z)
{
   return opt & S && c == '\n' && z == 2;
}

int
gopt(int argc, char **argv)
{
   int i, opt = 0;
   char *o;

   for (i = 1; i < argc; i++) {
      if (argv[i][0] != '-' || argv[i][1] == '-') return -1;
      for (o = &argv[i][1]; *o; o++)
         switch (*o) {
         case 'n': opt |= N; break;
         case 'b': opt |= B; break;
         case 'E': opt |= E; break;
         case 'T': opt |= T; break;
         case 'v': opt |= V; break;
         case 's': opt |= S; break;
         case 'A': opt |= V | E | T; break;
         case 'e': opt |= V | E; break;
         case 't': opt |= V | T; break;
         default: return -1; } }

   return opt;
}

int
main(int argc, char **argv)
{
   int c, l = 1, n = 0, z = 0, opt;

   opt = gopt(argc, argv);

   while (c = getchar(), c != EOF) {
      if (squeeze(opt, c, z)) continue;
      l = number(opt, c, n, l);
      c = show(opt, c);

      putchar(c);

      if (c == '\n')
         l++, z++, n = 0;
      else
         n++, z = 0; }

   return 0;
}
