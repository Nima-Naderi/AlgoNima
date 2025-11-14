// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define Mp make_pair
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 3e5 + 10;
// This is the Solution to problem: Div2B. Brightness Begins
// https://codeforces.com/contest/2020/problem/B
bool check(ll x){
	ll t = sqrt(x), sq = t;
	for(ll i = max(0ll, t - 5); i <= t + 5; i ++){
		if(i * i <= x) sq = i;
	}
	return (x - sq >= k);
}
void solve(){
	ll k; cin >> k;
	ll low = 0, high = 2e18;
	assert(check(high));
	while(high - low > 1){
		ll mid = (high + low) / 2;
		if(check(mid)) high = mid;
		else low = mid;
	}
	cout << high << '\n';
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);	
	ll tq = 1;
	cin >> tq;
	while(tq --) solve();
	return 0;
}
//! N.N
