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
ll n, ts, ort; //Important!
ll Root[MXN]; //MXN refers to different time slots
DATA seg[MXS];
int LC[MXS], RC[MXS];
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
        /* update node part */
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
    
    //Build the base
    ort = Root[n + 1] = Build();

    vector<ll> Qry[MXN];
    for(int i = n; i; i --){
        //For query:
        for(auto X: Qry[i]) ort = Upd(X);

        //Save root at spesific times
        Root[i] = ort;
    }
    cin >> q;
    while(q --){
        ll l, r, k; cin >> l >> r >> k;

        // Solution: Binary search on the timeline
        ll low = 1, up = n + 1;
        while(up - low > 1){
            ll mid = (low + up) / 2;
            if(Get(l, r, Root[mid]).ans >= k) low = mid;
            else               up = mid;
        }

        //Idea: Somtimes Binary search on segment tree is possible
    }
    return 0;
}
//! N.N
