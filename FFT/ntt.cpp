// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define Mp make_pair
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 2e5 + 10;
const ll LOG = 20;
const ll MXF = (1LL << LOG);
const ll Mod = 998244353;
ll power(ll a, ll b){
	return (!b ? 1 : power(a * a % Mod, b / 2) * (b & 1LL ? a : 1) % Mod);
}
ll inv(ll x){
	return power(x, Mod - 2);
}
void mkay(ll &x){
	if(x < 0) x += Mod;
	if(x >= Mod) x -= Mod;
}
ll rev[MXF];
const ll iMXF = inv(MXF);
void NTT(ll *A, bool inverse = 0){
	for(int i = 1; i < MXF; i ++){
		rev[i] = ((rev[i >> 1] >> 1) | ((i & 1) << (LOG - 1)));
		if(rev[i] < i) swap(A[i], A[rev[i]]);
	}
	for(int l = 1; l < MXF; l <<= 1){
		ll wn = power(3, Mod / 2 / l); // 3 or 5
		if(inverse) wn = inv(wn);
		for(int i = 0; i < MXF; i += (l << 1)){
			ll w = 1;
			for(int j = i; j < i + l; j ++){
				ll v = A[j], u = w * A[j + l] % Mod;
				mkay(A[j] = u + v);
				mkay(A[j + l] = v - u);
				w = w * wn % Mod;
			}
		}
	}
	if(!inverse) return;
	for(int i = 0; i < MXF; i ++) A[i] = A[i] * iMXF % Mod;
}

ll n, k, ans;
ll A[MXF]; // polynomial
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);	
	cin >> n >> k;
	for(int i = 1, x; i <= k; i ++){
		cin >> x; A[x] = 1;
	}
	NTT(A);

	return 0;
}
//! N.N
