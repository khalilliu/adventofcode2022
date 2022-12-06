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
    for(int i=0; i+13<n; i++) {
      unordered_set<char> S;
      for(int j=i; j<i+14; j++) {
        S.insert(s[j]);
      }
      if(S.size() == 14) {
        cout <<  i+14 << endl;
        break;
      }
    }
  }
  return 0;
}