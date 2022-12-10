#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> PII;
vector<PII> ops;
int a[300];
int main() {
  string s;
  while(getline(cin, s)) {
    if(s[0] == 'n') ops.push_back({1, 0});
    else ops.push_back({2, stoi(s.substr(5))});
  }
  // for(auto &p : ops) cout << p.second << endl;
  a[1] = 1;
  int n = ops.size();
  for(int i=1, j=0; i<=220; j++) {
    int c = ops[j%n].first, d = ops[j%n].second;
    while(c) {
      a[i+1] = a[i];
      i++, c--;
    }
    a[i] += d;
  }
  int res = 20 * a[20] + 60 * a[60] + 100 * a[100] + 140 * a[140] + 180 * a[180] + 220 * a[220];
  cout << res << endl;
  return 0;
}