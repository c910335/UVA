#include<stdio.h>
#include<stdlib.h>
#include<queue>
using std::queue ;
struct edge
{
   int to ;
   int v ;
   edge *next ;
};
edge *f[100], *t, *u;
int n, r, a, b, c, q, d[100][2], v[100] ;
queue<int> z ;
void add(int a, int b, int c)
{
   t = (edge*) malloc(sizeof(edge)) ;
   t->to = b ;
   t->v = c ;
   t->next = f[a] ;
   f[a] = t ;
}
void clear(int a)
{
   t = f[a] ;
   f[a] = NULL ;
   while(t)
   {
      u = t->next ;
      free(t) ;
      t = u ;
   }
}
int main()
{
   for(int time = 1 ; scanf("%d", &n) != EOF ; time++)
   {
      for(int i = 0 ; i != n ; i++)
         clear(i) ;
      scanf("%d", &r) ;
      while(r--)
      {
         scanf("%d%d%d", &a, &b, &c) ;
         add(a, b, c) ;
         add(b, a, c) ;
      }
      scanf("%d", &q) ;
      printf("Set #%d\n", time) ;
      while(q--)
      {
         scanf("%d%d", &a, &b) ;
         for(int i = 0 ; i != n ; i++)
         {
            d[i][0] = 100000 ;
            d[i][1] = 100001 ;
            v[i] = 0 ;
         }
         d[a][0] = 0 ;
         d[a][1] = 100000 ;
         z.push(a) ;
         v[a] = 1 ;
         while(! z.empty())
         {
            c = z.front() ;
            z.pop() ;
            v[c] = 0 ;
            t = f[c] ;
            while(t)
            {
               if(d[c][0] + t->v < d[t->to][0])
               {
                  d[t->to][1] = d[t->to][0] ;
                  d[t->to][0] = d[c][0] + t->v ;
                  if(! v[t->to])
                  {
                     z.push(t->to) ;
                     v[t->to] = 1 ;
                  }
               }
               if(d[c][0] + t->v < d[t->to][1] && d[c][0] + t->v > d[t->to][0])
               {
                  d[t->to][1] = d[c][0] + t->v ;
                  if(! v[t->to])
                  {
                     z.push(t->to) ;
                     v[t->to] = 1 ;
                  }
               }
               if(d[c][1] + t->v < d[t->to][1])
               {
                  d[t->to][1] = d[c][1] + t->v ;
                  if(! v[t->to])
                  {
                     z.push(t->to) ;
                     v[t->to] = 1 ;
                  }
               }
               t = t->next ;
            }
         }
         if(d[b][1] > 50000)
            puts("?") ;
         else
            printf("%d\n", d[b][1]) ;
      }
   }
}
