#include <bits/stdc++.h>
using namespace std;
int main() {
    string a; cin >> a;
    string b = "";
    // cout << b.size();
    for(auto it:a) {
        if (it == '0') {
            b.push_back('0');
        }
        else if (it == '1') {
            b.push_back('1');
        }
        else if (!b.empty()) b.pop_back();
    }
    cout << b;
}