#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define ll long long
int f[255], c[100];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("coinchange.inp", "r", stdin);
    freopen("coinchange.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> c[i];
    }
    sort(c + 1, c + m + 1);
    //th1: ngan hang vo han loai tien ==> duyet kieu nay se co cong dung nhu mot tong tich luy
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == c[i])
                f[j]++;
            else if (j > c[i])
                f[j] += f[j - c[i]];
        }
    }
    cout << f[n] << ' ';
    //th2: ngan hang sap pha san. Bang cach duyet nguoc lai tu tren xuong duoi ==> co the tinh duoc nhung tien rieng biet
    //for (int i = 1; i <= n; i++)
    //    f[i] = 0;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= m; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            if (j == c[i])
                f[j]++;
            else if (j > c[i])
                f[j] += f[j - c[i]];
        }
    }
    cout << f[n];
}