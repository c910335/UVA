#include <stdio.h>
#include <string.h>

int t, n, d, m, s[1000000], c[1000000], l[1000000], i, j;

int main() {
  scanf("%d", &t);
  while (t) {
    scanf("%d%d%d", &n, &m, &d);
    for (i = 0; i != n; ++i) {
      scanf("%d%*c", s + i);
      if (s[i] > m) {
        n--;
        i--;
      }
    }
    memset(c + 1, 127, sizeof(int) * n);
    memset(l, 0, sizeof(int) * (n + 1));
    for (i = 0; i != n; ++i)
      for (j = i; j >= 0; --j)
        if (l[j] >= s[i]) {
          if (c[j + 1] > c[j] || l[j] - s[i] > l[j + 1]) {
            c[j + 1] = c[j];
            l[j + 1] = l[j] - s[i];
          }
        } else if (c[j + 1] > c[j] + 1 || (c[j + 1] == c[j] + 1 && m - s[i] > l[j + 1])) {
          c[j + 1] = c[j] + 1;
          l[j + 1] = m - s[i];
        }
    for (i = n;; --i)
      if (c[i] <= d) {
        printf("%d\n", i);
        break;
      }
    if (--t)
      puts("");
  }
  return 0;
}
