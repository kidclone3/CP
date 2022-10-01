#include <bits/stdc++.h>
using namespace std;

vector<int> powerfulIntegers(int x, int y, int bound);
int main()
{
    int x, y, bound;
    x = 2;
    y = 3;
    bound = 10;
    vector<int> out = powerfulIntegers(x, y, bound);
    for (auto it : out)
        cout << it << " ";
}
vector<int> powerfulIntegers(int x, int y, int bound)
{
    set<int> st;
    int r1, r2;
    if (x > 1)
    {
        r1 = (int)(log(bound) / log(x) + 1);
    }
    else
    {
        r1 = 1;
    }
    if (y > 1)
    {
        r2 = (int)(log(bound) / log(y) + 1);
    }
    else
    {
        r2 = 1;
    }
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < r2; j++)
        {
            int tmp = (int)pow(x, i) + (int)pow(y, j);
            if (tmp <= bound)
            {
                st.insert(tmp);
            }
            else
                break;
        }
        if ((int)pow(x, i) > bound)
            break;
    }
    vector<int> res;
    for (auto it : st)
    {
        res.push_back(it);
    }
    return res;
}