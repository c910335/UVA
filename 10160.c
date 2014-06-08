#include <stdio.h>
const long long e = 1 ;
long long g[35], p[35] ;
int n, m, i, a, b ;
int dfs(int a, int c, long long s) {
   if (s == (e << n) - 1)
      return 1 ;
   if (c == i)
      return 0 ;
   int j ;
   for (j = a ; j != n ; ++j) {
      if ((s | p[j]) != (e << n) - 1)
         return 0 ;
      if ((s | g[j]) == s)
         continue ;
      if (dfs(j + 1, c + 1, s | g[j]))
         return 1 ;
   }
   return 0 ;
}
int main() {
   for(;;) {
      scanf("%d%d", &n, &m) ;
      if (! (n || m))
         return 0 ;
      for (i = 0 ; i != n ; ++i)
         g[i] = e << i ;
      for (i = 0 ; i != m ; ++i) {
         scanf("%d%d", &a, &b) ;
         g[a - 1] |= e << (b - 1) ;
         g[b - 1] |= e << (a - 1) ;
      }
      p[n - 1] = g[n - 1] ;
      for (i = n - 2 ; i >= 0 ; --i)
         p[i] = g[i] | p[i + 1] ;
      for (i = 1 ; ; ++i)
         if (dfs(0, 0, 0))
            break ;
      printf("%d\n", i) ;
   }
}
