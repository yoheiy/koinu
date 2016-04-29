#include <stdio.h>
#include <string.h>
#define BUFSIZE 0x80
int nr;

void
sub2(char *buf, char *cmd)
{
   int n = 0;

   if (*cmd == '/')
      for (cmd++; *cmd != '/'; cmd++)
         ;
   else if (*cmd >= '1' && *cmd <= '9') do {
      for (; *cmd >= '0' && *cmd <= '9'; cmd++)
         n = n * 10 + *cmd - '0';
      if (*cmd == ',') {
         cmd++;
         if (n > nr) return; }
      else {
         if (n != nr) return; else break; }

      n = 0;
      for (; *cmd >= '0' && *cmd <= '9'; cmd++)
         n = n * 10 + *cmd - '0';
      if (n < nr) return; } while (0);

   switch (*cmd) {
   case 'd':
      buf[0] = '\0';
      break;
   case 'a':
      strcat(buf, cmd + 1);
      strcat(buf, "\n");
      break;
   case 'c':
      strcpy(buf, cmd + 1);
      strcat(buf, "\n");
      break;
   case 'i':
      puts(cmd + 1);
      break;
   case 'p':
      fputs(buf, stdout);
      break;
   case 's':
      buf[0] = '*';
      break;
   }
}

void
sub(char *buf, int c, char **v)
{
   int i;

   for (i = 1; i < c; i++)
      sub2(buf, v[i]);

   fputs(buf, stdout);
}

int
main(int argc, char **argv)
{
   char buf[BUFSIZE];

   while (fgets(buf, sizeof buf, stdin)) {
      nr++;
      sub(buf, argc, argv); }

   return 0;
}
