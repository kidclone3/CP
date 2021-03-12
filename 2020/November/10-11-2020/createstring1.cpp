#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define ll long long

string inp, tmp = "";
map<int, bool> mp;
set<string> solve;

void solution(int n)
{
    if (n == inp.size())
    {
        solve.insert(tmp);
        return;
    }
    for (int i = 0; i < inp.size(); i++)
    {
        if (mp[i])
        {
            tmp += inp[i];
            mp[i] = false;
            solution(n + 1);
            tmp.pop_back();
            mp[i] = true;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> inp;
    for (int i = 0; i < inp.size(); i++)
    {
        mp[i] = true;
    }
    solution(0);
    cout << solve.size() << "\n";
    for (auto it : solve)
    {
        cout << it << "\n";
    }
}