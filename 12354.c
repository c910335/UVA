#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct edge
{
   int m, d ;
   struct edge *n ;
} edge ;
typedef struct
{
   int a, n ;
} state ;
edge *g[20000], *t, *d ;
state ts ;
int m, n, v[20000], a, b, i, j, k, r ;
void add(int x, int y, int z)
{
   t = (edge*) malloc(sizeof(edge)) ;
   t->m = y ;
   t->d = z ;
   t->n = g[x] ;
   g[x] = t ;
}
void clear(int p)
{
   memset(v, 0, p * sizeof(int)) ;
   for(k = 0 ; k != p ; k++)
   {
      t = g[k] ;
      g[k] = NULL ;
      while(t != NULL)
      {
         d = t->n ;
         free(t) ;
         t = d ;
      }
   }
}
state dfs(int x)
{
   edge *e = g[x] ;
   state rs ;
   rs.a = 0 ;
   rs.n = 0 ;
   while(e != NULL)
   {
      if(! v[e->m])
      {
         v[e->m] = 1 ;
         ts = dfs(e->m) ;
         rs.a += ts.a ;
         if(e->d && ts.n <= 0)
         {
            rs.n++ ;
            if(rs.n > 0)
               rs.a++ ;
         }
         else if((! e->d) && ts.n >= 0)
         {
            rs.n-- ;
            if(rs.n < 0)
               rs.a++ ;
         }
         else if(ts.n > 0)
         {
            if(rs.n < 0)
               rs.a -= (-rs.n) < ts.n ? (-rs.n) : ts.n ;
            rs.n += ts.n ;
         }
         else
         {
            if(rs.n > 0)
               rs.a -= (-ts.n) < rs.n ? (-ts.n) : rs.n ;
            rs.n += ts.n ;
         }
      }
      e = e->n ;
   }
   return rs ;
}
int main()
{
   scanf("%d", &m) ;
   for(i = 0 ; i != m ; i++)
   {
      scanf("%d", &n) ;
      for(j = 0 ; j != n - 1 ; j++)
      {
         scanf("%d%d", &a, &b) ;
         add(a, b, 1) ;
         add(b, a, 0) ;
      }
      v[0] = 1 ;
      printf("Case %d: %d\n", i + 1, dfs(0).a) ;
      if(i != m - 1)
         clear(n) ;
   }
}
