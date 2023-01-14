#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    // vector<int> a(n);
    int dem=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n-1;i++){
        int k=a[i];
        if(k==1) {
            if (a[i+1]==1) a[i+1]=0;
            if (a[i+1]==3) a[i+1]=2;
        }
        if(k==2) {
            if (a[i+1]==2) a[i+1]=0;
            if (a[i+1]==3) a[i+1]=1;
        }
        if(k==3){
            if(a[i+1]==1 || a[i+1]==2){
                if (a[i+2]==1) a[i+1]==2;
                if (a[i+2]==2) a[i+1]==1;
            }
        }
    }
    for (int i=0;i<n;i++){
        if (a[i]==0) dem++;
    }
    cout<<dem;
}