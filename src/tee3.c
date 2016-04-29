#include <stdio.h>
int
main(void)
{
   FILE *f3;
   int c;

   f3 = fdopen(3, "a");
   if (!f3) return 1;

   while (c = getchar(), c != EOF) {
      fputc(c, stdout);
      fputc(c, f3); }

   fclose(f3);
   return 0;
}
