#include <bits/stdc++.h>
using namespace std;
bool search_s(string s, string a)
{
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == a[j])
        {
            j++;
        }
        if (j = a.size())
            return true;
    }
    return false;
}
int main()
{
    int n;
    vector<pair<string, int>> inp;
    n = 3;
    inp = {{"Tokyo", 37}, {"Paris", 10}, {"London", 9}};
    string search = "Lon";
    int count = 0;
    for (auto it : inp)
    {
        if (search_s(it.first, search))
            count += it.second;
    }
    cout << count;
}