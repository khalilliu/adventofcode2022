#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>

#define x first 
#define y second

using namespace std;

typedef pair<int, int> PII;
unordered_map<char, int> mp{{'U', 0}, {'D', 1}, {'L', 2}, {'R', 3}};
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
set<PII> st;
vector<PII> snake;

bool is_touch(PII &h, PII &t) {
  return abs(h.x - t.x) <= 1 && abs(h.y - t.y) <= 1;
}

void move(PII &h, PII &t) {
  if(is_touch(h, t)) return;
  int xx = h.x - t.x, yy = h.y - t.y;
  t.x += (xx ? xx/abs(xx) : 0);
  t.y += (yy ? yy/abs(yy) : 0);
}

int main() {
  for(int i=0; i<10; i++) snake.push_back({0, 0});
  st.insert(snake.back());
  char dir;
  int x;
  while(cin >> dir >> x) {
    while(x--) {
      int d = mp[dir];
      snake[0].x += dx[d], snake[0].y += dy[d];
      for(int i=1; i<10; i++) {
        move(snake[i-1], snake[i]);
        st.insert(snake.back());
      }
    }
  }
  cout << st.size() << endl;
  return 0;
}