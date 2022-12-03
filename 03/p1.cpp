#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

char get_score(char c) {
  if(c >= 'a' && c <= 'z') return c - 'a' + 1;
  else return c - 'A' + 27;
} 

int solve(string &s) {
  unordered_set<char> st;
  int n = s.size(), ans = 0;
  for(int i=0; i<n/2; i++) {
    st.insert(s[i]);
  }
  for(int i=n/2; i<n; i++) {
    if(st.count(s[i])) {
      st.erase(s[i]);
      ans += get_score(s[i]);
    }
  }
  return ans;
}

int main() {
  string s;
  int res = 0;
  while(cin >> s) {
    res += solve(s);
  }  
  cout << res << endl;
  return 0;
}