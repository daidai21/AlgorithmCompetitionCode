// https://codeforces.com/problemset/problem/580/C


#include <stdio.h>

#include <iostream>
#include <vector>


using namespace std;


int n, m;
int a[100010];
vector<int> graph[100010];
int visited[100010];
int ret = 0;


int dfs(int cur, int ret) {
  if (a[cur])
    ret++;
  else
    ret = 0;
  if (ret > m || visited[cur])
    return 0;
  visited[cur] = 1;
  int ans = 0;
  if (cur > 1 && graph[cur].size() == 1)
    return 1;
  for (int i = 0; i < graph[cur].size(); ++i)
    ans += dfs(graph[cur][i], ret);
  return ans;
}


int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  for (int i = 0, tmp1, tmp2; i < n - 1; ++i) {
    scanf("%d %d", &tmp1, &tmp2);
    graph[tmp1].push_back(tmp2);
    graph[tmp2].push_back(tmp1);
  }
  cout << dfs(1, 0) << endl;

  return 0;
}
