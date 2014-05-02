#include<cstdio>
#include<cstring>
int main()
{
   char a[110],b[110];
   int d[10][4]={{0},{1},{6,2,4,8},{1,3,9,7},{6,4},{5},{6},{1,7,9,3},{6,8,4,2},{1,9}};
   int la,lb,e,f;
   for(;;)
   {
      scanf("%s%s",a,b);
      la=strlen(a);
      lb=strlen(b);
      if(a[0]=='0'&&b[0]=='0'&&la==1&&lb==1)
         return 0 ;
      if(b[0]=='0'&&lb==1)
      {
         puts("1");
         continue;
      }
      e=a[la-1]-'0';
      switch(e)
      {
      case 0:
      case 1:
      case 5:
      case 6:
         printf("%d\n",e);
         break;
      case 2:
      case 3:
      case 7:
      case 8:
         f=((lb>1?(b[lb-2]-'0')*10:0)+(b[lb-1]-'0'))%4;
         printf("%d\n",d[e][f]);
         break;
      case 4:
      case 9:
         f=(b[lb-1]-'0')&1;
         printf("%d\n",d[e][f]);
         break;
      }
   }
}
