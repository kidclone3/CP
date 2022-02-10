// https://codeforces.com/problemset/problem/1304/B
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i)
#define FOR1(i, a) for (int i = 1; i < (a + 1); ++i)
#define F0R(i, a, b) for (int i = (a); i < (b); ++i)
#define F_OR(i, a, b, step) for (int i = (a); (step) > 0 ? i < (b) : i > (b); i += (step))
#define EACH(x, a) for (auto &x : a)
template <class T>
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
bool isPalindrome(string s)
{
    if (s.size() == 1)
        return true;
    for (int i = 0; i <= s.size() / 2; ++i)
    {
        if (s[i] != s[s.size() - 1 - i])
            return false;
    }
    return true;
}
void solve();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
void solve()
{
    int n, x;
    cin >> n >> x;
    map<string, int> mp;
    FOR(i, n)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    queue<string> left;
    stack<string> right;
    priority_queue<pair<int, string>> pq;
    // Trong truong hop can tim 1 palin o giua => luu vao priority.
    EACH(it, mp)
    {
        string now = it.first;
        string tmp = it.first;
        reverse(all(tmp));
        if (tmp == now)
        {
            // reverse = nhau => palin cmnr.
            while (mp[now] >= 2)
            {
                left.push(now);
                right.push(now);
                mp[now] -= 2;
            }
            if (mp[tmp] == 1)
            {
                pq.push({tmp.size(), tmp});
            }
        }
        else
        {
            int mn = min(mp[now], mp[tmp]);
            if (mn > 0)
            {
                while (mn)
                {
                    left.push(now);
                    right.push(tmp);
                    mp[now]--;
                    mp[tmp]--;
                    mn--;
                }
            }
        }
    }
    string ans = "";
    while (!left.empty())
    {
        ans += left.front();
        left.pop();
    }
    if (!pq.empty()) {
        ans+=pq.top().second;
    }
    while (!right.empty())
    {
        ans += right.top();
        right.pop();
    }
    cout << ans.size() << '\n';
    cout << ans << '\n';
}