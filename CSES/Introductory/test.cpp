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
int N;
string s;
void process(int n)
{
    if (s.size() == N)
    {
        cout << s << '\n';
        return;
    }
    for (char j = '0'; j < '2'; ++j)
    {
        s += j;
        process(n + 1);
        s.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    process(0);
}