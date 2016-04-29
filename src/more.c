#include <stdio.h>
int
main(void)
{
   FILE *tty;
   int c, l = 0;

   tty = fopen("/dev/tty", "r");
   if (!tty) return 1;

   while (c = getchar(), c != EOF) {
      putchar(c);
      if (c == '\n' && ++l == 20) {
         l = 0;
         fputs("-- more --", stderr);
         for (;;) {
            c = fgetc(tty);
            if (c == '\n') break; } } }

   return 0;
}
