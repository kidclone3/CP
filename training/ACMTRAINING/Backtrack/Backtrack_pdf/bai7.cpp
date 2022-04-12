#include<bits/stdc++.h>
using namespace std;

#define ll long long

int m;
string s; 
vector<int> digit;
vector<int> op;
vector<string> ans;
int n;

void check() {
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        if (op[i]) {
            sum += digit[i];
        } else sum -= digit[i];
    }
    cerr << sum <<'\n';
    if (sum == m) {
        string tmp = "";
        for(int i = 0; i < n; ++i) {
            if (op[i]) {
                tmp.push_back('+');
            } else tmp.push_back('-');
            tmp.push_back(s[i]);
        }
        ans.push_back(tmp);
    }
}

void backtrack(int i) {
    if (i == n) {
        check();
        return;
    }
    for(int j = 0; j < 2; ++j) {
        op.push_back(j);
        backtrack(i+1);
        op.pop_back();
    }
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    cin >> m;
    cin >> s;
    n = s.size();
    op.clear();
    for(auto it : s) digit.push_back(it-'0');
    backtrack(0);
    if (ans.empty()) cout << "not found\n";
    for(auto it : ans) cout << it << '\n';
    // cout << "not found\n";
    return 0;
}