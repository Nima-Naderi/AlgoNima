// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define lc (id * 2)
#define rc (id * 2 + 1)
#define ln (e - s + 1)
#define md ((s + e) / 2)
#define dm ((s + e) / 2 + 1)
#define Mp make_pair
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 2e5 + 10;
const ll MXS = MXN * 4 + 10;
const ll INF = 1e9 + 10;
ll n, q;
ll A[MXN];
ll seg[MXS], Max[MXS], Min[MXS];
ll lazySet[MXS], lz[MXS];
void Build(ll id = 1, ll s = 1, ll e = n){
	lazySet[id] = -INF, lz[id] = 0;
	if(ln == 1){
		Max[id] = Min[id] = seg[id] = A[s]; return;
	}
	Build(lc, s, md), Build(rc, dm, e);
	seg[id] = seg[lc] + seg[rc];
	Max[id] = max(Max[lc], Max[rc]), Min[id] = min(Min[lc], Min[rc]);
}
void Shift(ll id = 1, ll s = 1, ll e = n){
	if(lazySet[id] != -INF){
		seg[id] = lazySet[id] * ln;
		Min[id] = Max[id] = lazySet[id];
		if(ln > 1){
			lazySet[lc] = lazySet[rc] = lazySet[id];
			lz[lc] = lz[rc] = 0;
		}
		lazySet[id] = -INF;
	}
	if(lz[id]){
		seg[id] += lz[id] * ln;
		Min[id] += lz[id], Max[id] += lz[id];
		if(ln > 1){
			lz[lc] += lz[id];
			lz[rc] += lz[id];
		}
		lz[id] = 0;
	}
}
void Set(ll l, ll r, ll x, ll id = 1, ll s = 1, ll e = n){
	Shift(id, s, e);
	if(e < l || s > r) return;
	if(l <= s && e <= r && Max[id] == Min[id]){ //important! All the numbers are the same
		lazySet[id] = x;
		Shift(id, s, e);
		return;
	}
	Set(l, r, x, lc, s, md), Set(l, r, x, rc, dm, e);
	seg[id] = seg[lc] + seg[rc];
	Max[id] = max(Max[lc], Max[rc]), Min[id] = min(Min[lc], Min[rc]);
}
void Upd(ll l, ll r, ll x, ll id = 1, ll s = 1, ll e = n){
	Shift(id, s, e);
	if(e < l || s > r) return;
	if(l <= s && e <= r){
		lz[id] = x;
		Shift(id, s, e);
		return;
	}
	Upd(l, r, x, lc, s, md), Upd(l, r, x, rc, dm, e);
	seg[id] = seg[lc] + seg[rc];
	Max[id] = max(Max[lc], Max[rc]), Min[id] = min(Min[lc], Min[rc]);
}
ll Get(ll l, ll r, ll id = 1, ll s = 1, ll e = n){
	Shift(id, s, e);
	if(e < l || s > r) return 0;
	if(l <= s && e <= r) return seg[id];
	return Get(l, r, lc, s, md) + Get(l, r, rc, dm, e);
}
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i ++) cin >> A[i];
	Build();
    //Seg: set to something
    //Upd: change += x the interval
    //Get: get sum of an interval
	return 0;
}
//! N.N