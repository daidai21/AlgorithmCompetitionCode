// https://codeforces.com/problemset/problem/4/A

#include <iostream>

using namespace std;

int main() {
  int w;
  cin >> w;
  for (int i = 2; i < w; i += 2)
    if ((w - i) % 2 == 0) {
      cout << "YES" << endl;
        return 0;
    }
  cout << "NO" << endl;

  return 0;
}
