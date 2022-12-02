#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<char, char> PII;

int score[3] = {1, 2, 3};

int main() {
  vector<PII> g;
  char a, b;
  while(cin >> a >> b) {
    g.push_back({a, b});
  }
  int n = g.size(), res = 0;
  for(auto p : g) {
    int a = p.first - 'A';
    char b = p.second;
    if(b == 'X') {
      res += score[(a-1+3)%3];
    } else if(b == 'Y') {
      res += 3 + score[a];
    } else if(b == 'Z') {
      res += 6 + score[(a + 1)%3];
    }
  }
  cout << res << endl;
  return 0;
}