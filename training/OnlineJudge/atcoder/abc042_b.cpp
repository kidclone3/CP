#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, l;
    cin >> n >> l;
    vector<string> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (auto& it: a) {
        cout << it;
    }
}