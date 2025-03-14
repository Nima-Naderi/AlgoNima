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

// Compress
vector<ll> vec;
inline void Compress(){
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin() , vec.end()) - vec.begin());
}
inline int GetId(int x){
    return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	
	//! O(3 ^ k) iteration on submasks
	ll mask = 0b01010;
	for(int sub = mask; ; sub = (sub - 1) & mask){
		// Update
		if(sub == 0) break;
	}
	//! time /= 2 as we only iterate on 1 bits
	for(ll i = mask, b = i & -i; i; i -= b, b = i & -i){
		
		//cout << "mask: " << i << ' ' << "bit " << b << '\n';
	}
	for(ll i = mask; i; ){ ll p2 = (i & -i);
        cout << p2 << ' ';
        i = i - p2;
    }
	//Fact: i & -i = 2 ^ (least 1 bit)

	/*
	memcpy(A, B, sizeof A); //copy B into A
	strncpy(str2, str1, sizeof str2); // copy str1 into str2
	*/

	return 0;
}
//! N.N

