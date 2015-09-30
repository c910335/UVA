#include <cstdio>
#include <cmath>
#include <unordered_map>
using std::unordered_map;
long long a, b, m, l;
void exgcd(long long x, long long y, long long &g, long long &a, long long &b) {
   if (y == 0)
      g = x, a = 1, b = 0;
   else
      exgcd(y, x % y, g, b, a), b -= (x/y) * a;
}
long long inv(long long x,long long y) {
   long long g = 1, a, b;
   exgcd(x, y, g, a, b);
   return (a % y + y) % y;
}
long long log(long long a, long long b, long long m) {
   unordered_map<long long, long long> x;
   long long n = floor(sqrt(m));
   long long t = 1;
   for (long long i = 0; i != n; ++i) {
      if (t == b)
         return i;
      if (! x.count(t))
         x[t] = i;
      t = t * a % m;
   }
   long long f = inv(t, m);
   for (long long i = 0; i != n + 1; ++i) {
      if (x.count(b))
         return i * n + x[b];
      b = b * f % m;
   }
   return -1;
}
int main() {
   while(scanf("%lld%lld%lld", &m, &a, &b) != EOF) {
      l = log(a, b, m);
      if (l == -1)
         puts("no solution");
      else
         printf("%lld\n", l);
   }
   return 0;
}
