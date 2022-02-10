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
set<string> storage;
bool isPalindrome(string s) {
    int n = s.size();
    F_OR(i, 0, n/2, 1) {
        if (s[i] != s[n-1-i]) return false;
    }
    F_OR(i, 1, n, 1) {
        if (s[i] < s[i-1]) return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int l2 = pow(2, s.size());
    F_OR(i, 1, l2, 1) {
        string tmp = "";
        int j = 0;
        while((1<<j) <= i) {
            if (i&(1<<j)) tmp+=s[j];
            j++;
        }
        if(isPalindrome(tmp)) storage.insert(tmp);
    }
    cout<<*storage.rbegin();
}
