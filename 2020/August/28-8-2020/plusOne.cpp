#include <bits/stdc++.h>
using namespace std;
string plusString(string nums)
{
    int i = nums.size() - 1;
    bool check = true;
    while (check)
    {
        if (nums[i] >= '0' && nums[i] < '9')
        {
            char temp = nums[i];
            temp++;
            string temp1 = "";
            temp1 += temp;
            nums.replace(i, 1, temp1);
            break;
        }
        else
        {
            nums.replace(i, 1, "0");
            if (i == 0)
            {
                nums = '1' + nums;
                break;
            }
            i--;
        }
    }
    return nums;
}
vector<int> plusOne(vector<int> &digits)
{
    string nums = "";
    for (auto i = digits.begin(); i != digits.end(); i++)
    {
        char temp = *i + 48;
        nums += temp;
    }
    nums = plusString(nums);
    vector<int> res;
    for (auto it : nums)
    {
        res.push_back((int)it - 48);
    }
    return res;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> test = nums;
    vector<int> res = plusOne(nums);
    for (auto it : test)
        cout << it << "";
    return 0;
}