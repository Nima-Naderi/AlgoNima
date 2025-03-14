// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 2e5 + 10;
const ll Mod = 998244353;

ll Ask(ll n){
	cout.flush();
	cout << "? " << n << '\n';
	cout.flush();
	ll res; cin >> res;
	cout.flush();
	return res;
}
/*
auto ask = [&] (ll n) -> ll {
	cout.flush(); cout << "? " << n << '\n'; cout.flush();
	int x; cin >> x; return x;
};
*/
void solve(){
	cout.flush(); cin >> n; cout.flush();
	
	cout.flush(); cout << ans << '\n'; cout.flush();
}
int32_t main(){
	//ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	ll tq = 1;
	cin >> tq;
	while(tq --) solve();
	return 0;
}
//! N.N
