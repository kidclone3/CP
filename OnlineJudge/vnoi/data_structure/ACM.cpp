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
bool same(pair<int, int> a, pair<int, int> b) {
    return a.first == b.second && a.second == b.first;
}
multiset<pair<int, int>>::iterator erase(multiset<pair<int, int>> &a, multiset<pair<int, int>>::iterator ia) {
    auto tmp = ia;
    ia++;
    a.erase(tmp);
    return ia;
}
void erase_2(multiset<pair<int, int>> &a, pair<int, int> target, multiset<pair<int, int>>::iterator &ia) {
    int tmp_l = target.first;
    int tmp_r = target.second;
    auto f = a.lower_bound({tmp_r, tmp_l});
    if (f == ia) {
        ia++;
    }
    a.erase(f);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> a(2*n), b(2*n);
    F_OR(i, 0, 2*n, 1) {
        cin >> a[i] >> b[i];
    }
    multiset<pair<int, int>> ai, bi;
    F_OR(i, 0, 2*n, 1) {
        ai.insert({a[i], b[i]});
        bi.insert({b[i], a[i]});
    }
    // two pointer ?
    ll sum = 0;
    auto ia = ai.begin();
    auto ib = bi.begin();
    int count1, count2;
    count1 = count2 = 0;
    F_OR(i, 0, 2*n, 1) {
        if (same(*ia, *ib)) {
            if (ia->first < ia->second && count1 < n) {
                count1++;
                sum+= ia->first;
                erase_2(bi, *ia, ib); // vi iterator cua ia != multiset bi => phai dung gia tri.
                ia = erase(ai, ia);
                
            }
            else if (ia->first == ia->second){
                if (count1<n) {
                    count1++;
                    sum += ia->first;
                    erase_2(bi, *ia, ib);
                    ia = erase(ai, ia);
                }
                else {
                    count2++;
                    sum += ia->first;
                    erase_2(ai, *ia, ia);
                    ib = erase( )
                }
            }
        }
    }
}