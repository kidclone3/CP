#include <bits/stdc++.h>
using namespace std;

bool detectCapitalUse(string word)
{
    int count = 0;
    for (auto i : word)
    {
        if (isupper(i))
            count++;
    }
    if (isupper(word[0]) && count == 1)
        return true;
    if (count == word.size() || count == 0)
        return true;
    else
        return false;
}

int main()
{
    string word;
    cout << "Enter a word: ";
    cin >> word;
    cout << "Does this word capital?\n";
    if (detectCapitalUse(word))
        cout << "yes";
    else
        cout << "No";
    return 0;
}