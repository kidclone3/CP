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
        cout << it << "\n";
    }
};
int N;
vector<string> arr;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    string s(N, '0');
    arr.pb(s);
    map<string, bool> mp;
    mp[s] = true;
    while (arr.size() < pow(2, N))
    {
        for (int i = arr[0].size() - 1; i >= 0; --i)
        {
            string temp = arr.back();
            if (arr.back()[i] == '0')
            {
                temp[i] = '1';
            }
            else
            {
                temp[i] = '0';
            }
            if (!mp[temp])
            {
                arr.pb(temp);
                mp[temp] = true;
                break;
            }
        }
    }
    print(arr);
}