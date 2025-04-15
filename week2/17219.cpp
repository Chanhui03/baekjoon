#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  string site_buf, pw_buf;
  map<string, string> site_password;

  for(int i = 0; i < n; i++) {
    cin >> site_buf >> pw_buf;
    site_password.insert({site_buf, pw_buf});
  }

  for(int i = 0; i < m; i++) {
    cin >> site_buf;
    cout << site_password.find(site_buf)->second << '\n';
  }

  return 0;
}