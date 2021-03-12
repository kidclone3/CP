#include <bits/stdc++.h>
using namespace std;

vector<bool> tick;
vector<int> digits;
set<int> store;
int tmp = 0;

bool checkLength(int tmp, int s);
void solve(int s);
bool reorderedPowerOf2(int N);

int main()
{
    int n = 635824465;
    //reorderedPowerOf2(n);
    cout << reorderedPowerOf2(n);
}

bool checkLength(int tmp, int s)
{
    stringstream ss;
    ss << tmp;
    string tmp_s = ss.str();
    return tmp_s.size() == s;
}

void solve(int s)
{
    if (checkLength(tmp, s))
    {
        store.insert(tmp);
        return;
    }

    for (int i = 0; i < s; i++)
    {
        if (tick[i])
        {
            tmp *= 10;
            tmp += digits[i];
            tick[i] = 0;
            solve(s);
            tmp /= 10;
            tick[i] = 1;
        }
    }
}

bool reorderedPowerOf2(int N)
{
    if (N == 1)
        return 1;
    int nn = N;
    int s; //size of digits.
    while (nn > 0)
    {
        digits.push_back(nn % 10);
        nn /= 10;
    }
    s = digits.size();
    tick.resize(s, 1);
    solve(s);
    for (auto it : store)
    {
        double l = log2(it);
        int ll = l;
        if (pow(2, l) == pow(2, ll))
        {
            return 1;
        }
    }
    return 0;
}
