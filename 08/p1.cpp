#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

char g[110][110];
int lt[110][110], rt[110][110], up[110][110], bottom[110][110];
int n, m;

int solve() {
  for(int i=0; i<n; i++) {
    for(int j=0, v=-1e9; j<m; j++) {
      if(g[i][j] - '0' > v) lt[i][j] = 1;
      v = max(v, g[i][j] - '0');
    }
    for(int j=m-1, v=-1e9; j>=0; j--) {
      if(g[i][j] - '0' > v) rt[i][j] = 1;
      v = max(v, g[i][j] - '0');
    }
  }
  for(int i=0; i<m; i++) {
    for(int j=0, v=-1e9; j<n; j++) {
      if(g[j][i] - '0' > v) up[j][i] = 1;
      v = max(v, g[j][i] - '0');
    }
    for(int j=n-1, v=-1e9; j>=0; j--) {
      if(g[j][i] - '0' > v) bottom[j][i] = 1;
      v = max(v, g[j][i] - '0');
    }
  }
  int res = 0;
  for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
    res += (lt[i][j] | rt[i][j] | up[i][j] | bottom[i][j]);
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