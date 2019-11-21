// https://codeforces.com/problemset/problem/27/A


#include <stdio.h>

#include <algorithm>


using namespace std;


int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  sort(a, a + n);
  int res = 1;
  bool is_find = false;
  for (int i = 0; i < n; ++i) {
    if (a[i] == res)
      res++;
    else {
      printf("%d\n", res);
      is_find = true;
      break;
    }
  }
  if (!is_find)
    printf("%d\n", res);

  return 0;
}


