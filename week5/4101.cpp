#include <iostream>
using namespace std;

// 크냐?
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  while(1) {

    int n, m;
    cin >> n >> m;

    if ( n == 0 && m == 0) break;

    n > m ? cout << "Yes" << '\n' : cout << "No" << '\n';
  }

  return 0;

}