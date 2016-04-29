#include <stdio.h>
int
sub(FILE *f0, FILE *f1)
{
   int c0, c1;

   for (;;) {
      c0 = fgetc(f0);
      c1 = fgetc(f1);
      if (c0 != c1) return 1;
      if (c0 == EOF) return 0; }
}

int
main(int argc, char **argv)
{
   FILE *f0, *f1;
   int ret;

   if (argc != 3) return 2;

   if (!(f0 = fopen(argv[1], "r"))) return 2;
   if (!(f1 = fopen(argv[2], "r"))) return 2;

   ret = sub(f0, f1);

   fclose(f0);
   fclose(f1);
   return ret;
}
