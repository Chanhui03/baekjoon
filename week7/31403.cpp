#include <iostream>
#include <string>

using namespace std;

// A + B - C
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
    
  string A, B, C;
  
  cin >> A >> B >> C;
  cout << stoi(A) + stoi(B) - stoi(C) << "\n";
  cout << stoi(A + B) - stoi(C);

  return 0;
}