#include <bits/stdc++.h>
using namespace std;

vector<bool> check;
bool res = false;
void feasible(vector<int> x, int t);
bool solution(vector<int> x, int t);

int main()
{
    vector<int> x = {8, 6, 7, 5, 3, 10, 9};
    int t = 0;
    if (solution(x, t))
        cout << "true";
    else
        cout << "false";
}
void feasible(vector<int> x, int t)
{
    if (t == 0)
    {
        for (auto it : check)
        {
            if (!it)
            {
                res = true;
                return;
            }
        }
        return;
    }
    for (int i = 0; i < x.size(); i++)
    {
        if (check[i] && x[i] <= t)
        {
            check[i] = 0;
            feasible(x, t - x[i]);
            check[i] = 1;
        }
    }
}
bool solution(vector<int> x, int t)
{
    check.resize(x.size(), 1);
    feasible(x, t);
    return res;
}
