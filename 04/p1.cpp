#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int res = 0;
  string s;
  while(getline(cin, s)) {
    int l1, r1, l2, r2;
    sscanf(s.c_str(), "%d-%d,%d-%d", &l1, &r1, &l2, &r2);
    if(l1 <= l2 && r1 >= r2 || l2 <= l1 && r2 >= r1) {
      res ++;
    }
  } 
  cout << res << endl;
  return 0;
}