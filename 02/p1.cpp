#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<char, char> PII;

int score[3] = {1, 2, 3};

int calc(char a, char b) {
  int c1 = a - 'A', c2 = b - 'X';
  int res = score[c2];
  if(c1 == c2) {
    res += 3;
  } else if((c2-1+3)%3 == c1) {
    res += 6;
  }
  return res;
}

int main() {
  vector<PII> g;
  char a, b;
  while(cin >> a >> b) {
    g.push_back({a, b});
  }
  int n = g.size(), res = 0;
  for(auto p : g) {
    res += calc(p.first, p.second);
  }
  cout << res << endl;
  return 0;
}