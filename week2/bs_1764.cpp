#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<string>non_h,non_hs; //듣도 못한사람, 듣보잡

    int n, m;
    string buf;
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        cin >> buf;
        non_h.push_back(buf);
    }
    sort(non_h.begin(), non_h.end());
    
    for (int i = 0; i < m; i++) {
        cin >> buf;
        if (binary_search(non_h.begin(), non_h.end(), buf)) non_hs.push_back(buf);
    }
    sort(non_hs.begin(), non_hs.end());
    
    cout << non_hs.size() << "\n";
    //vector 배열 출력
    for (auto out : non_hs) cout << out << "\n";

    return 0;
}