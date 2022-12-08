#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

char g[110][110];
int lt[110][110], rt[110][110], up[110][110], bottom[110][110];
int n, m;

int solve() {
  for(int i=0; i<n; i++) {
    stack<int> stk;
    for(int j=0; j<m; j++) {
      while(stk.size() && (g[i][stk.top()] - '0') < (g[i][j] - '0')) stk.pop();
      if(stk.size()) lt[i][j] = j - stk.top();
      else lt[i][j] = j;
      stk.push(j);
    }
    while(stk.size()) stk.pop();
    for(int j=m-1; j>=0; j--) {
      while(stk.size() && g[i][stk.top()] - '0' < g[i][j] - '0') stk.pop();
      if(stk.size()) rt[i][j] = stk.top() - j;
      else rt[i][j] = m - j - 1;
      stk.push(j);
    }
  }
  for(int i=0; i<m; i++) {
    stack<int> stk;
    for(int j=0; j<n; j++) {
      while(stk.size() && g[stk.top()][i] - '0' < g[j][i] - '0') stk.pop();
      if(stk.size()) up[j][i] = j - stk.top();
      else up[j][i] = j;
      stk.push(j);
    }
    while(stk.size()) stk.pop();
    for(int j=n-1; j>=0; j--) {
      while(stk.size() && g[stk.top()][i] - '0' < g[j][i] - '0') stk.pop();
      if(stk.size()) bottom[j][i] = stk.top() - j;
      else bottom[j][i] = n - j - 1;
      stk.push(j);
    }
  }
  int res = 0;
  for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
      res = max(res, lt[i][j] * rt[i][j] * up[i][j] * bottom[i][j]);
    }

  return res;
}

int main() {
  {
    int i = 0;
    while(cin >> g[i]) {
      i++;
    }
    n = i, m = strlen(g[0]);
  }
  cout << solve() << endl;
  return 0;
}