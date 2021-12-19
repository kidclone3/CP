// default headers
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <list>
#include <sstream>
#include <iomanip>

using namespace std;

// macros
#define FORST(X,S,T) for(int X=(S); X<=(T); X++)  
#define RFORST(X,S,T) for(int X=(S); X>=(T); X--)  
#define FOR(X,XB) for(int X=0; X<(XB); X++)
#define RFOR(X,XB) for(int X=(XB)-1; X>=0; X--)
#define FORSTL(X,C) for(X=C.begin();X!=C.end();X++)
#define RFORSTL(X,C) for(X=C.rbegin();X!=C.rend();X++)
#define SQR(X) ((X)*(X))
#define MID(X,Y) (((X)+(Y))/2)
#define MIN(X,Y) (X=min((X),(Y)))
#define MAX(X,Y) (X=max((X),(Y)))
#define FILL(X,V) memset(X,V,sizeof(X))
#define FILE_R(X) freopen(X, "r", stdin)
#define FILE_W(X) freopen(X, "w", stdout)  
#define ERREQ(X,Y) (fabs((X)-(Y))<EPS)
#define DBGL cout << "here" << endl;
#define INITLISTS {L=0; FILL(adj,-1);}
#define SZ(X) (int)sizeof(X)
const double PI = acos(-1.0);
const double EPS = 1E-9;
const int INF = (int)1E9;
typedef long long LL;
typedef vector<int> VI;

#define MAXN 100005

// the stuffs above are my contest template, used for speedup in contest :)
// ---------------------------------------------------------------------------
// actual solution below


// memo table that stores the decision we make for each car, -1 for "no solution" states
int pre[205][10005];

// dp table
bool dp[2][10005];	

// the length of each car, used to recover our solution from pre[][] matrix
int carlen[205];	

// the answer(decisions) for each car, 0:port  1:starboard
bool answer[205];	


int main(){


	int caseNum; 
	scanf("%d", &caseNum);			// get the number of cases

	FOR(caseId, caseNum){
		int L;
		scanf("%d", &L);			// get the length of the ferry
		L *= 100;					// centimeters from meters

		FILL(dp[0], false);			// initialize dp table to "no solution" state
		dp[0][0] = true;			// initially, 0 length at both sides is feasible
		FILL(pre, -1);				// solution memo is initialized to "no solution"

		bool done = false;			// are we done with this case?
		int i = 0;					// for enumerating car id
		int N = 0;					// how many cars we can load
		int sumlen = 0;				// sum of car length we've considered so far
		int t=0, pt;				// we use space saving trick here
		int lastlen = 0;			// record feasible length at port side for the last loaded car

		while(1){
			int curlen;
			scanf("%d", &curlen);	// get the current car length
			if(curlen==0) break;
			if(done==true) continue;

			// if we reach here, it means we are not done yet with this case

			pt = t; t ^= 1;			// swap dp table (space saving trick)
			carlen[++i] = curlen;	// increment car id, store the car length
			sumlen += curlen;		// add the length to the length sum

			FILL(dp[t], false);		// initialize a new row of dp table

			bool canload = false;				// can we load this car?

			FORST(len, 0, L){					// enumerate all the possible lengths at port side
				if(dp[pt][len]==false) continue;// there is no solution for this state, ignore
				
				// is it ok if we put the car on the port side?
				if(len+curlen<=L && sumlen-(len+curlen)<=L){  // port side ok && starboard side ok
					dp[t][len+curlen] = true;
					pre[i][len+curlen] = 0;	// record out decision, recall: 0 means we put the i-th car at port side
					lastlen = len+curlen;
					canload = true;
				}

				// is it ok if we put the car on the port side?
				if(sumlen-len<=L){			// starboard side ok (len<=L is trivial so we do not write it explicitly)
					dp[t][len] = true;
					pre[i][len] = 1;		// record out decision, recall: 1 means we put the i-th car at starboard side
					lastlen = len;
					canload = true;
				}
			}
			if(!canload) done = true;		// if we cannot load this car, we are done
			else N = i;						// store how many cars we have successfully loaded
		}

		printf("%d\n", N);					// print the number of cars we load
        printf("%d\n", lastlen);
		RFORST(i, N, 1){					// iterate reversely from the last car to the first
			if(pre[i][lastlen]==0){			// this car is loaded at port
				lastlen -= carlen[i];		// decrease the port side length
				answer[i] = 0;
			}else if(pre[i][lastlen]==1){	// this car is loaded at starboard
				answer[i] = 1;	
			}
		}

		FORST(i, 1, N){						// print the solutions
			if(answer[i]==0) puts("port");
			else if(answer[i]==1) puts("starboard");
		}
		if(caseId<caseNum-1) printf("\n");			// print an empty line between consecutive cases
	}
	return 0;
}