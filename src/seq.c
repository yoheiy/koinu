#include <stdio.h>
#include <stdlib.h>
int
main(int argc, char **argv)
{
   int i, inc = 1, end;

   switch (argc - 1) {
   case 1:
      end = atoi(argv[1]), i = 1;
      break;
   case 2:
      end = atoi(argv[2]), i = atoi(argv[1]);
      break;
   case 3:
      end = atoi(argv[3]), i = atoi(argv[1]), inc = atoi(argv[2]);
      break;
   default:
      return 2; }

   for (; i <= end; i += inc)
      printf("%d\n", i);

   return 0;
}
