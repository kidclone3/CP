#include <bits/stdc++.h>
using namespace std;

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    // Du lieu da duoc sap xep nen rat de de code.
    vector<int> ans;
    stack<int> ranking;
    for (auto it : ranked) {
        if (ranking.empty() || it != ranking.top()) {
            ranking.push(it);
        }
    }
    for (auto it : player) {
        while (!ranking.empty() && it >= ranking.top()) {
            ranking.pop();
        }
        ans.push_back((int)ranking.size() + 1);
    }
    return ans;
    // Co the code cach khac dung binary search. Hazzz.
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