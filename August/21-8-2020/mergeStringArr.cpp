#include <bits/stdc++.h>

std::vector<std::string> mergeStringArr(std::vector<std::string> arr1, std::vector<std::string> arr2)
{
    std::set<std::string> set1, set2, res;
    set1.insert(arr1.begin(), arr1.end());
    set2.insert(arr2.begin(), arr2.end());
    for (auto it1 = set1.begin(); it1 != set1.end();)
    {
        auto it2 = set2.find(*it1);
        if (it2 != set2.end())
        {
            set2.erase(it2);
            it1 = set1.erase(it1);
        }
        else
            ++it1;
    }
    res.insert(set1.begin(), set1.end());
    std::vector<std::string> vectorResult(res.begin(), res.end());
    return vectorResult;
}

int main()
{
    std::vector<std::string> arr1 = {"codelearn", "learncode", "codelearn", "io", "fpt"};
    std::vector<std::string> arr2 = {"learncode", "codelearnio", "fsoft"};
    std::vector<std::string> arr = mergeStringArr(arr1, arr2);
    for (auto it : arr)
        std::cout << it << "\n";
    return 0;
}