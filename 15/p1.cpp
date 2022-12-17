#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <array>
#include <unordered_set>

using namespace std;

vector<array<int, 4>> pts;
int n, res;

void work(int v) {
  vector<array<int, 2>> ans;
  unordered_set<int> st;
  for(int i=0; i<n; i++) {
    int x1 = pts[i][0], y1 = pts[i][1], x2 = pts[i][2], y2 = pts[i][3];
    int dx = abs(x1 - x2) + abs(y1 - y2) - abs(y1 - v);
    if(dx >= 0) {
      ans.push_back({x1 - dx, x1 + dx});
    }
    if(y2 == v) st.insert(x2);
  }
  sort(ans.begin(), ans.end());
  for(auto c : ans) {
    int l = c[0], r = c[1];
    for(int i=l; i<=r; i++) {
      if(!st.count(i)) res++, st.insert(i);
    }
  }
  cout << res << endl;
}
 
int main() {
 string s;
 while(getline(cin, s)) {
  int x1, y1, x2, y2;
  sscanf(s.c_str(), "Sensor at x=%d, y=%d: closest beacon is at x=%d, y=%d", &x1, &y1, &x2, &y2);
  pts.push_back({x1, y1, x2, y2});
 }
 n = pts.size();
 work(2000000);
 return 0;
}