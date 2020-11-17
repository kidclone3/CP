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

int q, opt;
ll val;
map<ll, ll> a, dd;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input_fre.txt", "r", stdin);
    freopen("FREQUENCY.INP", "r", stdin);
    freopen("FREQUENCY.OUT", "w", stdout);
    cin >> q;
    FOR(i, 1, q+1){
        cin >> opt >> val;
        if(opt==1){
            dd[a[val]]--;
            a[val]++;
            dd[a[val]]++;
        }else if(opt==2){
            dd[a[val]]--;
            a[val]--;
            if(a[val] < 0)
                a[val] = 0;
            dd[a[val]]++;
        }else{
            if(dd[val]>0){
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
