#include <iostream>
#include <string>

using namespace std;

class Set {
private:
    bool set_s[21];

public:
    Set() { fill(set_s, set_s + 21, false); }

    void setAdd(int x) { set_s[x] = true; }
    void setRemove(int x) { set_s[x] = false; }
    void setCheck(int x) { cout << (set_s[x] ? 1 : 0) << '\n'; }
    void setToggle(int x) { set_s[x] = !set_s[x]; }
    void setAll() { fill(set_s + 1, set_s + 21, true); }
    void setEmpty() { fill(set_s, set_s + 21, false); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    Set s;
    int cmd_time;
    cin >> cmd_time;

    string cmd;
    int x;

    while (cmd_time--) {
        cin >> cmd;
        if (cmd == "add") { cin >> x; s.setAdd(x); }
        else if (cmd == "remove") { cin >> x; s.setRemove(x); }
        else if (cmd == "check") { cin >> x; s.setCheck(x); }
        else if (cmd == "toggle") { cin >> x; s.setToggle(x); }
        else if (cmd == "all") s.setAll();
        else if (cmd == "empty") s.setEmpty();
    }

    return 0;
}
