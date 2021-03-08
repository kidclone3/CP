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
    string n;
    cin >> n;
    n.pb('$');
    // tao 2 mang. 1 mang p de luu chi so, mang c de luu RANK.
    vector<int> p(n.size()), c(n.size());
    vector<pair<char, int>> a(n.size());
    // Khoi tao mang ban dau.
    // Mang p de luu chi so, la chi so bat dau cua suffix array.
    // Mang c de luu thu tu cua cac so' trong day.
    for (int i = 0; i< n.size(); ++i) {
        a[i]={n[i], i};
    }
    sort(all(a));
    F_OR(i, 0, n.size(), 1) {
        p[i] = a[i].second;
    }
    c[p[0]] = 0;
    F_OR(i, 1, n.size(), 1) {
        if (a[i].first == a[i-1].first) c[p[i]] = c[p[i-1]];
        else {
            c[p[i]] = c[p[i-1]] + 1;
            if (c[p[i]] == n.size() - 1) {
                print(p);
                return 0;
            }
        }
    }
    // print(c);
    // print(p);
    // cout << j << "\n";
    // Hoan thanh khoi tao.
    int k = 0;
    while ((1<<k) < n.size()) {
        // k = k+1
        // Can tach 1 xau con thanh 2.
        vector<pair<pair<int, int>, int>> a(n.size());
        F_OR(i, 0, n.size(), 1) {
            a[i] = {{c[i], c[(i + (1<<k)) % n.size()]}, i};
        }   
        sort(all(a));
        F_OR(i, 0, n.size(), 1) {
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        F_OR(i, 1, n.size(), 1) {
            int l1, l2;
            l1 = p[i]; l2 = p[i-1];
            if (a[i].first == a[i-1].first) c[p[i]] = c[p[i-1]];
            else {
                c[p[i]] = c[p[i-1]] + 1;
                // if (c[p[i]] == n.size() - 1) {
                //     print(p);
                //     return 0;
                // }
            }   
        }
        k++;
    }
    print(p);
}