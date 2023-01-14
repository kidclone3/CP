#include <bits/stdc++.h>
using namespace std;

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    // Du lieu da duoc sap xep nen rat de de code.
    vector<int> ans;
    // De y thay du lieu player da duoc sap xep. 
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    vector<int> ans = climbingLeaderboard(a, b);
    for (auto it : ans) {
        cout << it << '\n';
    }
    
    
}