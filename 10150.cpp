#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
struct vo
{
   char s[20];
}v[25144];
struct ro
{
   int q[25144];
   int l[25144];
   int h,t;
}r;
int cmp(vo a,vo b)
{
   int la=strlen(a.s),lb=strlen(b.s);
   return la!=lb?la<lb:strcmp(a.s,b.s)<0;
}
vector<int> m[25144];
int w[25144];
int main()
{
   int n,f,c,s,e,a[25144],b,d=0;
   vo o,p;
   for(n=0;;n++)
   {
      gets(v[n].s);
      if(v[n].s[0]=='\0')
         break;
   }
   sort(v,v+n,cmp);
   for(int i=0;i!=n;i++)
      for(int j=i+1;j!=n;j++)
      {
         if(strlen(v[j].s)!=strlen(v[i].s))
            break;
         f=1,c=0;
         for(int k=0;;k++)
         {
            if(v[i].s[k]=='\0'&&v[j].s[k]=='\0')
               break;
            if(v[i].s[k]!=v[j].s[k])
            {
               if(c==0)
               {
                  c=1;
                  continue;
               }
               else
               {
                  f=0;
                  break;
               }
            }
         }
         if(f)
         {
            m[i].push_back(j);
            m[j].push_back(i);
         }
      }
   while(scanf("%s%s",o.s,p.s)!=EOF)
   {
      if(d)
         puts("");
      else
         d=1;
      s=lower_bound(v,v+n,o,cmp)-v;
      e=lower_bound(v,v+n,p,cmp)-v;
      r.q[0]=s;
      memset(w,0,sizeof(w));
      w[r.q[0]]=1;
      r.h=0;
      r.t=1;
      f=1;
      while(r.q[r.h]!=e)
      {
         for(int i=0;i<m[r.q[r.h]].size();i++)
            if(!w[m[r.q[r.h]][i]])
            {
               r.q[r.t]=m[r.q[r.h]][i];
               w[m[r.q[r.h]][i]]=1;
               r.l[r.t]=r.h;
               r.t++;
            }
         r.h++;
         if(r.h==r.t)
         {
            f=0;
            break;
         }
      }
      if(f)
      {
         b=0;
         for(int i=r.h;;b++,i=r.l[i])
         {
            a[b]=r.q[i];
            if(i==0)
               break;
         }
         for(int i=b;i>0;i--)
            printf("%s\n",v[a[i]].s);
         printf("%s\n",v[a[0]].s);
      }
      else
         puts("No solution.");
   }
   return 0;
}
