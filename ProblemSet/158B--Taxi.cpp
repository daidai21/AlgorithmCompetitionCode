// https://codeforces.com/problemset/problem/158/B

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
  int n;
  vector<int> s;
  cin >> n;
  for (int i = 0, tmp; i < n; ++i) {
    cin >> tmp;
    s.push_back(tmp);
  }
  sort(s.begin(), s.end(), [](const int& i1, const int& i2) { return i1 > i2; });
  int taxis = 0;
  unordered_map<int, int> unoccupied_seat = {
    {1, 0},
    {2, 0},
    {3, 0}
  }; // k: seat num, v: taxis num
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 4) {
      ++taxis;
    } else if (s[i] == 3)
      if (unoccupied_seat[3] > 0)
        unoccupied_seat[3]--;
      else {
        unoccupied_seat[1]++;
        ++taxis;
      }
    else if (s[i] == 2)
      if (unoccupied_seat[2] > 0)
        unoccupied_seat[2]--;
      else {
        unoccupied_seat[2]++;
        ++taxis;
      }
    else if (s[i] == 1)
      if (unoccupied_seat[1] > 0)
        unoccupied_seat[1]--;
      else if (unoccupied_seat[2] > 0) {
        unoccupied_seat[2]--;
        unoccupied_seat[1]++;
      } else if (unoccupied_seat[3] > 0) {
        unoccupied_seat[3]--;
        unoccupied_seat[2]++;
      } else {
        unoccupied_seat[3]++;
        ++taxis;
      }
  }

  cout << taxis << endl;
  return 0;
}
