#include <iostream>
#include <vector>
using namespace std;

vector<int> v[105];
int virus[105];
int ans;

void dfs(int x)
{
  for(int i = 0; i < v[x].size(); i++)
  {
    //2차원 행렬
    int k = v[x][i];

    if(virus[k] == 0)
    {
      virus[k] = 1;
      ans++;
      dfs(k);
    }
  }
  return;
}

//바이러스
int main()
{
  int n, m;
  cin >> n >> m;

  for(int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;

    v[a].push_back(b);
    v[b].push_back(a);
  }

  virus[1] = 1;
  dfs(1);

  cout << ans;

  return 0;
}