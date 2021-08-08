#include <bits/stdc++.h>
using namespace std;

string s = "";
vector<string> ans;

int n;

void out() {
    for (int i = 1; i < n; ++i) {
        if (s[i] == 'B' && s[i-1] == 'B') return;
    }
    ans.push_back(s);
    // ans[5] ~ ans.at(5)

}

void dequy(int i) {
    if (i == n) {
        out();
        return;
    }
    for (char ch = 'A'; ch <= 'B'; ++ch) {
        // s += ch;
        s.push_back(ch);
        dequy(i+1);
        s.pop_back();
    }
}

int main() {
    cin >> n;
    dequy(0);
    for (auto& it : ans) {
        cout << it << "\n";
    }
}