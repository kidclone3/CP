#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define F_OR(i, a, b, step) for (int i=(a); (step)>0? i<(b) : i>(b); i+=(step))
#define EACH(x, a) for(auto& x: a)
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

void solve(int a, int b, int c) {
    if ( (a+b) <= c || (a+c) <= b || (b+c) <= a) {
        cout<<"-1.00";
    }
    else {
        float p = (a + b + c) / 2.0;
        float res = sqrt(p * (p - a) * (p - b) * (p - c));
        cout.precision(2);
        cout.setf(ios::fixed, ios::floatfield);
        cout << res;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c; 
    cin >> a >> b >> c;
    solve(a, b, c);
}