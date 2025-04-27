// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define Mp make_pair
#define MSB(x)  (63 - __builtin_clzll(ll(x)))
#define bit(x, b) ((x >> b) & 1)
#define kill { cout << "-1\n"; return; }
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 2e5 + 10;
const ll Mod = 998244353;
tuple<ll, ll, ll> extended_gcd(ll a, ll b){
	if(b == 0) return {a, 1, 0};
	auto [gcd, x1, y1] = extended_gcd(b, a % b);
	return {gcd, y1, x1 - (a / b) * y1};
}
ll inv(ll x, ll Mod){
	auto [g, ix, _] = extended_gcd(x, Mod);
	if (g != 1) return 0;
	return (ix % Mod + Mod) % Mod;
}
inline pll reduce(ll x, ll y){
	ll g = gcd(x, y);
	return Mp(x / g, y / g);
}
ll CRT(ll r1, ll r2, ll m1, ll m2){
	ll d = gcd(m1, m2);
	if(r1 % d != r2 % d) return -1;
	m1 /= d, m2 /= d;

	ll delta = (r2 - r1) / d;
	delta = (delta % m2 + m2) % m2;

	ll k = delta * inv(m1, m2) % m2;
	return r1 + m1 * d * k;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	
	return 0;
}
//! N.N
