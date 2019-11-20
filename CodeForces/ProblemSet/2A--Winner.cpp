// https://codeforces.com/problemset/problem/2/A


#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;


string name[1000];
int score[1000];
map<string, int> map1, map2;


int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> name[i] >> score[i];
    map1[name[i]] += score[i];
  }
  int max_score = 0;
  for (auto it = map1.begin(); it != map1.end(); ++it)
    max_score = max(max_score, it->second);
  for (int i = 0; i < n; ++i) {
    map2[name[i]] += score[i];
    if (map1[name[i]] >= max_score && map2[name[i]] >= max_score) {
      cout << name[i] << endl;
      break;
    }
  }

  return 0;
}

