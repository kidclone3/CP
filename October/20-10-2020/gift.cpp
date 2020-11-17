#include <bits/stdc++.h>
using namespace std;
long long value(int l, int m, vector<long long> a, set<long long> &b)
{
    int sum = 0;
    int med = 0;
    if (b.empty())
    {
        for (int i = l; i < l + m; i++)
        {
            b.insert(a[i]);
        }
    }
    else
    {
        if (b.size() == m)
        {
            b.erase(b.begin());
        }
        b.insert(a[l + m - 1]);
    }
    if (b.size() < m)
        return 0;
    if (m % 2 == 1)
    {
        auto it = b.begin();
        advance(it, m / 2);
        med = *it;
        for (auto itr : b)
        {
            sum += abs(itr - *it);
        }
    }
    else
    {
        set<long long>::iterator it1, it2;
        it1 = it2 = b.begin();
        advance(it1, m / 2);
        advance(it2, (m - 1) / 2);
        long long s1, s2;
        s1 = s2 = 0;
        for (auto itr : b)
        {
            s1 += abs(itr - *it1);
            s2 += abs(itr - *it2);
        }
        sum = max(s1, s2);
    }

    return sum;
}
long long solve(int k, vector<long long> a)
{
    long long MAX = 0;
    set<long long> b;
    int n = a.size();
    // loai cac phan tu lien tiep trung nhau
    for (int i = a.size() - 2; i > -1; i--)
    {
        if (a[i] == a[i + 1])
        {
            a.erase(a.begin() + i);
        }
    }
    for (int i = 0; i < n - k; i++)
    {
        MAX = max(value(i, k, a, b), MAX);
    }
    return MAX;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<long long> a;
    for (int i = 0; i < n; i++)
    {
        long long tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    cout << solve(k, a);
}