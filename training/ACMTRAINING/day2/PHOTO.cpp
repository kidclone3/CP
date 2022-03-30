#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n; // n la so luong muon chup
    int d; cin >> d; // k la dung luong cua bo nho.
    int aa, bb; cin >> aa >> bb;
    vector<int> a;
    for(int i = 0; i < n; ++ i) {
        int x, y; cin >> x >> y;
        a.push_back(x*aa+y*bb);
    }
    // Sap xep theo tong dung luong cac con bo` can.
    sort(a.begin(), a.end());
    int curr = 0, i;
    for(i = 0; i < n; ++i) {
        curr += a[i];
        if (curr > d) break;
    } 
    cout << i << "\n";
    for(i = 0; i < n; ++i) cout << a[i] << " ";
}
