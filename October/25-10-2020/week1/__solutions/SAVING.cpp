#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define nMax 1000009

int n,m,q,l,r,x,a[nMax],d[nMax];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("SAVING/TEST001/SAVING.INP","r",stdin);
    //freopen("SAVING.INP", "r", stdin);
    //freopen("SAVING.OUT", "w", stdout);
	cin>>n>>m;
	FOR(i,1,m+1)
        cin>>l>>r, a[l]++, a[r+1]--;
	FOR(i,1,n+1)
        a[i]+=a[i-1];
    FOR(i,1,n+1)
        d[a[i]]++;
    FORd(i,1,n+1)
        d[i]+=d[i+1];
    cin >> q;
    FOR(i,1,q+1)
        cin >> x, cout << d[x] << endl;
    return 0;
}
