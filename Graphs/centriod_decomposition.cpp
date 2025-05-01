///In the name of GOD
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

typedef long long ll;
const ll MXN = 1e5 + 10;
ll n, Mod, ans, phi;
ll sub[MXN], ipw[MXN], pw[MXN];
ll dis[MXN], Val[MXN];
vector<pair<ll, ll>> adj[MXN];
bool hide[MXN];
unordered_map<int, int> Cnt;
ll power(ll a, ll b){
    return (!b ? 1 : power(a * a % Mod, b / 2) * (b & 1LL ? a : 1) % Mod);
}
void plant(ll u, ll par){
    sub[u] = 1;
    for(auto Pr : adj[u]){
        ll v = Pr.first;
        if(v != par && !hide[v]){
            plant(v, u), sub[u] += sub[v];
        }
    }
}
void Pre(ll u, ll par){
    if(par == -1) Val[u] = dis[u] = 0;
    for(auto Pr : adj[u]){
        ll v, w; tie(v, w) = Pr;
        if(v != par && !hide[v]){
            Val[v] = (Val[u] + pw[dis[u]] * w % Mod) % Mod;
            dis[v] = dis[u] + 1;
            Pre(v, u);
        }
    }
}
void Upd(ll u, ll par, ll dt){
    Cnt[Val[u]] += dt;
    for(auto Pr : adj[u]){
        ll v = Pr.first;
        if(v != par && !hide[v]) Upd(v, u, dt);
    }
}
void Calc(ll u, ll par, ll now){
    ll goal = Mod - (now * ipw[dis[u]] % Mod);
    if(goal == Mod) goal = 0;
    if(Cnt.count(goal)) ans += Cnt[goal];
    for(auto Pr : adj[u]){
        ll v, w; tie(v, w) = Pr;
        if(v != par && !hide[v]){
            Calc(v, u, (now * 10ll % Mod + w) % Mod);
        }
    }
}
ll CRD(ll u, ll par, ll val){
    for(auto Pr : adj[u]){
        ll v = Pr.first;
        if(v == par || hide[v]) continue;
        if(sub[v] >= val) return CRD(v, u, val);
    }
    return u;
}
void DMS(ll u, ll h){
    plant(u, -1);
    ll cent = CRD(u, -1, (sub[u] + 1) / 2); //attention
    Pre(cent, -1), Upd(cent, -1, 1);
    for(auto Pr : adj[cent]){
        ll v, w; tie(v, w) = Pr;
        if(hide[v]) continue;
        Upd(v, cent, -1);
        Calc(v, cent, w);
        Upd(v, cent, +1);
    }
    Cnt[Val[cent]] --;
    ans += Cnt[0];
    Cnt.clear();
    hide[cent] = 1;
    for(auto Pr : adj[cent]){
        ll v = Pr.first;
        if(!hide[v]) DMS(v, h + 1);
    }
}
void init(){ // TODO: copy phi inverse in Combinatrocis directory
    ll p = 2, m = Mod; phi = m;
    while(p * p <= m){
        if(m % p == 0){
            while(m % p == 0) m /= p;
            phi -= phi / p;
        }
        p ++;
    }
    if(m > 1) phi -= phi / m;
    ipw[0] = pw[0] = 1;
    ipw[1] = power(10, phi - 1);
    for(int i = 2; i < MXN; i ++) ipw[i] = ipw[i - 1] * ipw[1] % Mod;
    for(int i = 1; i < MXN; i ++) pw[i] = pw[i - 1] * 10ll % Mod;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin >> n >> Mod, init();
    for(int i = 1; i < n; i ++){
        ll u, v, w; cin >> u >> v >> w; u ++, v ++;
        adj[u].push_back({v, w}), adj[v].push_back({u, w});
    }
    DMS(1, 0);
    cout << ans << '\n';

    // CF: 715C
    return 0;
}