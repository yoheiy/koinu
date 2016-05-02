#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
struct dirname {
   char *name;
   struct dirname *parent; };

void
print_dirpart(struct dirname *d)
{
   if (!d || !d->name) return;

   if (d->parent) print_dirpart(d->parent);

   fputs(d->name, stdout);
   putchar('/');
}

void
sub(char *path, struct dirname *dn0)
{
   DIR *dir;
   struct dirent *d;
   struct dirname dn1;
   struct stat s;

   dir = opendir(path);
   if (!dir) return;
   if (chdir(path) != 0) {
      perror("chdir");
      goto out; }

   while (d = readdir(dir))
      if (*d->d_name != '.') {
         print_dirpart(dn0);
         puts(d->d_name);

         if (lstat(d->d_name, &s) != 0)
            perror("lstat");
         else if (S_ISDIR(s.st_mode)) {
            dn1.name = d->d_name;
            dn1.parent = dn0;
            sub(d->d_name, &dn1); } }

   chdir("..");
out:
   closedir(dir);
}

void
sub0(char *path)
{
   struct dirname d;

   d.parent = NULL;
   d.name = path;
   sub(path, &d);
}

int
main(int argc, char **argv)
{
   int i;

   if (argc == 1)
      sub0(".");
   else
      for (i = 1; i < argc; i++)
         sub0(argv[i]);

   return 0;
}
