#include<stdio.h>
#include<list>
using std::list ;
int v[31623] ;
list<int> p ;
int d(int x)
{
   int t, r = 1 ;
   for(list<int>::iterator i = p.begin() ; i != p.end() && x != 1 ; ++i)
   {
      t = 0 ;
      while(x % *i == 0)
      {
         x /= *i ;
         t++ ;
      }
      r *= (t + 1) ;
   }
   return r ;
}
int main()
{
   for(int i = 2 ; i != 31623 ; i++)
   {
      if(v[i])
         continue ;
      p.push_back(i) ;
      for(int j = 2 ; i * j < 31623 ; j++)
         v[i * j] = 1 ;
   }

   int n, l, u, a, b, t ;

   scanf("%d", &n) ;
   while(n--)
   {
      scanf("%d%d", &l, &u) ;

      a = l ;
      b = d(l) ;
      for(int i = l + 1 ; i <= u ; i++)
      {
         t = d(i) ;
         if(t > b)
         {
            a = i ;
            b = t ;
         }
      }

      printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, u, a, b) ;
   }
}
