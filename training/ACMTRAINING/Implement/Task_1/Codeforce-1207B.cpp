#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < m; ++j)
            cin >> a[i][j];
    vector<vector<int>> b(n, vector<int>(m, 0));
    vector<pair<int, int>> ans;
    for(int i = 0; i < n-1; ++i) 
        for(int j = 0; j < m-1; ++j) {
            if (a[i][j] == 1 && a[i][j] == a[i+1][j] && a[i][j] == a[i][j+1] && a[i][j] == a[i+1][j+1]) {
                b[i][j] = b[i+1][j] = b[i][j+1] = b[i+1][j+1] = 1;
                ans.push_back({i+1, j+1});
            }
        }
    bool isOK = true;
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < m; ++j)
            if (a[i][j] != b[i][j]) {
                isOK = false;
                break;
            }
    if (isOK) {
        cout << ans.size() << "\n";
        for(auto &it:ans) cout << it.first << " " << it.second <<"\n";
    } else {
        cout << -1;
    }
}
