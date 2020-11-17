#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
vector<int> tmp;
void solution(vector<int> x, int t);
vector<vector<int>> combinationSum(vector<int> &candidates, int target);
int main()
{
    vector<int> inp = {2, 3, 5};
    int t = 8;
    vector<vector<int>> out = combinationSum(inp, t);
    for (auto i : out)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << '\n';
    }
    int Max = max(1, 2);
    cout << Max;
}

void solution(vector<int> x, int t, int j)
{
    if (t == 0)
    {
        res.push_back(tmp);
        return;
    }
    else
        for (int i = j; i < x.size(); i++)
        {
            if (x[i] <= t)
            {
                tmp.push_back(x[i]);
                solution(x, t - x[i], i);
                tmp.pop_back();
            }
            else
                break;
        }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    solution(candidates, target, 0);
    vector<vector<int>> sol;
    for (auto it : res)
    {
        sol.push_back(it);
    }
    return sol;
}