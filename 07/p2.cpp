#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>


using namespace std;


struct Node {
  string name;
  int size;
  bool isDir;
  Node *parent;
  vector<Node*> children;
  Node(string _name, int _size, bool _isDir, Node *_parent) {
    this->name = _name;
    this->size = _size;
    this->isDir = _isDir;
    this->parent = _parent;
  };
};

vector<int> nums;

void print(Node *cur, string level) {
  if(!cur->isDir) {
    cout << level << " - " << cur->name;
    printf("(file, size=%d)\n",  cur->size);
    return;
  }
  cout << level << " - " << cur->name << " (dir)\n";
  for(auto c : cur->children) {
    print(c, level + "   ");
  }
}

int dfs(Node *cur) {
  if(!(cur->isDir)) {
    return cur->size;
  }
  int ans = 0;
  for(auto c : cur->children) {
    ans += dfs(c);
  }

  nums.push_back(ans);
  return ans;
}

int main() {
  auto root = new Node("/", 0, true, NULL);
  auto cur = root;
  string s;
  while(getline(cin, s)) {
    // cout << "cur: " << cur->name << endl;
    if(s[0] == '$') {
      if(s[2] == 'c') {
        // run cd cmd
        string ct = s.substr(5);
        if(ct == "/") cur = root;
        else if(ct == "..") {
          cur = cur->parent;
        } else {
          for(auto c : cur->children) {
            if(c->name == ct) {
              cur = c;
              break;
            }
          }
        }
      } else if(s[2] == 'l') {
        //run ls cmd
      } 
    } else {
        stringstream ssin(s);
        string a, b;
        ssin >> a >> b;
        // result of ls cmd
        if(a == "dir") {
          // folder
          cur->children.push_back(new Node(b, 0, true, cur));
        } else {
          // file
          int sz = stoi(a);
          cur->children.push_back(new Node(b, sz, false, cur));
        }
    }
  }

  // print(root, "");
  int total = 70000000, need = 30000000;
  int sum = dfs(root);
  int target = sum - total + need;

  sort(nums.begin(), nums.end());
  cout << *lower_bound(nums.begin(), nums.end(), target) << endl;
  return 0;
}