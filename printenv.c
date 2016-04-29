#include <stdio.h>
extern char **environ;
int
main(void)
{
   for (; *environ; environ++)
      puts(*environ);

   return 0;
}
