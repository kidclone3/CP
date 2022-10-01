#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string &s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[j] == s[i]) j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    string s; cin >> s;
    auto tmp = prefix_function(s);
    for (auto &it: tmp) cerr << it << " ";
}
