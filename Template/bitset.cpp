// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define Mp make_pair
#define MSB(x)  (63 - __builtin_clzll(ll(x)))
// __builtin_ctz(mask); __builtin_popcount(mask); /* ll for ll */
#define bit(x, b) ((x >> b) & 1)
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 2e5 + 10;
const ll Mod = 998244353;
const ll INF = 8e18;

bitset<MXN> bs;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	
	for(int i = bs._Find_first(); i < bs.size(); i = bs._Find_next(i)){
		cout << i << ' ';
	}
	cout << '\n';
	
	
	bs.set(); //set all to 1
	bs.reset(); //reset all to 0


	return 0;
}
//! N.N

