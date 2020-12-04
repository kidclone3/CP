#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()

int a[255];
int n;
ll MIN = LLONG_MAX;
ll sum;
string s = "";

void process(string s)
{
    ll tmp = 0;
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            tmp += a[i];
        mp[s[i]]++;
    }
    if (mp['1'] == s.size())
        return;
    MIN = min(MIN, abs(sum - 2 * tmp));
}

void generate(int k)
{
    if (k == n)
    {
        process(s);
        return;
    }
    for (char i = '0'; i < '2'; i++)
    {
        s += i;
        generate(k + 1);
        s.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    generate(0);
    cout << MIN;
}