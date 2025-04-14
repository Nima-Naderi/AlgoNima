// #pragma GCC optimize("O2")
#include<bits/stdc++.h>
#define lc (id * 2)
#define rc (id * 2 + 1)
#define ln (e - s + 1)
#define md ((s + e) / 2)
#define dm ((s + e) / 2 + 1)
#define Mp make_pair
using namespace std;

typedef long long ll;
const ll MXN = 4e5 + 10;
const ll MXS = 4 * MXN;
const ll Mod = 1e9 + 7;
ll n, q;
ll A[MXN];
ll seg[MXS], Sum[MXS], Ted[MXS];
void Build(ll id = 1, ll s = 1, ll e = n){
    Sum[id] = Ted[id] = 0;
    if(ln == 1){
        seg[id] = A[s]; return;
    }
    Build(lc, s, md), Build(rc, dm, e);
    seg[id] = (seg[lc] + seg[rc]) % Mod;
}
inline ll f(ll x) { return (x * (x - 1) / 2) % Mod; }
void Shift(ll id, ll s, ll e){
    if(ln < 1) return;
    if(!Sum[id] && !Ted[id]) return;
    seg[id] += Sum[id] * ln + f(ln) * Ted[id];
    seg[id] %= Mod;
    if(ln > 1){
        Ted[lc] = (Ted[lc] + Ted[id]) % Mod;
        Ted[rc] = (Ted[rc] + Ted[id]) % Mod;
        Sum[lc] = (Sum[lc] + Sum[id]) % Mod;
        Sum[rc] = (Sum[rc] + Ted[id] * (dm - s) + Sum[id]) % Mod;
    }
    Ted[id] = Sum[id] = 0;
}
void Upd(ll l, ll r, ll id = 1, ll s = 1, ll e = n){
    Shift(id, s, e);
    if(e < l || s > r) return;
    if(l <= s && e <= r){
        Sum[id] += (s - l + 1); Sum[id] %= Mod;
        Ted[id] ++;
        Shift(id, s, e);
        return;
    }
    Upd(l, r, lc, s, md), Upd(l, r, rc, dm, e);
    seg[id] = (seg[lc] + seg[rc]) % Mod;
}
ll Get(ll l, ll r, ll id = 1, ll s = 1, ll e = n){
    Shift(id, s, e);
    if(e < l || s > r) return 0;
    if(l <= s && e <= r) return seg[id];
    return (Get(l, r, lc, s, md) + Get(l, r, rc, dm, e)) % Mod;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) cin >> A[i];
    Build();
    while(q --){
        string s; ll l, r;
        cin >> s >> l >> r;
        if(s == "ask")  cout << (Get(l, r) + Mod) % Mod << '\n';
        else            Upd(l, r);
    }
    return 0;
}