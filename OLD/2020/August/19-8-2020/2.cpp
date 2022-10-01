#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> vector_test{1, 2, 3, 4, 5, 6};
    //vector_test.erase(vector_test.begin(), vector_test.end());
    vector_test.clear();
    for (auto it : vector_test)
        cout << it << " ";
    if (vector_test.empty())
        cout << "yes";
    return 0;
}