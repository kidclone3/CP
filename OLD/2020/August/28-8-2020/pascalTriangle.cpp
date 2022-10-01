#include <bits/stdc++.h>
using namespace std;
/* vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res;
    res.push_back({1});
    for (int n = 1; n <= numRows; n++)
    {
        vector<int> vtr1, vtr2;
        vtr1 = res[n - 1];
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || i == n - 1)
                vtr2.push_back(1);
            else
            {
                vtr2.push_back(vtr1[i] + vtr1[i - 1]);
            }
        }
        res.push_back(vtr2);
    }
    res.erase(res.begin(), res.begin() + 1);
    return res;
} */
vector<int> getRow(int rowIndex)
{
    vector<int> vtr1 = {1};
    for (int n = 2; n <= rowIndex + 1; n++)
    {
        vector<int> vtr2;
        for (int i = 0; i < n / 2; i++)
        {
            if (i == 0)
                vtr2.push_back(1);
            if (i == n / 2 - 1)
                vtr2.push_back(vtr1[i] * 2);
            else
            {
                vtr2.push_back(vtr1[i] + vtr1[i - 1]);
            }
        }
        vtr1 = vtr2;
    }
    if (rowIndex == 0)
        return vtr1;
    vtr1.insert(vtr1.end(), vtr1.rbegin(), vtr1.rend());
    return vtr1;
}
int main()
{
    int n = 3;
    /*vector<vector<int>> result;
    result = generate(n);
    for (auto it : result)
    {
        for (auto i : it)
            cout << i << " ";
        cout << '\n';
    }*/
    vector<int> result = getRow(n);
    for (auto i : result)
    {
        cout << i << " ";
    }
    return 0;
}