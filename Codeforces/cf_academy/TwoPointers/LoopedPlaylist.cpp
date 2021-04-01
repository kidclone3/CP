#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define F_OR(i, a, b, step) for (int i = (a); (step) > 0 ? i < (b) : i > (b); i += (step))
#define EACH(x, a) for (auto &x : a)
#define BUG(x)                    \
    {                             \
        cout << #x << " = " << x; \
    }
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};

int main(int argc, char const *argv[])
{

    long long int n, p;
    cin >> n >> p;
    long long int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long int r = 0;
    long long int sum = 0;
    long long int s = 0;
    for (int l = 0; l < n; l++)
    {
        while ( r < n && s+a[r] <=p)
        {
            s += a[r];
            r++;
        }

        // if (s >= p)
        // {
            long long int dau = 1;
            long long int cuoi = r-l;
            long long int so = cuoi - dau + 1;
            sum+=(dau+cuoi)*so/2;
        // }
        s -= a[l];
    }
    cout << sum;
}
