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

int n, rs;
int a[105];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("EASYMTP.INP", "r", stdin);
    freopen("EASYMTP.OUT", "w", stdout);
    cin >> n;
    FOR(i, 1, n+1)
        cin >> a[i];
    sort(a+1, a+1+n);
    int zy = 0;
    FORd(i, 1, n+1){
        rs += max(0, a[i]-(zy++));
    }
    cout << rs;
    return 0;
}
