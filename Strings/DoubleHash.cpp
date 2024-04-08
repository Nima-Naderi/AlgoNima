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
ll pw[MXH][MXN], H[MXH][MXN];
void InitPow(){
	for(int th = 0; th < MXH; th ++){
		pw[th][0] = 1;
		for(int i = 1; i < MXN; i ++) pw[th][i] = pw[th][i - 1] * BASE % Mod[th];
	}
}
void InitHash(ll &n, string &s){
	assert(s[0] == '$' && s.size() == n + 1);
	for(int th = 0; th < MXH; th ++){
		H[th][0] = 0;
		for(int i = 1; i <= n; i ++){
			H[th][i] = H[th][i - 1] * BASE + (s[i] - 'a' + 1);
			mkay(th, H[th][i]);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);	
	ll n = 5; string s = "$ninia";
	InitPow(), InitHash(n, s);



	return 0;
}
//! N.N
