#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s)
{
    map<char, int> ch;
    map<int, int> freq;
    for (auto it : s)
    {
        ch[it]++;
    }
    for (auto it : ch)
    {
        freq[it.second]++;
    }
    if (freq.size() == 1)
        return "YES";
    else if (freq.size() > 2)
        return "NO";
    auto first = freq.begin();
    auto sec = freq.begin();
    advance(sec, 1);
    if (first->first == 1 && first->second == 1)
        return "YES";
    if ((sec->first - first->first) == 1 && sec->second == 1)
        return "YES";
    return "NO";
}

int main()
{
    string inp = "aaab";
    cout << isValid(inp);
}