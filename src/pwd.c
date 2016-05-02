#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

ino_t
cwd_inode(void)
{
   struct stat s;

   lstat(".", &s);
   return s.st_ino;
}

char *
d_name(ino_t inode)
{
   DIR *dir;
   struct dirent *d;
   char *name;

   dir = opendir("."); /* parent */
   if (!dir) {
      perror("pwd: opendir");
      exit(1); }

   while (d = readdir(dir))
      if (d->d_ino == inode) break;

   if (!d) {
      fputs("pwd: file not found\n", stderr);
      exit(1); }

   name = strdup(d->d_name);
   closedir(dir);

   return name;
}

void
sub(ino_t ino_child)
{
   ino_t ino_parent;
   char *name;

   if (chdir("..") != 0) { perror("pwd: chdir"); return; }

   ino_parent = cwd_inode();
   if (ino_child == ino_parent) return; /* root dir */

   name = d_name(ino_child);
   sub(ino_parent);
   putchar('/');
   fputs(name, stdout);
   free(name);
}

int
main(void)
{
   sub(cwd_inode());
   putchar('\n');

   return 0;
}
