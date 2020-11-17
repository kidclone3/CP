#include <bits/stdc++.h>

/*std::vector<int> stickSpan(std::vector<int> arr)
{
    std::vector<int> res;
    res.push_back(1);
    int i;
    for (i = 1; i < arr.size(); i++)
    {
        bool check = true;
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[i] < arr[j])
            {
                res.push_back(i - j);
                check = false;
                break;
            }
        }
        if (check)
            res.push_back(i + 1);
    }
    return res;
}*/

std::vector<int> stickSpan(std::vector<int> arr)
{
    std::stack<int> st;
    std::vector<int> res;
    st.push(0);
    res.push_back(1);
    for (int i = 1; i < arr.size(); i++)
    {
        while (arr[i] > arr[st.top()])
        {
            st.pop();
            if (st.empty())
                break;
        }
        if (st.empty())
            res.push_back(i + 1);
        else
            res.push_back(i - st.top());
        st.push(i);
    }
    return res;
}

int main()
{
    std::vector<int> input = {10, 4, 5, 90, 120, 80};
    std::vector<int> output = stickSpan(input);
    for (auto it : output)
        std::cout << it << " ";
    return 0;
}