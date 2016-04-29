#include <stdio.h>
#define SZ 8
int s[SZ], t, e;

void
push(int n)
{
   if (t == SZ) {
      e = 1;
      return; }

   s[t++] = n;
}

int
pop(void)
{
   return t ? s[--t] : 0;
}

void
show_stack(void)
{
   int i;

   for (i = 0; i < t; i++)
      printf(" %d", s[i]);
   putchar('\n');
}

int
swap(int n)
{
   int c;

   c = pop();
   push(n);

   return c;
}

void
skip_comment(void)
{
   int c;

   while (c = getchar(), c != EOF)
      if (c == '\n') {
         ungetc(c, stdin);
         break; }
}

int
main(void)
{
   int c, n = 0;

   while (c = getchar(), c != EOF) {
      if (e && c == '\n') {
         e = 0;
         fputs("stack overflow\n", stderr); }

      if (c >= '0' && c <= '9') {
         n = n * 10 + (c - '0');
         continue; }

      switch (c) {
      case ',':
         push(n);
         n = 0;
         break;
      case 'p':
         printf("%d\n", n);
         break;
      case 'f':
         show_stack();
         break;

      case '+': n += pop(); break;
      case '-': n -= pop(); break;
      case '*': n *= pop(); break;
      case '/': n /= pop(); break;
      case '%': n %= pop(); break;

      case 'c':
         t = 0;
         break;
      case 'd':
         push(n);
         break;
      case 'r':
         n = swap(n);
         break;
      case 'z':
         push(t);
         break;
      case 'C':
         e = 0;
         break;
      case '#':
         skip_comment();
         break;
      case '\n':
      case ' ':
         break;
      default:
         fputs("?\n", stderr);
      }
   }
   return 0;
}
