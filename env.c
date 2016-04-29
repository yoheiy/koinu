#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int
main(int argc, char **argv)
{
   char **p = argv;
   int i;

   for (i = 1; i < argc; i++) {
      p++;
      if (strchr(*p, '='))
         putenv(*p);
      else if (execvp(*p, p) == -1)
         return 1; }

   return 0;
}
