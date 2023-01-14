#include<bits/stdc++.h>
using namespace std;

int n;

string int2bin(int x) {
    string ans = "";
    for (int i = 0; (1<<i) <= x; ++i) {
        if (x & (1<<i)) ans.push_back('1');
        else ans.push_back('0');
    }
    while(ans.size() < n) ans.push_back('0');
    reverse(ans.begin(), ans.end());
    return ans;
}

int g (int n) {
    return n ^ (n >> 1);
}

int main() {
    cin >> n;
    for (int i = 0; i < (1<<n); ++i) {
        cout << int2bin(g(i)) << '\n';
    }
}