#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define ll long long

const int N = 2 * 100000 + 5;
int a[N], f[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, M = 0, head = 0;
    cin >> n;
    //Ki thuat: dung 1 mang de luu vi tri cuoi cung cua phan tu do
    //Dung 1 bien de luu gia tri ay ==> gia tri dau tien cho day tiep theo.

    map<int, int> last;
    for (int i = 1; i < n + 1; i++)
    {
        int a;
        cin >> a;
        //Kiem tra xem co the thay gia tri cua head = last[a] hay ko
        head = max(head, last[a]);
        M = max(M, i - head); // i- head = do dai xau khong trung o vi tri i
        last[a] = i;          // luu vi tri cuoi cung lai.
    }
    cout << M;
}