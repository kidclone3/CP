#include <bits/stdc++.h>
using namespace std;
int format(string a)
{
    if (a == "A")
        return 1;
    if (a == "J" || a == "Q" || a == "K" || a == "10")
        return 10;
    else
        return a[0] - '0';
}
void solve(string a, string b)
{
    int aa[2];
    aa[0] = format(a);
    aa[1] = format(b);
    sort(aa, aa + 2);
    if (aa[0] == 1)
    {
        if (aa[1] == 10)
            cout << "Blackjack" << '\n';
        else
            cout << 21 << '\n';
    }
    else
    {
        int sum = aa[0] + aa[1];
        if (sum >= 11)
            cout << 21 << '\n';
        else if (sum <= 10)
            cout << sum + 11 << '\n';
        else
            cout << sum + 10 << '\n';
    }
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string a, b;
        cin >> a >> b;
        solve(a, b);
    }
}