#include <bits/stdc++.h>
using namespace std;

void Print(vector<int> &Q);
void RecursiveQueen(vector<int> &Q, int r);

int main()
{
    freopen("out.txt", "w", stdout);
    int n = 20;
    vector<int> queen;
    queen.resize(n, 0);
    RecursiveQueen(queen, 0);
}

void Print(vector<int> &Q)
{
    for (auto it : Q)
        cout << it + 1 << " ";
    cout << '\n';
}
void RecursiveQueen(vector<int> &Q, int r)
{
    const int n = Q.size();
    if (r == n)
        Print(Q);
    else
    {
        for (int j = 0; j < n; j++)
        {
            bool legal = true;
            for (int i = 0; i < r; i++)
            {
                if ((Q[i] == j) || (Q[i] == j + r - i) || (Q[i] == j - r + i))
                {
                    legal = false;
                    break;
                }
            }
            if (legal == true)
            {
                Q[r] = j;
                RecursiveQueen(Q, r + 1);
            }
        }
    }
}