#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
int
ckstat(char op, char *f)
{
   struct stat s;

   if (stat(f, &s) == -1) return 1;

   switch (op) {
   case 'e': return 0;
   case 'd': return S_ISDIR(s.st_mode) ? 0 : 1;
   case 'f': return S_ISREG(s.st_mode) ? 0 : 1;
   case 's': return S_ISREG(s.st_mode) && s.st_size > 0 ? 0 : 1;
   }
   return 2;
}

int
sub1(char *o, char *a)
{
   char op = *++o;
   switch (op) {
   case 'n': return *a ? 0 : 1;
   case 'z': return *a ? 1 : 0;
   }
   return ckstat(op, a);
}

int
sub2(char *o, char *a0, char *a1)
{
   return 2;
}

int
main(int argc, char **argv)
{
   if (argc == 1) return 1;
   if (argc == 2) return *argv[1] ? 0 : 1;
   if (argc == 3) return *argv[1] == '-' ? sub1(argv[1], argv[2]) : 2;
   if (argc == 4) return *argv[2] == '-' ? sub2(argv[2], argv[1], argv[3]) : 2;

   return 2;
}
