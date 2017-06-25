#include <stdio.h>
#include <stdlib.h>
char tt[256]; /* translation table */
struct sc {
   const char *s;
   char c;
};

void
init_tt(void)
{
   int i;

   for (i = 0; i < 256; i++)
      tt[i] = i;
}

void
next(struct sc *p)
{
   if (*p->s == '-') {
      p->c++;
      if (p->c == p->s[1])
         p->s++;
      return; }
   p->s++;
   if (*p->s == '-') {
      p->c++;
      if (p->c >= p->s[1])
         exit(2);
      return; }
   p->c = *p->s;
}

void
make_tt(const char *s0, const char *s1)
{
   struct sc sc0 = { s0, *s0 };
   struct sc sc1 = { s1, *s1 };

   if (!*s0 || !*s1) /* refuse empty string */
      return;

   for (;;) {
      tt[sc0.c] = sc1.c;
      next(&sc0);
      if (!sc0.c) break;
      if (!sc1.s[1]) continue;
      next(&sc1);
      if (!sc1.c) break; }
}

int
main(int argc, char **argv)
{
   int c;

   init_tt();

   if (argc == 3)
      make_tt(argv[1], argv[2]);

   while (c = getchar(), c != EOF)
      putchar(tt[c]);
   return 0;
}
