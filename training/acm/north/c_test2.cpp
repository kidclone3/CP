#include<bits/stdc++.h>

using namespace std;

int powN(int x, int n){
    if (!n) return 1;
    if (n == 1) return x;
    int half(powN(x, n>>1));
    if (n&1) return half*half*x;
    return half*half;
    // int res(1);
    // for (int i=0; i<n; i++) res *= x;
    // return res;
}

int main(){
    ios::sync_with_stdio(true);
    cin.tie(0);
    // freopen("test.inp", "r", stdin);
    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        int n(s.size());
        cout << fixed << setprecision(9) << powN(2, n+1) - 2;
        if (q) cout << '\n';
    }
}