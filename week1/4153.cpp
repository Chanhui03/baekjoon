#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  while(true) {
    vector<int> v;
    int a, b, c;
    cin >> a >> b >> c;

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    if(accumulate(v.begin(), v.end(), 0) == 0) break;
    sort(v.begin(), v.end());

    if((pow(v[0],2) + pow(v[1],2)) == pow(v[2],2)) cout << "right" << endl;
    else {
      cout << "wrong" << endl;
    }
    //if((v[0]*v[0] + v[1]*v[1]) == v[2]*v[2]) cout << "right" << endl;
    

  }
  return 0;
}