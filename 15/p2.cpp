#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <array>
#include <unordered_set>

using namespace std;

vector<array<int, 4>> pts;
int n;

bool check(int x, vector<array<int, 2>>& segs) {
  for(auto seg: segs) {
    int l = seg[0], r = seg[1];
    if(x >= l && x <= r) return true;
  }
  return false;
}

void work(int v) {
  vector<array<int, 2>> segs, ans;
  unordered_set<int> S;
  for(int i=0; i<n; i++) {
    int x1 = pts[i][0], y1 = pts[i][1], x2 = pts[i][2], y2 = pts[i][3];
    int dx = abs(x1 - x2) + abs(y1 - y2) - abs(y1 - v);
    if(dx >= 0) {
      segs.push_back({x1 - dx, x1 + dx});
    }
    if(y2 == v) segs.push_back({x2, x2});
  }
  
  sort(segs.begin(), segs.end());

  int st = -2e9, ed = -2e9;
  for (auto seg : segs) {
      if (ed < seg[0])
      {
          if (st != -2e9) ans.push_back({st, ed});
          st = seg[0], ed = seg[1];
      }
      else ed = max(ed, seg[1]);
  }

  if (st != -2e9) ans.push_back({st, ed});

  int x = 0;
  for(auto seg: ans) {
    int l = seg[0], r = seg[1];
    if(x >= l && x <= r) x = r + 1;
    else break;
  }

  if(x <= 4000000) {
    cout << x << ' ' << v << endl;
    cout << (long long)x * 4000000 + v << endl;
  }
}
 
int main() {
 string s;
 while(getline(cin, s)) {
  int x1, y1, x2, y2;
  sscanf(s.c_str(), "Sensor at x=%d, y=%d: closest beacon is at x=%d, y=%d", &x1, &y1, &x2, &y2);
  pts.push_back({x1, y1, x2, y2});
 }
 n = pts.size();
 for(int i=0; i<=4000000; i++) {
  work(i);
 }
 
 return 0;
}