#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Set {
  private:
    vector<int> set_s;

  public:
    Set();
    void setAdd(int x);
    void setRemove(int x);
    void setCheck(int x);
    void setToggle(int x);
    void setAll();
    void setEmpty();

};

Set::Set() {
  set_s.clear();
}

void Set::setAdd(int x) {
  if (find(set_s.begin(), set_s.end(), x) == set_s.end()) set_s.push_back(x);
}
void Set::setRemove(int x) {
  set_s.erase(remove(set_s.begin(), set_s.end(), x), set_s.end());
}
void Set::setCheck(int x) {
  cout << (find(set_s.begin(), set_s.end(), x) != set_s.end() ? '1' : '0' ) << endl;
}
void Set::setToggle(int x) {
  if (find(set_s.begin(), set_s.end(), x) == set_s.end()) setAdd(x);
  else setRemove(x);
}
void Set::setAll() {
  setEmpty();
  for(int i = 0; i < 20; i++) set_s.push_back(i+1);
}
void Set::setEmpty() {
  set_s.clear();
}

int main() {
  Set s;
  int cmd_time;
  cin >> cmd_time;

  string cmd;
  int cmd_x;

  for(int i = 0; i < cmd_time; i++) {
    cin >> cmd;
    if (cmd.compare("all") != 0 && cmd.compare("empty") != 0) {
      cin >> cmd_x;
      if (cmd.compare("add") == 0) s.setAdd(cmd_x);
      else if (cmd.compare("remove") == 0) s.setRemove(cmd_x);
      else if (cmd.compare("check") == 0) s.setCheck(cmd_x);
      else if (cmd.compare("toggle") == 0) s.setToggle(cmd_x);
    }
    else if (cmd.compare("all") == 0) s.setAll();
    else if (cmd.compare("empty") == 0) s.setEmpty();
    else return 0;
  }

  return 0;
}