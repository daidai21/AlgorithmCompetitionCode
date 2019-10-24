// https://codeforces.com/problemset/problem/545/D

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> queue_;
  for (int i = 0, tmp; i < n; ++i) {
    cin >> tmp;
    queue_.push_back(tmp);
  }
  sort(queue_.begin(), queue_.end());
  int satisfied_people_num = 0;
  for (int i = 0, sum_time = 0; i < n; ++i)
    if (queue_[i] >= sum_time) {
      ++satisfied_people_num;
      sum_time += queue_[i];
    }
  cout << satisfied_people_num << endl;

  return 0;
}
