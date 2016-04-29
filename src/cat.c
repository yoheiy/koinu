#include <stdio.h>
int
sub(const char *path)
{
   FILE *f;
   int c;

   f = fopen(path, "r");
   if (!f) return 1;

   while (c = fgetc(f), c != EOF)
      putchar(c);

   fclose(f);
   return 0;
}

int
main(int argc, char **argv)
{
   int i, err = 0;

   for (i = 1; i < argc; i++)
      err |= sub(argv[i]);

   return err;
}
