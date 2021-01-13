#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int solve(int m, int k, vector<pair<int,int>> inp)
{
    int arr[m+5][k+5]={0};
    // Y tuong qhd: Dung bien j chay tu 0 den k (max weight that the bag can have)
    // Neu j< gia tri cua do vat thi bo qua (vi tri hien tai = max{0,vi tri [i-1][j]})
    // Neu j>= gia tri cua do vat thi vi tri hien tai = max(vi tri [i-1][j], vi tri [i-1][j-can nang] + gia tri)
    // Duyet den cuoi cung la ra dc kqua max o vi tri [m-1][k];

    //inp.first = weight, inp.second= value;

    // Initialize first dp instance for first item.
    for (int j=0; j<=k; j++)
    {
        if (j<inp[0].first) arr[0][j]=0;
        else
        {
            arr[0][j]=inp[0].second;
        }
    }
    //Bay gio la bai toan quy hoach dong cho m-1 cai con lai.
    for (int i=1; i<m; i++)
    {
        for (int j=0; j<=k; j++)
        {
            if (j<inp[i].first){
                arr[i][j]=arr[i-1][j];
                }
            else{
                arr[i][j]=max(arr[i-1][j], arr[i-1][j-inp[i].first]+inp[i].second);
                }
        }
    }
    return arr[m-1][k];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("WACHOVIA.INP", "r", stdin);
    //freopen("WACHOVIA.OUT", "w", stdout);
    int n,k,m;
    cin>>n;
    while (n--)
    {
        cin>>k>>m;
        vector<pair<int,int>> inp;
        for (int i=0; i<m; i++)
        {
            int a,b;
            cin>>a>>b;
            inp.pb({a,b});
        }
        cout<<"Hey stupid robber, you can get "<<solve (m, k, inp)<<".\n";
    }
}
