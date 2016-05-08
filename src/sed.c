#include <stdio.h>
#include <string.h>
#define BUFSIZE 0x80
int nr;

int
num_read(char *s)
{
   int n = 0;

   for (; *s >= '0' && *s <= '9'; s++)
      n = n * 10 + (*s - '0');

   return n;
}

char *
num_skip(char *s)
{
   for (; *s >= '0' && *s <= '9'; s++) ;

   return s;
}

void
sub2(char *buf, char *cmd)
{
   if (*cmd == '/')
      for (cmd++; *cmd != '/'; cmd++)
         ;
   else if (*cmd >= '1' && *cmd <= '9') {
      int n0, n1;
      n0 = num_read(cmd);
      cmd = num_skip(cmd);

      if (*cmd == ',') {
         if (*++cmd == '$') {
            n1 = 0;
            cmd++; }
         else {
            n1 = num_read(cmd);
            cmd = num_skip(cmd); } }
      else
         n1 = n0;

      if (n0 > nr) return;
      if (n1 < nr && n1) return; }

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
