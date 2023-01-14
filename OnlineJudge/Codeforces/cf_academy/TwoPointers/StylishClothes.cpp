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
const int N = 1e5+5;
ll a1[N], a2[N], a3[N], a4[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int n1, n2, n3, n4;
    cin >> n1;
    F_OR(i, 0, n1, 1) {
        cin >> a1[i];
    }
    cin >> n2;
    F_OR(i, 0, n2, 1) {
        cin >> a2[i];
    }
    cin >> n3;
    F_OR(i, 0, n3, 1) {
        cin >> a3[i];
    }
    cin >> n4;
    F_OR(i, 0, n4, 1) {
        cin >> a4[i];
    }
    sort(a1, a1+n1);
    sort(a2, a2+n2);
    sort(a3, a3+n3);
    sort(a4, a4+n4);
    // ok, now is two pointer, no, it is 4 pointer;
    vector<ll> res(4);
    int ia1, ia2, ia3, ia4;
    ia1 = ia2 = ia3 = ia4 = 0;
    ll distance = LLONG_MAX;
    F_OR(ia1, 0, n1, 1) {
        while (ia2 +1 < n2 && abs (a2[ia2] - a1[ia1]) > abs(a2[ia2+1] - a1[ia1])) {
            ia2++;
        }
        while (ia3 + 1 < n3 && abs (a3[ia3] - a1[ia1]) > abs(a3[ia3+1] - a1[ia1])) {
            ia3++;
        }
        while (ia4 + 1 < n4 && abs (a4[ia4] - a1[ia1]) > abs(a4[ia4+1] - a1[ia1])) {
            ia4++;
        }
        ll tmp = abs(a2[ia2] - a1[ia1]) + abs(a3[ia3] - a1[ia1]) + abs(a4[ia4] - a1[ia1]);
        if (tmp < distance) {
            res[0] = a1[ia1];
            res[1] = a2[ia2];
            res[2] = a3[ia3];
            res[3] = a4[ia4];
            distance = tmp;
        }
    }
    print(res);
}
