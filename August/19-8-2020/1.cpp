#include <bits/stdc++.h>
using namespace std;

vector<string> allLongestStrings(vector<string> inputArray)
{
    int max{0};
    vector<string>res;
    for (auto it:inputArray)
        if (it.size()>max) max=it.size();
    for (auto it:inputArray)
        if (it.size()==max) res.push_back(it);
    return res; 
}
int main()
{
    vector <string> input, output;
    int n;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        string temp;
        cin>>temp;
        input.push_back(temp);
    }
    output=allLongestStrings(input);
    for (auto it:output)
    {cout<<it<<" ";}
    return 0;
}