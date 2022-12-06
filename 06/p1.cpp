#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
  string s;
  while(cin >> s) {
    int n = s.size();
    for(int i=0; i+3<n; i++) {
      unordered_set<char> S{s[i], s[i+1], s[i+2], s[i+3]};
      if(S.size() == 4) {
        cout <<  i+4 << endl;
        break;
      }
    }
  }
  return 0;
}