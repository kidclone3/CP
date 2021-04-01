#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define F_OR(i, a, b, step) for (int i=(a); (step)>0? i<(b) : i>(b); i+=(step))
#define EACH(x, a) for(auto& x: a)
#define BUG(x)                    \
    {                             \
        cout << #x << " = " << x; \
    }
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        ll m;
        cin >> n >> m;
        vector<ll> a(n), b(n);
        ll sum_a, sum_b;
        sum_a = sum_b = 0LL;
        F_OR(i, 0, n, 1) {
            cin >> a[i];
            sum_a += a[i];
        }
        F_OR(i, 0, n, 1) {
            cin >> b[i];
            sum_b += b[i];
        }
        vector<ll> c1, c2;
        F_OR(i, 0, n, 1) {
            // [i] = {a[i], b[i]};
            if (b[i]==1) {
                c1.pb(a[i]);
            }
            else {
                c2.pb(a[i]);
            }
        }
        if (sum_a < m) {
            cout<<"-1\n";
            continue;
        }
        sort(c1.rbegin(), c1.rend());
        sort(c2.rbegin(), c2.rend());
        int i, j; // i cho c1, j cho c2.
        i = j = 0;
        // dung two pointer;
        ll a_count, b_count;
        a_count = b_count = 0;
        while(a_count<m) {
            ll tmp = c1[i] + c1[i+1];
            if (c1[i] >= c2[j]) {
                a_count+=c1[i];
                b_count++;
                i++;
            }
            else if (tmp<c2[j] {
                a_count+=c2[j];
                b_count+=2;
                j++;
            }
            else {
                a_count+= tmp;
                b_count+=2;
                i+=2;
            }
            
        }
        cout<<b_count<<"\n";
        
    }
}
