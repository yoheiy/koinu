#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
void
indent(int n)
{
   int i;

   for (i = 0; i < n; i++) putchar('\t');
}

void
sub(const char *path, int depth)
{
   DIR *dir;
   struct dirent *d;
   struct stat s;

   dir = opendir(path);
   if (!dir) return;
   chdir(path);

   while (d = readdir(dir))
      if (*d->d_name != '.') {
         indent(depth);
         puts(d->d_name);
         lstat(d->d_name, &s);
         if (S_ISDIR(s.st_mode)) sub(d->d_name, depth + 1); }

   chdir("..");
   closedir(dir);
}

int
main(int argc, char **argv)
{
   int i;

   if (argc == 1)
      sub(".", 0);
   else
      for (i = 1; i < argc; i++)
         sub(argv[i], 0);

   return 0;
}
