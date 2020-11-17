#include <bits/stdc++.h>
using namespace std;

#define VI vector<ll>
#define PB push_back
#define ll long long

ll solve(VI a, int au, int av);

int main(){
 int n, q;
 cin>>n>>q;
 VI a;
 vector<pair<int,int>> b;
 for(int i=0; i<n; i++){
 	int tmp;
 	cin>>tmp;
 	a.PB(tmp);
 }
 for (int i=0; i<q; i++){
 	int b1,b2;
 	cin>>b1>>b2;
 	b.PB({b1,b2});
 }	
 for (int i=0; i<q; i++){
 	cout<<solve(a,b[i].first, b[i].second)<<'\n';
 }
}

ll solve(VI a, int au, int av){
 VI p;
 p.PB(a[au-1]);
 for (int i=au; i<av; i++){
 	ll tmp;
 	tmp=p.back()+a[i];
 	p.PB(tmp);
 }
 ll res=LONG_LONG_MAX;
 ll last=p.back();
 p.pop_back();
 for (auto it:p){

 	res=min(res, abs(last-2*it));
 }
 return res;	 
}
