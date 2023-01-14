#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    for(int i = 1; i <= 20; ++i) cout << sizeof(int)*8 << " " << sizeof(int) * 8 - __builtin_clz(i) << "\n";
}
