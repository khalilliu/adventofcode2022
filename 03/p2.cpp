#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

string s[3];
int g[55][3];

int get(char c) {
  if(c >= 'a' && c <= 'z') return c - 'a' + 1;
  else return c - 'A' + 27;
} 

int solve() {
  memset(g, 0, sizeof g);
  int ans = 0;
  for(int i=0; i<3; i++) {
    for(auto c : s[i]) {
      g[get(c)][i]++;
    }
  }
  for(int i=0; i<55; i++) {
    if(g[i][0] && g[i][1] && g[i][2]) ans += i;
  }
  return ans;
}

int main() {
  int res = 0;
  while(cin >> s[0] >> s[1] >> s[2]) {
    res += solve();
  }  
  cout << res << endl;
  return 0;
}