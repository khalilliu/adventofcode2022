#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

vector<string> crates;
vector<array<int, 3>> ops;

int main() {
  string s;
  bool is_op = false;
  while(getline(cin, s)) {
    if(s.empty()) is_op = true;
    else {
      if(!is_op) crates.push_back(s);
      else {
        int a, b, c;
        sscanf(s.c_str(), "move %d from %d to %d", &a, &b, &c);
        b--, c--;
        ops.push_back({a, b, c});
      }
    }
  }

  for(auto op : ops) {
    int a = op[0], b = op[1], c = op[2];
    int n = crates[b].size();
    string t = crates[b].substr(n-a);
    crates[c] += t;
    crates[b] = crates[b].substr(0, n-a);
  }
  string res;
  for(auto c : crates) {
    if(!c.empty()) res += c.back();
  }
  cout << res << endl;
  return 0;
}