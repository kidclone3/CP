#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define VI vector<int>
#define ll long long

bool solve(ll k, int d0, int d1)
{
    /*
    Giai thich cac bien:
    + d la tong cac chu so
    + p[] la cac chu so trong phan` chua' quy luat
    + sum la` tong cua cac p[].
    Giai thich y tuong
    Xet 2 th k=2 va k=3. Neu = thi cho ra kqua luon
    k>3 nghia~ la` da vao` trong quy luat. Ta dung vong for de tinh p[i], dong thoi k--.
    Trong qua trinh nay, neu k=0 thi xet nhu tren.
    Doan code phia duoi t thay kha de hieu. Neu ko hieu noi t de giai thich them :)
    */
    ll d = (d0 + d1);
    if (k == 2)
        return (d % 3 == 0);
    d += d % 10;
    if (k == 3)
        return (d % 3 == 0);
    k -= 3; //bo qua 3 chu so dau roi
    int p[4], sum = 0;
    for (int i = 0; i < 4; i++)
    {

        sum += d % 10;
        p[i] = d % 10;
        d += d % 10;
        k--;
        if (k == 0)
            return (d % 3 == 0);
    }
    int k_4 = k / 4;
    d += sum * k_4;
    for (int i = 0; i < k % 4; i++)
    {
        d += p[i];
    }
    return (d % 3 == 0);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("a.inp", "r", stdin);
    //freopen("a.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        ll k;
        int d0, d1;
        cin >> k >> d0 >> d1;
        if (solve(k, d0, d1))
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}
