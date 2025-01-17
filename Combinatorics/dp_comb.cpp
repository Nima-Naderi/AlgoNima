// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MXN = 500 + 10;
const ll Mod = 998244353;
void mkay(ll &x){
	if(x < 0) x += Mod;
	if(x >= Mod) x -= Mod;
}
ll C[MXN][MXN];
inline void Init(){
	C[0][0] = 1;
	for(int n = 1; n < MXN; ++ n){
		C[n][0] = C[n][n] = 1;
		for(int k = 1; k < n; ++ k){
			C[n][k] = C[n - 1][k] + C[n - 1][k - 1];
			mkay(C[n][k]);
		}
	}
}
inline ll ncr(ll n, ll r){
	if(r < 0 || r > n) return 0;
	return C[n][r];
}

//Fact: nCrr(n, r1, .., rk): r1,..,rk should partition bits of n
inline ll nCrMod2(ll n, ll r){
	if(r < 0 || r > n) return 0;
	return ((n & r) == r);
}

//Stirling number of the second kind
//- Number of ways to partition n elements array into p non-empty subsequences
ll S[MXN][MXN];
inline void InitS2(){
	for(int i = 1; i < MXN; i ++){
		S[i][1] = 1;
		for(int j = 2; j <= i; j ++){
			S[i][j] = S[i - 1][j] * j + S[i - 1][j - 1];
			mkay(S[i][j]);
		}
	}
}
inline ll Stirling2(ll n, ll k){
	if(k < 0 || k > n) return 0;
	if(n == 0 && k == 0) return 1; //!
	if(k == 0) return 1;
	return S[n][k];
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	Init();

	return 0;
}
//! N.N
