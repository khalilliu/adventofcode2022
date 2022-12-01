#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int tot = 0;
  string s;
  vector<int> nums;
  while(getline(cin, s)) {
    if(s.size()) tot += stoi(s);
    else nums.push_back(tot), tot = 0;
  }
  nums.push_back(tot);
  sort(nums.begin(), nums.end(), greater<int>());
  cout << nums[0] + nums[1] + nums[2] << endl;
  return 0;
}