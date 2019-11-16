// https://codeforces.com/problemset/problem/25/A


#include <stdio.h>


int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);

  int even = 0;
  for (int num : arr)
    even += num & 0x1;
  bool diff_is_even = even < n - even;
  for (int i = 0; i < n; ++i)
    if (arr[i] % 2 == diff_is_even) {
      printf("%d\n", i + 1);
      break;
    }

  return 0;
}

