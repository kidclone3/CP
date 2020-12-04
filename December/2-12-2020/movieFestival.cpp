#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<pair<int, int>>
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

vi c;

bool tmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        c.pb({a, b});
    }
    // sap xep mang theo thu tu thoi gian ket thuc tang dan
    sort(all(c), tmp);
    int j = 0;
    int ans = 1;
    // Dung 1 bien j de luu vi tri da duyet
    // Xet neu thoi gian bat dau c[i].first >= thoi gian
    // ket thuc cua hoat dong truoc do c[j].second
    // ==> cong them vao?
    // Tuy nhien cau hoi o day la neu dung ki thuat nay
    // thi chon goc o phan tu thu 2 se nhu the nao?
    for (int i = 0; i < n; i++)
    {
        if (c[i].first >= c[j].second)
        {
            ans++;
            j = i;
        }
    }
    cout << ans;
}

// 3 7
// 3 5
// 6 8
// 6 7
