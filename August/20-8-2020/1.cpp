#include <bits/stdc++.h>
using namespace std;

list<int> removeElements(list<int> linkedList, int n)
{
    for (auto it = linkedList.begin(); it != linkedList.end();)
        if (*it == n)
            it=linkedList.erase(it);
		else it++;
    return linkedList;
}

vector<int> verifyFunction(vector<int> v, int n) {
	list<int> l(v.begin(), v.end());
	l = removeElements(l, n);
	vector<int> vec(l.begin(), l.end());
	return vec;
}

int main()
{
    int n, x;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter vector: ";
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    cout << "Enter number you want to remove: ";
    cin >> x;
    vec = verifyFunction(vec, x);
    cout << "This is the vector after remove: ";
    for (auto it : vec)
        cout << it << " ";
    return 0;
}