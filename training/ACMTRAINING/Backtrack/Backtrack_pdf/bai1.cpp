#include <bits/stdc++.h> 
using namespace std;
set<string> ans;
string tmp;

void check() {
    for(int i = 0; i < (int) tmp.size()-1; ++i) {
        if (tmp[i] == tmp[i+1] && tmp[i] == 'B') return;
    }
    ans.insert(tmp);
}

void backtrack(int i, int n) {
    if (i == n) {
        check();
        return;
    }
    for(char c = 'A'; c <= 'B'; ++c) {
        tmp[i] = c;
        backtrack(i+1, n);
    }
}

int main() {
    int n; cin >> n;
    tmp.assign(n, ' ');
    backtrack(0, n);
    for(auto it : ans) {
        cout << it << "\n";
    }
}
