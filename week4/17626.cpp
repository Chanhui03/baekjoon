#include <iostream>
using namespace std;

int min(int a, int b) { return a < b ? a : b;}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  int dp[50001];
  dp[1] = 1;
  for (int i = 2; i*i <= n; i++) dp[i*i] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = 4;
    for(int j = 1; j*j <= i; j++) {
      dp[i] = min(dp[i], dp[i - j*j] + 1);
    }
  }

  cout << dp[n] << '\n';

  return 0;
}

/*
1  = 1 /1
2  = 2 /1 1
3  = 3 /1 1 1
4  = 1 /4
5  = 2 /4 1
6  = 3 /4 1 1
7  = 4 /4 1 1 1
8  = 2 /4 4
9  = 1 /9
10 = 2 /9 1
11 = 3 /9 1 1
12 = 3 /4 4 4
13 = 2 /9 4
14 = 3 /9 4 1
15 = 4 /9 4 1 1
16 = 1 /16
17 = 2 /16 1
18 = 2 /9 9
19 = 3 /9 9 1
20 = 2 /16 4
21 = 3 /16 4 1
22 = 3 /9 9 4
23 = 4 /9 9 4 1

dp[n] = dp[i*i] + dp[n - i*i]

*/
