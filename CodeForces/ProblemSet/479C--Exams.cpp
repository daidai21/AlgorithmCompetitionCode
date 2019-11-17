// https://codeforces.com/problemset/problem/479/C


#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> vec(n);
  for (int i = 0; i < n; ++i) {
    cin >> vec[i].first >> vec[i].second;
  }

  sort(vec.begin(), vec.end());
  int best = -1;
  for (int i = 0; i < n; ++i)
    if (best <= vec[i].second)
      best = vec[i].second;
    else
      best = vec[i].first;
  cout << best << endl;

  return 0;
}

