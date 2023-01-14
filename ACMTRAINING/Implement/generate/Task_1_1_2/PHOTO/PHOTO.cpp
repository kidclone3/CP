#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n; // n la so luong muon chup
    long long d; cin >> d; // k la dung luong cua bo nho.
    int aa, bb; cin >> aa >> bb;
    vector<long long> a;
    for(int i = 0; i < n; ++ i) {
        long long x, y; cin >> x >> y;
        a.push_back(x*aa+y*bb);
    }
    // Sap xep theo tong dung luong cac con bo` can.
    sort(a.begin(), a.end());
    long long curr = 0LL;
    int i;
    for(i = 0; i < n; ++i) {
        curr += a[i]*1LL;
        if (curr > d) break;
    } 
    cout << i;
    // for(i = 0; i < n; ++i) cout << a[i] << " ";
}
