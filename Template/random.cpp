// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define Mp make_pair
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 3e5 + 10;

//mt19937 rng(time(0));
//srand(time(0)); srand(time(NULL)); random_shuffle(A + 1, A + n + 1);
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//int uid(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }
// mt19937 mrand(19260817);
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(Rnd); }

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	for(int tof = 0; tof < 200; tof ++){
		shuffle(A + 1, A + n + 1, Rnd);
		//shuffle(nums.begin(), nums.end(), Rnd);
		
		if(check()){

		}
	}
	return 0;
}
//! N.N
