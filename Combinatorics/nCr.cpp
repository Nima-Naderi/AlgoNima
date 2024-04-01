// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MXN = 2e5 + 10;
const ll Mod = 998244353;
ll power(ll a, ll b){
	return (!b ? 1 : power(a * a % Mod, b / 2) * (b & 1LL ? a : 1) % Mod);
}
ll inv(ll x){
	return power(x, Mod - 2);
}
void mkay(ll &x){
	if(x >= Mod) x -= Mod;
}
ll F[MXN], I[MXN];
ll nCr(ll n, ll r){
	if(r < 0 || r > n) return 0;
	return F[n] * I[r] % Mod * I[n - r] % Mod;
}
inline void Init(){
	F[0] = I[0] = 1;
	for(int i = 1; i < MXN; i ++) F[i] = F[i - 1] * i % Mod;
	I[MXN - 1] = inv(F[MXN - 1]);
	for(int i = MXN - 2; i; -- i) I[i] = I[i + 1] * (i + 1) % Mod;
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	Init();

	return 0;
}
//! N.N
