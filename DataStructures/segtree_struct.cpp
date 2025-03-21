// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define lc (id * 2)
#define rc (id * 2 + 1)
#define md ((s + e) / 2)
#define dm ((s + e) / 2 + 1)
#define ln (e - s + 1)
#define Mp make_pair
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 2e5 + 10;
const ll MXS = MXN * 4;
struct Data {
	ll l, r;
	ll pre, suff, x;
	bool all;
};
ll n, q, A[MXN];
Data seg[MXS];
inline ll f(ll x){
	return 1ll * x * (x + 1) / 2;
}
inline Data Merge(Data L, Data R){
	Data res; res.r = R.r, res.l = L.l;
	if(L.all && R.all && A[L.r] <= A[R.l]){
		res.all = 1;
		res.pre = res.suff = res.r - res.l + 1;
		res.x = f(res.pre);
		return res;
	}
	res.all = 0;
	if(A[L.r] > A[R.l]){
		res.pre = L.pre, res.suff = R.suff;
		res.x = L.x + R.x;
	} else {
		if(L.all) res.pre = L.pre + R.pre;
		else res.pre = L.pre;
		if(R.all) res.suff = L.suff + R.suff;
		else res.suff = R.suff;
		res.x = L.x + R.x - f(L.suff) - f(R.pre) + f(L.suff + R.pre);
	}
	return res;
}
void Build(ll id = 1, ll s = 1, ll e = n){
	if(ln == 1){
		seg[id].l = seg[id].r = s;
		seg[id].pre = seg[id].suff = seg[id].all = 1;
		seg[id].x = f(1);
		return;
	}
	Build(lc, s, md), Build(rc, dm, e);
	seg[id] = Merge(seg[lc], seg[rc]);
}
void Upd(ll p, ll x, ll id = 1, ll s = 1, ll e = n){
	if(p < s || p > e) return;
	if(ln == 1) return;
	Upd(p, x, lc, s, md), Upd(p, x, rc, dm, e);
	seg[id] = Merge(seg[lc], seg[rc]);
}
Data Get(ll l, ll r, ll id = 1, ll s = 1, ll e = n){
	if(l <= s && e <= r) return seg[id];
	if(r <= md) return Get(l, r, lc, s, md);
	if(l >= dm) return Get(l, r, rc, dm, e);
	return Merge(Get(l, r, lc, s, md), Get(l, r, rc, dm, e));
}
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);	
	cin >> n >> q;
	for(int i = 1; i <= n; i ++) cin >> A[i];
	Build();
	while(q --){
		ll t, x, y; cin >> t >> x >> y;
		if(t == 1) A[x] = y, Upd(x, y);
		else cout << Get(x, y).x << '\n';
	}
    //CF 1567E
    //query asks: calculate how many non-decreasing subarrays exist within the subarray
	return 0;
}
//! N.N
