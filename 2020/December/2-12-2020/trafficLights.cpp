#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()

template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, n;
    multiset<int> locate, distinct;
    cin >> x >> n;
    locate.insert(0);
    locate.insert(x);
    distinct.insert(x);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        locate.insert(a);
        auto right = locate.upper_bound(a);
        auto left = --locate.lower_bound(a);
        int to_Delete = *right - *left;
        int tmp1, tmp2;
        tmp1 = *right - a;
        tmp2 = a - *left;
        distinct.erase(distinct.find(to_Delete));
        distinct.insert(tmp1);
        distinct.insert(tmp2);
        cout << *distinct.rbegin() << " ";
    }
}