#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<ll>
#define ll long long
#define all(x) x.begin(), x.end()
#define ms multiset<ll>

ll a, n, k, sumLeft, sumRight;

template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
}

void balance(multiset<ll> &left, multiset<ll> &right)
{
    ll kk = k % 2;
    // th k chan ==> 2 cai set = size nhau.
    // kk=0;
    // k le ==>kk=1 ==> 1 cai la k/2, 1 cai la k/2+1;
    // o day ta cho right la k/2+1
    while (left.size() + kk < right.size())
    {
        ll tmp;
        tmp = *right.begin();
        right.erase(right.begin());
        left.insert(tmp);
        sumRight -= tmp;
        sumLeft += tmp;
    }
    while (left.size() + kk > right.size())
    {
        ll tmp;
        tmp = *left.rbegin();
        left.erase(--left.end());
        right.insert(tmp);
        sumLeft -= tmp;
        sumRight += tmp;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    multiset<ll> left, right;
    queue<ll> holding;
    vi out;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        holding.push(a);
        if (!right.empty() && a > *right.begin())
        {
            right.insert(a);
            sumRight += a;
        }
        else
        {
            left.insert(a);
            sumLeft += a;
        }
        if (i >= k - 1)
        {
            // khi ma i= k-1 ==> lan dau tien xuat ra median --> day 1 nua sang right
            balance(left, right);
            ll tmp, ans = 0;
            if (k % 2)
            {
                tmp = *right.begin();
            }
            else
            {
                tmp = *left.rbegin();
            }
            ans = abs(tmp * (ll)right.size() - sumRight);
            ans += abs(tmp * (ll)left.size() - sumLeft);
            out.pb(ans);

            //boi bi multiset khi xoa theo pha tu se xoa tat ca cac gia tri do,
            // nen phai dung pointer de tim + xoa
            if (left.find(holding.front()) != left.end())
            {
                left.erase(left.find(holding.front()));
                sumLeft -= holding.front();
            }
            else
            {
                right.erase(right.find(holding.front()));
                sumRight -= holding.front();
            }
            holding.pop();
        }
    }
    print(out);
}