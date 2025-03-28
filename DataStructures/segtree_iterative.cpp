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
class SegTree { // Mem O(n)
public:
	ll n = 0, null_val = 0;
    vector<ll> seg;
    SegTree(ll sz) {
        seg.assign(2 * sz, null_val);
        n = sz;  
    }   
    ll Merge(ll a, ll b){ return max(a, b); }
    void upd(ll pos, ll val){
		for(seg[pos += n] = val; pos /= 2; )
			seg[pos] = Merge(seg[2 * pos], seg[2 * pos + 1]);
    }
    ll query(ll l, ll r){ // [l, r]
        ll lans = null_val, rans = null_val;
        for(l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if(l & 1) lans = Merge(lans, seg[l ++]);
            if(r & 1) rans = Merge(seg[-- r], rans);
        }
        return Merge(lans, rans);
    }
}; 


int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin >> n >> q;
	SegTree seg(n + 5);
	for(int i = 1; i <= n; i ++) cin >> A[i], seg.upd(i, A[i]);
	while(q --){
		ll l, r; cin >> l >> r;
		cout << seg.query(l, r) << '\n';
	}
	return 0;
}
//! N.N