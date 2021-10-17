#include <iostream>
#include <stack>

void sortStackByStack(std::stack<int>& stk1) {
  std::stack<int> stk2;
  while (!stk1.empty()) {
    int cur = stk1.top();
    stk1.pop();
    while (!stk2.empty() && cur < stk2.top()) {
      int tmp = stk2.top();
      stk1.push(tmp);
      stk2.pop();
    }
    stk2.push(cur);
  }
  while (!stk2.empty()) {
    stk1.push(stk2.top());
    stk2.pop();
  }
}


int main() {
  std::stack<int> stk;
  stk.push(5);
  stk.push(8);
  stk.push(4);
  stk.push(3);
  stk.push(6);
  sortStackByStack(stk);
  for (std::stack<int> tmp = stk; !tmp.empty(); tmp.pop()) {
    std::cout << tmp.top() << " "; 
  }
  std::cout << std::endl;
}
