#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    // freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<pair<ll, ll>> a;
        for(int j=0;j<n;j++){
            int tmp;
            cin>>tmp;
            a.push_back({tmp,j});
        }
        sort(a.begin(),a.end());
        vector<pair<ll,ll>> b(n-1);
        ll s=0;
        for(int k=0;k<n-1;k++){
            s=s+a[k].first;
            b[k].first=s-a[k+1].first;
            b[k].second= a[k].second;
        }
        vector<int> c;
        for(int p=n-2;p>=0;p--){
            if(b[p].first>=0){
                c.push_back(b[p].second);
            }else{
                break;
            }
        }
        c.push_back(a[n-1].second);
        sort(c.begin(),c.end());
        cout<<c.size()<<endl;
        for(int m=0;m<c.size();m++){
            cout<<c[m]+1<<" ";
        }
        cout<<"\n";
    }
}