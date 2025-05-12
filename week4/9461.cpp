#include <iostream>
#include <vector>

using namespace std;

//파도반 수열
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test_case, n;
  vector<long long> p(101);
  cin >> test_case;

  p[0] = 0; p[1] = 1; p[2] = 1; p[3] = 1;
  p[4] = 2; p[5] = 2; p[6] = 3;

  for(int i = 7; i < 101; i++) {
    p[i] = p[i-2] + p[i-3];
  }

  while(test_case--) {
    cin >> n;
    cout << p[n] << '\n';
  }

  return 0;
}