#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;
typedef long long LL;

LL MOD = 1;
struct Monkey {
  LL count, t_monkey, f_monkey, mod;
  LL op, op_val; // + - * /
  queue<LL> items;
} monkeys[10];

LL isop(char c) {
  string ops = "+-*/";
  for(int i=0; i<4; i++) {
    if(c == ops[i]) return i;
  }
  return -1;
}

vector<LL> get(string &s) {
  vector<LL> res;
  int m = s.size();
  for(int i=0; i<m; i++) {
    if(isdigit(s[i])) {
      int j = i+1;
      while(j < m && isdigit(j)) j++;
      res.push_back(stoll(s.substr(i, j-i+1)));
      i = j;
    } else if(~isop(s[i])) {

      res.push_back(isop(s[i]));
      if(isdigit(s[i+2])) {
        res.push_back(stoll(s.substr(i+2)));
      } else res.push_back(-1);
      break;
    }
  }
  return res;
}

bool check(LL a, LL b) {
  return (b + MOD) % a == 0;
}

int main() {
  // read input
  int n = 0;
  string s[7];
  while(getline(cin, s[0])) {
    for(int i=1; i<=6; i++) getline(cin, s[i]);

    LL count, t_monkey, f_monkey, mod;
    LL op, op_val;
    vector<LL> items;

    f_monkey = get(s[5])[0], t_monkey = get(s[4])[0];
    mod = get(s[3])[0], op = get(s[2])[0], op_val = get(s[2]).back();
    items = get(s[1]); 


    monkeys[n] = {0, t_monkey, f_monkey, mod, op, op_val};
    for(auto c : items) monkeys[n].items.push(c);
    
    MOD *= mod;
    n++;
  }

  // solve problem
  for(int r=0; r<10000; r++) {
    for(int i=0; i<n; i++) {
      auto &monkey = monkeys[i];
      monkey.count += (int)monkey.items.size();
      while(monkey.items.size()) {
        auto item = monkey.items.front();
        monkey.items.pop();
        if(monkey.op == 0) item += (monkey.op_val == -1 ? item : monkey.op_val);
        else if(monkey.op == 1) item -= (monkey.op_val == -1 ? item : monkey.op_val);
        else if(monkey.op == 2) item *= (monkey.op_val == -1 ? item : monkey.op_val);
        else if(monkey.op == 3) item /= (monkey.op_val == -1 ? item : monkey.op_val);

        item = (item%MOD + MOD) % MOD;

        if(check(monkey.mod, item)) {
          monkeys[monkey.t_monkey].items.push(item);
        } else monkeys[monkey.f_monkey].items.push(item);
      }
    }

  }

  vector<LL> res;
  for(int i=0; i<n; i++) res.push_back(monkeys[i].count);
  sort(res.begin(), res.end(), greater<LL>());

  cout << res[0] * res[1] << endl;

  return 0;
}