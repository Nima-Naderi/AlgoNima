///In the name of GOD
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#define lc (id * 2)
//#define rc (id * 2 + 1)
#define md ((s + e) / 2)
#define dm ((s + e) / 2 + 1)
#define ln (e - s + 1)
using namespace std;

typedef long long ll;
const ll MXN = 1e5 + 10;
const ll LOG = 17;
const ll MXS = MXN * 4 * LOG;
struct DATA{
    int ans, pre, suf, sz;
    DATA(){
        ans = pre = suf = sz = 0;
    }
};
DATA Merge(const DATA& a, const DATA& b){
    DATA c; c.sz = a.sz + b.sz;
    c.ans = max(a.ans, b.ans);
    c.ans = max(c.ans, a.suf + b.pre);
    if(a.pre == a.sz) c.pre = a.sz + b.pre;
    else              c.pre = a.pre;
    if(b.suf == b.sz) c.suf = a.suf + b.sz;
    else              c.suf = b.suf;
    return c;
}
ll n, q, ts, ort;
ll A[MXN], Root[MXN];
int LC[MXS], RC[MXS];
DATA seg[MXS];
vector<ll> vec[MXN], Num;
ll New(ll id){
    ll nd = ++ ts;
    LC[nd] = LC[id], RC[nd] = RC[id], seg[nd] = seg[id];
    return nd;
}
ll Build(ll s = 1, ll e = n){
    ll nd = New(0);
    if(ln == 1){
        seg[nd].sz = 1; return nd;
    }
    LC[nd] = Build(s, md), RC[nd] = Build(dm, e);
    seg[nd] = Merge(seg[LC[nd]], seg[RC[nd]]);
    return nd;
}
ll Upd(ll p, ll id = ort, ll s = 1, ll e = n){
    ll nd = New(id);
    if(ln == 1){
        seg[nd].pre = seg[nd].suf = seg[nd].ans = 1;
        return nd;
    }
    if(p <= md) LC[nd] = Upd(p, LC[id], s, md);
    else        RC[nd] = Upd(p, RC[id], dm, e);
    seg[nd] = Merge(seg[LC[nd]], seg[RC[nd]]);
    return nd;
}
DATA Get(ll l, ll r, ll id, ll s = 1, ll e = n){
    if(l <= s && e <= r) return seg[id];
    if(r <= md) return Get(l, r, LC[id], s, md);
    if(l >= dm) return Get(l, r, RC[id], dm, e);
    return Merge(Get(l, r, LC[id], s, md), Get(l, r, RC[id], dm, e));
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> A[i], Num.push_back(A[i]);
    sort(Num.begin(), Num.end());
    Num.resize(unique(Num.begin(), Num.end()) - Num.begin());
    for(int i = 1; i <= n; i ++) A[i] = lower_bound(Num.begin(), Num.end(), A[i]) - Num.begin() + 1;
    for(int i = 1; i <= n; i ++) vec[A[i]].push_back(i);
    ort = Root[n + 1] = Build();
    for(int i = n; i; i --){
        for(auto X : vec[i]) ort = Upd(X);
        Root[i] = ort;
    }
    cin >> q;
    while(q --){
        ll l, r, k; cin >> l >> r >> k;
        ll low = 1, up = n + 1;
        while(up - low > 1){
            ll mid = (low + up) / 2;
            if(Get(l, r, Root[mid]).ans >= k) low = mid;
            else               up = mid;
        }
        cout << Num[low - 1] << '\n';
    }
    //TODO: to clean here
    return 0;
}
//! N.N
