#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;
typedef pair<int, int> PII;
vector<vector<PII>> input;
const int N = 1010;
int dx[3] = {1, 1, 1}, dy[3] = {0, -1, 1};
int g[N][N];
int maxX;
PII S;

void read_input() {
  string s;
  while(getline(cin, s)) {
    vector<PII> path;
    string pt; 
    stringstream ss(s);
    while(getline(ss, pt, ' ')) {
      if(isdigit(pt[0])) {
        auto t = pt.find(',');
        int y = stoi(pt.substr(0, t)), x = stoi(pt.substr(t+1));
        path.emplace_back(x, y);
      }
    }
    input.push_back(path);
  }
}

void fill_dot() {
  for(auto pts : input) {
    int n = pts.size();
    for(int i=1; i<n; i++) {
      int x1 = pts[i-1].first, y1 = pts[i-1].second;
      int x2 = pts[i].first, y2 = pts[i].second;
      maxX = max({maxX, x1, x2});
      if(x1 > x2 || y1 > y2) swap(x1, x2), swap(y1, y2);
      for(int i=x1; i<=x2; i++) {
        for(int j=y1; j<=y2; j++) {
          g[i][j] = 1;
        }
      }
    }
  }
  for(int i=0; i<N; i++) g[maxX+2][i] = 1;
}

void solve() {
  int res = 0;
  while(!g[0][500]) {
    int x = 0, y = 500;
    while(true) {
      int px = x, py = y;
      for(int i=0; i<3; i++) {
        int a = x + dx[i], b = y + dy[i]; 
        if(!g[a][b]) {
          x = a, y = b;
          break;
        }
      }

      if(px == x && py == y) {
        g[x][y] = 2;
        break;
      }
    }
  }
  for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
    res += g[i][j] == 2;
  }
  cout << res << endl;
}

int main() {
  {
    read_input();
    fill_dot();
    S = {0, 500};
  }
  solve();
  return 0;
}