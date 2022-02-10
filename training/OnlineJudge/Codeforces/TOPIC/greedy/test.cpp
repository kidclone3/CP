#include <bits/stdc++.h>
using namespace std;
 
void preamble()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
}
int main(int argc, char const *argv[])
{
    // preamble();
    int n;
    cin >> n;
    long long int a[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
 
    map<long long, int> mp;
    mp[0] = 0;
    int c = 0;
    int current = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!mp.count(a[i]))
        {
            mp[a[i]] = i;
        }
        else
        {
            if (mp[a[i]] >= current - 1)
            {
                c++;
                mp[a[i]] = i;
                current = i;
            }
        }
    }
    cout << c << endl;
    return 0;
}