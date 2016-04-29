#include <dirent.h>
#include <stdio.h>
void
sub(const char *path)
{
   DIR *dir;
   struct dirent *d;

   dir = opendir(path);
   if (!dir) return;

   while (d = readdir(dir))
      if (*d->d_name != '.')
         puts(d->d_name);

   closedir(dir);
}

int
main(int argc, char **argv)
{
   int i;

   if (argc == 1)
      sub(".");
   else
      for (i = 1; i < argc; i++)
         sub(argv[i]);

   return 0;
}
