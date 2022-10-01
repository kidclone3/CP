#include<bits/stdc++.h>
using namespace std;

int a[2*100000+5];
int b[2*100000+5];
int main()
{
    int n; cin>>n;
    int Max=1;
    for(int i=1; i<=n; i++)
        {
        cin>>a[i];
        if(a[i]>a[i-1])
                {
                    b[i]=b[i-1]+1;
                    Max=max(Max,b[i]);
                }
                else
                {
                    b[i]=1;
                }
        cout<<b[i]<<" ";
        }
    cout<<"\n"<<Max;

}
