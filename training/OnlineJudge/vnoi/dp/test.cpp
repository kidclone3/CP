#include<bits/stdc++.h>
using namespace std;
int main() {

	int maxcost[items+1][space+1];
	memset(maxcost, ???, sizeof(maxcost); // set to -inf
	maxcost[0][0] = 0; // set init state
	for(int i = 0; i < items; i++)        // iterations over all state.
		for(int j = 0; j <= space; j++) {
			int mc = maxcost[i][j];    // 
			int ni, nj, nmc;
			
			ni = i + 1;
			nj = j;
			nmc = mc;

			if (maxcost[ni][nj] < nmc) {
				maxcost[ni][nj] = nmc;
			}

			ni = i + 1;
			nj = j + size[i]; 			// add element i to the current state.
			nmc = mc + cost[i];
			if (nj <= space && maxcost[ni][nj] < nmc)
				maxcost[ni][nj] = nmc;
		}
	int answer = -1e9;
	for(int j = 0; j <= space; j++) 
		answer = max(answer, maxcost[items][j]);

}
