// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define Mp make_pair
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 3e5 + 10;

ll rand(ll l, ll r) {
    return l + rand() % (r - l + 1);
}

int32_t main(int argc, char* argv[]){
	//ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);	
	srand(atoi(argv[1]));
 	
	// number of vertices
	ll n = rand(2, 20); //!!! MAX HERE IS IMPORTANT!
    cout << n << '\n';
	
	// edges
	for(int i = 2; i <= n; i ++){
		// let's choose parent of node i
		ll p = rand(1, i - 1);
		cout << i << ' ' << p << '\n';
	}
	return 0;
}
//! N.N
