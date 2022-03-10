#include <bits/stdc++.h>
using namespace std;

const int N = 2000+5;

vector<bitset<N>> adj(N);

int main() {
    // Su dung bitset lam ma tran ke.
    // input: n m 
    // m dong: 2 dinh a,b <=> co lien ket
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    // Dem so tam giac trong O(n^2*n/32)
    int ans = 0;
    for(int i = 0; i < n-1; ++i) {
        for(int j = i+1; j < n; ++j) {
            if (adj[i][j]) {
                bitset<N> tmp = adj[i] & adj[j];
                ans += tmp.count();
            }
        }
    }
    cout << ans;
}
