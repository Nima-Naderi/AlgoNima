// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define Mp make_pair
#define MSB(x)  (63 - __builtin_clzll(ll(x)))
#define bit(x, b) ((x >> b) & 1)
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 2e5 + 10;
const ll Mod = 998244353;
const ll LOG = 32;
const ll MXT = 2e5 * 32 + 10; // Total nodes in graph
ll n, k;
ll A[MXN];
void solve(){
	cin >> n >> k; //k: the least xor result
	for(int i = 1; i <= n; i ++) cin >> A[i];

    // Finding the minimum interval with pair xor >= k
    ll l = 1, r = 0, Ans = n + 1;
	for(int i = 1; i <= n; i ++){
		while(r < i) Upd(A[++ r], +1);
		while(l < i) Upd(A[l ++], -1);
		while(ans == 0 && r + 1 <= n) Upd(A[++ r], +1);
        if(ans > 0) Ans = min(Ans, r - i + 1);
	}
	cout << (Ans == n + 1 ? -1 : Ans) << '\n';
}
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	ll tq = 1;
	cin >> tq;
	while(tq --) solve();
	return 0;
}
//! N.N
