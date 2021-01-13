#include <bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int sums[n];
    sums[0] = 0;
    int sum = 0;
    int i = 1;
    for (auto it : nums)
    {
        sum += it;
        sums[i++] = sum;
    }
    int max = INT_MIN;
    for (auto i = 1; i <= nums.size(); i++)
    {
        for (int j = i; j <= n; j++)
        {
            int temp = sums[j] - sums[j - i];
            if (temp >= max)
                max = temp;
        }
    }
    return max;
}
int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Result is: " << maxSubArray(nums);
}