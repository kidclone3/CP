#include <bits/stdc++.h>
using namespace std; 

int n;
vector<int> tmp;
vector<vector<int>> ans;
void backtrack(int x) {
    if (x == 0) {
        ans.push_back(tmp);
        return;
    }
    for(int i = 1; i <= x; ++i) {
        tmp.push_back(i);
        backtrack(x-i);
        tmp.pop_back();
    }
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    cin >> n;
    backtrack(n);
    ans.pop_back();
    for(auto &it: ans) {
        for(auto &it2 : it) {
            cout << it2 << " ";
        }
        cout << '\n';
    }
}
