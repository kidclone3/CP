#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define ll long long

int n;
string father, mother;
string tmp = "";
set<string> st;
void gen(int m)
{
    if (m == n)
    {
        st.insert(tmp);
        return;
    }
    for (auto i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            tmp += father[m];
        }
        else
        {
            tmp += mother[m];
        }
        gen(m + 1);
        tmp.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("gen.inp", "r", stdin);
    freopen("gen.out", "w", stdout);
    cin >> n;

    cin >> father >> mother;
    gen(0);
    for (auto it : st)
        cout << it << '\n';
}