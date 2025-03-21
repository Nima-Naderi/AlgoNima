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
ll A[MXN], seg[MXS], Sum[MXS], Ted[MXS];
void Build(ll id = 1, ll s = 1, ll e = n){
    ll mid = (s + e) / 2;
    if(s >= e){
        seg[id] = A[s]; return;
    }
    Build(lc, s, mid), Build(rc, mid + 1, e);
    seg[id] = (seg[lc] + seg[rc]) % Mod;
}
inline void Relax(ll id, ll s, ll e){
    ll len = (e - s + 1), mid = (s + e) / 2;
    if(len < 1) return;
    seg[id] = (seg[id] + ((((Sum[id] % Mod) * len % Mod) + (((len * (len - 1) / 2) % Mod) * Ted[id] % Mod)) % Mod)) % Mod;
    Ted[lc] = (Ted[lc] + Ted[id]) % Mod;
    Ted[rc] = (Ted[rc] + Ted[id]) % Mod;
    Sum[lc] = (Sum[lc] + Sum[id]) % Mod;
    Sum[rc] = (Sum[rc] + ((Ted[id] * (mid + 1 - s) % Mod + Sum[id]) % Mod)) % Mod;
    Ted[id] = Sum[id] = 0;
}
ll Get(ll l, ll r, ll id = 1, ll s = 1, ll e = n){
    ll mid = (s + e) / 2; Relax(id, s, e);
    if(l <= s && e <= r){
        return seg[id];
    }
    if(s >= e) return 0;
    ll ans = 0;
    if(l <= mid) ans = (ans + Get(l, r, lc, s, mid)) % Mod;
    if(r >  mid) ans = (ans + Get(l, r, rc, mid + 1, e)) % Mod;
    Relax(lc, s, mid), Relax(rc, mid + 1, e);
    seg[id] = (seg[lc] + seg[rc]) % Mod;
    return ans;
}
void Upd(ll l, ll r, ll id = 1, ll s = 1, ll e = n){
    ll mid = (s + e) / 2; Relax(id, s, e);
    if(l <= s && e <= r){
        Sum[id] += (s - l + 1), Sum[id] %= Mod, Ted[id] ++; Relax(id, s, e); return;
    }
    if(s >= e) return;
    if(l <= mid) Upd(l, r, id * 2, s, mid);
    if(r >  mid) Upd(l, r, id * 2 + 1, mid + 1, e);
    Relax(id * 2, s, mid), Relax(id * 2 + 1, mid + 1, e);
    seg[id] = (seg[id * 2] + seg[id * 2 + 1]) % Mod;
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