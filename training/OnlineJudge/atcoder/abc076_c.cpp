#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    if (t.size() > s.size()) {
        cout << "UNRESTORABLE";
        return 0;
    }
    vector<string> ans;
    for (size_t i = 0; i < s.size() - t.size() + 1; ++i)
    {
        if (s[i] == t[0] || s[i] == '?')
        {
            bool check = true;
            for (size_t j = i; j < i + t.size(); ++j)
            {
                if (s[j] != '?' && s[j] != t[j - i])
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                string tmp1 = s.substr(0, i);
                string tmp2 = s.substr(i + t.size(), s.size() - i + t.size());
                for (auto &it : tmp1)
                    if (it == '?')
                        it = 'a';
                for (auto &it : tmp2)
                    if (it == '?')
                        it = 'a';
                ans.push_back(tmp1 + t + tmp2);
            }
        }
    }
    if (ans.empty())
    {
        cout << "UNRESTORABLE";
    }
    else
    {
        sort(ans.begin(), ans.end());
        cout << ans[0];
    }
    // for(auto &it: ans) cout << it << "\n";
}