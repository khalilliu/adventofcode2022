#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> PII;
vector<PII> ops;
int a[300], b[300];

int main() {
  string s;
  while(getline(cin, s)) {
    if(s[0] == 'n') ops.push_back({1, 0});
    else ops.push_back({2, stoi(s.substr(5))});
  }
  a[1] = 1;
  int n = ops.size();
  for(int i=1, j=0; i<=250; j++) {
    int c = ops[j%n].first, d = ops[j%n].second;
    while(c) {
      a[i+1] = a[i];
      i++, c--;
    }
    a[i] += d;
  }
  for(int j=0; j<6; j++) {
    for(int i=1; i<=40; i++) {
      if(abs(a[i+j*40] - (i-1)) <= 1) b[i+j*40-1] = 1;
    }
  }
  cout << endl;
  for(int i=1; i<=240; i++) {
    cout << (b[i-1] ? '#' : '.') ;
    if(i%40 == 0) cout << endl;
  }
  return 0;
}