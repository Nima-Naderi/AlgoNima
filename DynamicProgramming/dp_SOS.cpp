// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define Mp make_pair
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 20 + 10;
const ll MXM = (1LL << MXN) + 10;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);	
	
	// N * 2^N
	for(int j = 0; j < MXN; j ++){
        for(int mask = 0; mask < MXM; mask ++){
            if(((mask >> j) & 1LL)) dp[mask ^ (1 << j)] += dp[mask];
        }
    }
	//TODO: Sum ove subsets or supersets?
	//TODO: 3^n implementation

	return 0;
}
//! N.N
