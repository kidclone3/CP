#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        st.insert(tmp);
    }
    cout << st.size();
    return 0;
}