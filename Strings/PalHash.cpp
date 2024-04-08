// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MXN = 2e5 + 10;
const ll MXH = 2;
const ll Mod[MXH] = {(ll)(1e9 + 7), (ll)(1e9 + 9)};
const ll BASE = 257;
void mkay(int th, ll &x){
	if(x > Mod[th]){
		x -= Mod[th];
	}
}

//! Length is important in RH!
ll n;
string s;

ll pw[MXH][MXN], H[MXH][MXN], RH[MXH][MXN];
//RH: ith suffix Hash, i <-> n - i + 1
void InitPow(){
	for(int th = 0; th < MXH; th ++){
		pw[th][0] = 1;
		for(int i = 1; i < MXN; i ++) pw[th][i] = pw[th][i - 1] * BASE % Mod[th];
	}
}
void InitHash(){
	assert(s[0] == '$' && s.size() == n + 1);
	for(int th = 0; th < MXH; th ++){
		H[th][0] = RH[th][0] = 0;
		for(int i = 1; i <= n; i ++){
			H[th][i] = (H[th][i - 1] * BASE + (s[i] - 'a' + 1)) % Mod[th];
			RH[th][i] = (RH[th][i - 1] * BASE + (s[n - i + 1] - 'a' + 1)) % Mod[th];
		}
	}
}
inline ll Hash(int th, ll l, ll r){
	return (H[th][r] - H[th][l - 1] * pw[th][r - l + 1] % Mod[th] + Mod[th]) % Mod[th];
}
inline ll RHash(int th, ll l, ll r){
	// H(l, r) -> H[l] - H[r + 1] * pw[len]
	return (RH[th][n - l + 1] - RH[th][n - (r + 1) + 1] * pw[th][r - l + 1] % Mod[th] + Mod[th]) % Mod[th];
}
inline ll IsPal(ll l, ll r){
	for(int th = 0; th < MXH; th ++)
		if(Hash(th, l, r) != RHash(th, l, r))
			return 0;
	return 1;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);	
	n = 5; s = "$ninia";
	InitPow(), InitHash();
	

	return 0;
}
//! N.N
