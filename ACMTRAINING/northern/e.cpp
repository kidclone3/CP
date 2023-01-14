// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
long long x,y,i,p,q;
vector<int> V;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    V.clear();V.push_back(1);
    while(cin>>p >> q){
        x=0;
        if(V.size()>=2) for(i=0;i<=V.size()-2;i++) if(q*V[i]==p*V[i+1]){
            cout<<i<<"\n";
            x++;
            break;
        }
        if(x==0){
            while(true){
                y=V.size();
                if(y%2==1) V.push_back(V[(y-1)/2]);
                else V.push_back(V[y/2]+V[y/2-1]);
                if(q*V[y-1]==p*V[y]){
                    cout<<y-1<<"\n";
                    break;
                }
            }
        }
    }
}