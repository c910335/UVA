#include<stdio.h>
#include<math.h>
int main()
{
   int n,a[1000],b,c,d,e,f;
   for(;;)
   {
      scanf("%d",&n);
      if(!n)
         return 0;
      b=0,c=0,f=0;
      for(int i=0;i!=n;i++)
      {
         scanf("%d.%d",&a[i],&e);
         a[i]*=100;
         a[i]+=e;
         b+=a[i];
      }
      b=floor((b+.0)/n+0.5);
      for(int i=0;i!=n;i++)
      {
         if(a[i]>b)
            c+=a[i]-b;
         else
            f+=b-a[i];
      }
      d=c<f?c%100:f%100;
      c/=100;
      f/=100;
      printf("$%d.%02d\n",c<f?c:f,d);
   }
}
