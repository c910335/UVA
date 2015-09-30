#include <stdio.h>
#include <math.h>
int main()
{
   int n, a[1000], b, c, d, e, f, i;
   for (;;)
   {
      scanf("%d", &n);
      if (!n)
         return 0;
      b = 0, d = 0, e = 0;
      for (i=0; i!=n; i++)
      {
         scanf("%d.%d", &a[i], &c);
         a[i] *= 100;
         a[i] += c;
         b += a[i];
      }
      c = ceil((b + .0) / n);
      b = floor((b + .0) / n);
      for (i = 0; i != n; i++)
      {
         if (a[i] > c)
            d += a[i] - c;
         else if (a[i] < b)
            e += b - a[i];
      }
      f = d > e ? d % 100 : e % 100;
      d /= 100;
      e /= 100;
      printf("$%d.%02d\n", d > e ? d : e, f);
   }
}
