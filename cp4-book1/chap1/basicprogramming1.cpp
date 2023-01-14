#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    ll a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    switch(t) {
        case 1:
            cout << 7;
            break;
        case 2:
            {
                if (a[0] > a[1]) cout << "Bigger";
                else if (a[0] == a[1]) cout << "Equal";
                else cout << "Smaller";
                break;
            }
        case 3:
            {
                sort(a, a+3);
                cout << a[1];
                break;
            }
        case 4:
            {
                ll sum = 0LL;
                for(int i = 0 ; i < n; ++i) sum += a[i];
                cout << sum;
                break;
            }
        case 5:
            {
                ll sum = 0LL;
                for(int i = 0 ; i < n; ++i) if (!(a[i] & 1)) sum += a[i];
                cout << sum;
                break;
            }
        case 6:
            {
                for(int i = 0; i < n; ++i) a[i] %= 26, cout << (char) (a[i] + 'a');
                break;
            }
        case 7:
            {
                map<int, bool> visited;
                int i = 0;
                while (!visited[i]) {
                    visited[i] = true;
                    if (i > n-1) return cout << "Out", 0;
                    if (i == n-1) return cout << "Done", 0;
                    i = a[i];
                }
                cout << "Cyclic";
                break;
            }
    }
    return 0;
}
