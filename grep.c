#include <stdio.h>
#include <string.h>
#define MAXLEN 80

int
main(int argc, char **argv)
{
   char buf[MAXLEN + 1];

   if (argc != 2) return 2;

   while (fgets(buf, sizeof buf, stdin))
      if (strstr(buf, argv[1]))
         fputs(buf, stdout);

   return 0;
}
