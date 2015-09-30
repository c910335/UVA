#include<stdio.h>
#define avg(x,y) ((double) (*(s + y) - *(s + x)) / ((y) - (x))) 
int t, n, l, i, j;
int s[100005], q[100005];
int *f, *r;
double a, m;
int al, ar;
int main() {
   scanf("%d", &t);
   while (t--) {
      scanf("%d%d\n", &n, &l);
      for (i = 1, s[0] = 0; i <= n; ++i)
         s[i] = getchar() - '0' + s[i - 1];
      a = (double) s[n] / n, al = 0, ar = n;
      f = r = q;
      r--;
      for (i = l; i <= n; ++i) {
         j = i - l;
         while (f < r && avg(*r, j) <= avg(*(r - 1),*r))
            r--;
         *(++r) = j;
         while (f < r && avg(*f, i) <= avg(*(f + 1), i))
            f++;
         m = avg(*f, i);
         if (m > a)
            a = m, al = *f, ar = i;
         else if (m == a && (i - (*f)) < ar - al)
            al = *f, ar = i;
      }
      printf("%d %d\n", al + 1, ar);
   }
}
