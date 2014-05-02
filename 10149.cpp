#include<stdio.h>
#include<string.h>
#include<algorithm>
struct out
{
   int s[13],b,a;
};
int d[13][5];
int m[13][13];
out dp[8192];
int cal(int n,int type)
{
   int re=0,f=0,t[7]={0};
   switch (type)
   {
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
         for(int i=0;i!=5;i++)
            re+=(d[n][i]==type)*type;
         return re;
         break;
      case 9:
         if(d[n][0]==d[n][3]||d[n][1]==d[n][4])
            f=1;
         if(!f)
            return 0;
         for(int i=0;i!=5;i++)
            re+=d[n][i];
         return re;
         break;
      case 8:
         if(d[n][0]==d[n][2]||d[n][1]==d[n][3]||d[n][2]==d[n][4])
            f=1;
         if(!f)
            return 0;
         for(int i=0;i!=5;i++)
            re+=d[n][i];
         return re;
         break;
      case 7:
         for(int i=0;i!=5;i++)
            re+=d[n][i];
         return re;
         break;
      case 10:
         if(d[n][0]==d[n][4])
            return 50;
         return 0;
         break;
      case 11:
         for(int i=0;i!=5;i++)
            t[d[n][i]]=1;
         for(int i=1;i!=4;i++)
            if(t[i]&&t[i+1]&&t[i+2]&&t[i+3])
            {
               f=1;
               break;
            }
         if(f)
            return 25;
         return 0;
         break;
      case 12:
         f=1;
         for(int i=1;i!=5;i++)
            if(d[n][i-1]+1!=d[n][i])
            {
               f=0;
               break;
            }
         if(f)
            return 35;
         return 0;
         break;
      case 13:
         if(d[n][0]==d[n][2]&&d[n][3]==d[n][4])
            f=1;
         if(d[n][0]==d[n][1]&&d[n][2]==d[n][4])
            f=1;
         if(f)
            return 40;
         return 0;
         break;
   }
}
int co(int x)
{
   int re=0;
   for(int i=0;i!=13;i++)
      re+=(x>>i)&1;
   return re;
}
int main()
{
   while(scanf("%d%d%d%d%d",&d[0][0],&d[0][1],&d[0][2],&d[0][3],&d[0][4])!=EOF)
   {
      memset(dp,-1,sizeof(dp));
      for(int i=1;i!=13;i++)
      {
         scanf("%d%d%d%d%d",&d[i][0],&d[i][1],&d[i][2],&d[i][3],&d[i][4]);
         std::sort(d[i],d[i]+5);
      }
      for(int i=0;i!=13;i++)
         for(int j=0;j!=13;j++)
            m[i][j]=cal(i,j+1);
      out ma,t;
      int q;
      for(int i=0;i!=13;i++)
         for(int j=1;j!=8192;j++)
            if(co(j)==i+1)
            {
               memset(&ma,0,sizeof(ma));
               ma.a=-1;
               if(!i)
               {
                  for(int k=0;k!=13;k++)
                     if((j>>k)&1)
                     {
                        ma.s[0]=m[k][0];
                        ma.a=m[k][0];
                        break;
                     }
               }
               else
                  for(int k=0;k!=13;k++)
                     if((j>>k)&1)
                     {
                        t=dp[j-(1<<k)];
                        t.s[i]=m[k][i];
                        t.a+=m[k][i];
                        if(i<6)
                        {
                           q=0;
                           for(int l=0;l!=6;l++)
                              q+=t.s[l];
                           if(q>=63)
                           {
                              t.a+=t.b?0:35;
                              t.b=35;
                           }
                        }
                        if(t.a>=ma.a)
                           ma=t;
                     }
               dp[j]=ma;
            }
      out a=dp[8191];
      for(int i=0;i!=13;i++)
         printf("%d ",a.s[i]);
      printf("%d %d\n",a.b,a.a);
   }
   return 0;
}
