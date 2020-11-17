#include <bits/stdc++.h>
std::vector<std::vector<int>> uniqueRows(std::vector<std::vector<int>> matrix)
{
    std::set<std::vector<int>> res;
    std::vector<std::vector<int>> result;
    for (std::vector<std::vector<int>>::iterator row = matrix.begin(); row != matrix.end(); row++)
    {
        res.insert(*row);
    }
    for (auto it : res)
    {
        result.push_back(it);
    }
    return result;
}

int main()
{
    std::vector<std::vector<int>> rows = {{1, 0, 0, 1}, {1, 1, 0, 1}, {1, 1, 0, 1}};
    return 0;
}