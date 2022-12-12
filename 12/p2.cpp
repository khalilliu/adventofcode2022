#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;
typedef pair<int, PII> PPI;
const int N = 200;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
string g[N];
int dist[N][N];
PII S, E;
int n, m;

int main() {
  {
    while(cin >> g[n]) n++;
    m = g[0].size();
  }

  
  memset(dist, 0x3f, sizeof dist);
  priority_queue<PPI, vector<PPI>, greater<PPI>> heap;

  for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
    if(g[i][j] == 'S'){
       g[i][j] = 'a'; dist[i][j] = 0;
       heap.push({0, {i, j}});
    } else if(g[i][j] == 'a') {
      dist[i][j] = 0;
      heap.push({0, {i, j}});
    } else if(g[i][j] == 'E') E = {i, j}, g[i][j] = 'z';
  }

  while(heap.size()) {
    auto t = heap.top(); heap.pop();
    auto pt = t.y;

    for(int i=0; i<4; i++) {
      int x = pt.x + dx[i], y = pt.y + dy[i];
      if(x < 0 || x >= n || y < 0 || y >= m) continue;
      if(g[x][y] - g[pt.x][pt.y] <= 1) {
        if(dist[x][y] > dist[pt.x][pt.y] + 1) {
          dist[x][y] = dist[pt.x][pt.y] + 1;
          heap.push({dist[x][y], {x, y}});
        }
      }
    }
  }

  cout << dist[E.x][E.y] << endl;
  return 0;
}