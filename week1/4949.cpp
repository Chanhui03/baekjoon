#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
  while(true) {
    string input;
    stack<char> s;
    bool confi = true;

    getline(cin,input);
    if(input == ".") break; //'' <- char "" <- string

    for(int i = 0; i < input.length(); i++) {
      if(input[i] == '[' || input[i] == '(') s.push(input[i]);
      
      if(input[i] == ']') {
        if(!s.empty() && s.top() == '[') s.pop();
        else {
          confi = false;
          break;
        }
      }
      else if(input[i] == ')') {
        if(!s.empty() && s.top() == '(') s.pop();
        else {
          confi = false;
          break;
        }
      }
    }
    
    if(s.empty() && confi) cout << "yes" << endl;
    else cout << "no" << endl;
  }

  return 0;
}