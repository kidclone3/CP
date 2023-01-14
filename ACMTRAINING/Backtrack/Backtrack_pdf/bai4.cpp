#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> a;
vector<string> ans;

void check() {
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        cnt += (a[i] == 0 ? 1 : -1);
        if (cnt < 0) return; 
    }
    if (cnt != 0) return;
    string tmp(n, ' ');
    for(int i = 0; i < n; ++i) {
        if (a[i] == 0) tmp[i] = '(';
        else tmp[i] = ')';
    }
    ans.push_back(tmp);
}

void backtrack(int i) {
    if (i == n) {
        check();
        return;
    }
    for(int j = 0; j < 2; ++j) {
        a[i] = j;
        backtrack(i+1);
    }
}

int main() {
    cin >> n;
    n *= 2;
    a.resize(n);
    backtrack(1);
    // cout << "test\n";
    for(auto it : ans) {
        cout << it << "\n";
    }
    return 0;
}