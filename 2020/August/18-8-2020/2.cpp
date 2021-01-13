#include <iostream>
#include <ctype.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (isupper(s[i]))
        {
            count++;
        }
    }
    cout << count;
}