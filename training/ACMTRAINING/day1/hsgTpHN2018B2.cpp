#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
    }
    
    // Cach 1: dung map:
    {
        cout << "Cach 1: Dung map";
        int ans = 0;
        map<int, int> mp;
        for (int i = 0; i < n; ++ i) {
            ans += mp[-a[i]];
            mp[a[i]]++;
        }
        cout << ans+n;
    }

    // Cach 2: Dung tknp;
    {
        cout << "Cach 2: Tknp";
        sort(a, a+n);
        for(int i = 0; i < n; ++ i) {
            auto tmp = equal_range(a,a+n, -a[i]);
            ans += tmp.second - tmp.first;
        }
        cout << ans/2 + n;
    }
}
