#include<bits/stdc++.h>
using namespace std;

int solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> medals;
    int curr = 1;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i) {
            if (a[i]!=a[i-1]) {
                medals.push_back(curr);
                curr = 1;
            } else curr++;
        }
    }
    medals.push_back(curr);
    // trong moi truong hop, cai dau tien luon la gold.
    int sum = medals[0]; // sum <= n/2.
    int gold = medals[0];
    int silver, bronze;
    silver = bronze = 0;
    int i = 1;
    while(i < (int) medals.size() && sum + medals[i] <= n/2 && silver <= gold) {
        silver += medals[i];
        sum += medals[i++];
    }
    while(i < (int) medals.size() && sum + medals[i] <= n/2) {
        bronze += medals[i];
        sum += medals[i++];
    }
    // for(auto &it : medals) cout << it << " ";
    // cout << '\n';
    // 
    // cout << gold << " " << silver << " " << bronze << '\n';
    if (gold >= silver || gold >= bronze || !silver || !bronze) return cout << "0 0 0\n", 0;
    else cout << gold << " " << silver << " " << bronze << '\n';
    return 0;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}
