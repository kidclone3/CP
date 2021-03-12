#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k);
int main()
{
    vector<int> nums = {1, 1, 1};
    int k = 2;
    cout << subarraySum(nums, k);
}
int subarraySum(vector<int> &nums, int k)
{
    int count = 0;
    vector<int> sum;
    sum.push_back(0);
    for (int i = 0; i < nums.size(); i++)
    {
        sum.push_back(sum[i] + nums[i]);
    }
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size() + 1; j++)
        {
            if (sum[j] - sum[i] == k)
            {
                count++;
            }
        }
    }
    return count;
}