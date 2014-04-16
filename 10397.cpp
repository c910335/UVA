#include<stdio.h>
#include<math.h>
#include<algorithm>
using std::sort ;
struct build
{
   int x, y ;
} ;
struct edge
{
   int a, b, n ;
} ;
int cmp(edge x, edge y)
{
   return x.n < y.n ;
}
int p[750] ;

int f(int x)
{
   return x == p[x] ? x : (p[x] = f(p[x])) ;
}
int main()
{
   int n, m, x, y, c, t ;
   double a ;
   build b[750] ;
   edge e[500000] ;
   while(scanf("%d", &n) != EOF)
   {
      for(int i = 0 ; i != n ; i++)
      {
         scanf("%d%d", &((b + i)->x), &((b + i)->y)) ;
         p[i] = i ;
      }
      scanf("%d", &m) ;
      c = 0 ;
      while(m--)
      {
         scanf("%d%d", &x, &y) ;
         x-- ;
         y-- ;
         if(f(x) != f(y))
         {
            c++ ;
            p[f(x)] = f(y) ;
         }
      }
      t = 0 ;
      for(int i = 0 ; i != n-1 ; i++)
         for(int j = i + 1 ; j != n ; j++)
         {
            e[t].a = i ;
            e[t].b = j ;
            e[t].n = (b[i].x - b[j].x) * (b[i].x - b[j].x) + (b[i].y - b[j].y) * (b[i].y - b[j].y) ;
            t++ ;
         }
      sort(e, e + t, cmp) ;
      a = 0 ;
      for(int i = 0 ; c != n - 1 ; i++)
         if(f(e[i].a) != f(e[i].b))
         {
            p[f(e[i].a)] = f(e[i].b) ;
            a += sqrt(e[i].n) ;
            c++ ;
         }
      printf("%.2lf\n", a) ;
   }
}
