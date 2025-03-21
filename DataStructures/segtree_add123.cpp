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
void Relax(ll id, ll s, ll e){
    if(ln < 1) return;
    seg[id] = (seg[id] + ((((Sum[id] % Mod) * ln % Mod) + (((ln * (ln - 1) / 2) % Mod) * Ted[id] % Mod)) % Mod)) % Mod;
    Ted[lc] = (Ted[lc] + Ted[id]) % Mod;
    Ted[rc] = (Ted[rc] + Ted[id]) % Mod;
    Sum[lc] = (Sum[lc] + Sum[id]) % Mod;
    Sum[rc] = (Sum[rc] + ((Ted[id] * (dm - s) % Mod + Sum[id]) % Mod)) % Mod;
    Ted[id] = Sum[id] = 0;
}
ll Get(ll l, ll r, ll id = 1, ll s = 1, ll e = n){
    Relax(id, s, e);
    if(l <= s && e <= r){
        return seg[id];
    }
    if(s >= e) return 0;
    ll ans = 0;
    if(l <= md) ans = (ans + Get(l, r, lc, s, md)) % Mod;
    if(r >= dm) ans = (ans + Get(l, r, rc, dm, e)) % Mod;
    Relax(lc, s, md), Relax(rc, dm, e);
    seg[id] = (seg[lc] + seg[rc]) % Mod;
    return ans;
}
void Upd(ll l, ll r, ll id = 1, ll s = 1, ll e = n){
    Relax(id, s, e);
    if(l <= s && e <= r){
        Sum[id] += (s - l + 1), Sum[id] %= Mod, Ted[id] ++; Relax(id, s, e); return;
    }
    if(s >= e) return;
    if(l <= md) Upd(l, r, lc, s, md);
    if(r >= dm) Upd(l, r, rc, dm e);
    seg[id] = (seg[lc] + seg[rc]) % Mod;
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