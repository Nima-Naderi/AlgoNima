//#pragma GCC optimize("O2")
#include<bits/stdc++.h>
#define lc (id * 2)
#define rc (id * 2 + 1)
#define md ((s + e) / 2)
#define dm ((s + e) / 2 + 1)
#define ln (e - s + 1)
using namespace std;

typedef long long ll;
const ll MXN = 1e5 + 10;
const ll MXS = MXN * 4;
const ll MXK = MXN + MXS * 2; // total number of vertices
const ll INF = 1e18;
ll n, q, src, cntr;
ll Id[2][MXS], dis[MXK];
vector<pair<ll, ll>> adj[MXK];
bool vis[MXK];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

inline void Ins(ll typ, ll u, ll v, ll w){ //0 : out-tree 1 : in-tree
    if(typ) swap(u, v);
    adj[u].push_back({v, w});
}
void Build(ll typ, ll id = 1, ll s = 1, ll e = n){
    Id[typ][id] = cntr ++;
    if(ln == 1){
        Ins(typ, Id[typ][id], s, 0); return;
    }
    Build(typ, lc, s, md), Build(typ, rc, dm, e);
    Ins(typ, Id[typ][id], Id[typ][lc], 0);
    Ins(typ, Id[typ][id], Id[typ][rc], 0);
}
void Add(ll typ, ll l, ll r, ll u, ll w, ll id = 1, ll s = 1, ll e = n){
    if(e < l || s > r) return;
    if(l <= s && e <= r){
        Ins(typ, u, Id[typ][id], w);
        return;
    }
    Add(typ, l, r, u, w, lc, s, md);
    Add(typ, l, r, u, w, rc, dm, e);
}

void BFS(ll src){
    for(int i = 1; i < MXK; i ++) dis[i] = INF, vis[i] = 0;
    pq.push({0, src}), dis[src] = 0;
    while(!pq.empty()){
        ll u, d; tie(d, u) = pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto Pr : adj[u]){
            ll v, w; tie(v, w) = Pr;
            if(vis[v]) continue;
            if(d + w < dis[v]){
                dis[v] = d + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin >> n >> q >> src;

    cntr = n + 1;
    Build(0), Build(1);

    while(q --){
        ll typ, u, v, w, l, r;
        cin >> typ;
        switch(typ){
            case 1 : cin >> u >> v >> w, Ins(0, u, v, w); break;
            case 2 : cin >> u >> l >> r >> w, Add(0, l, r, u, w); break;
            case 3 : cin >> u >> l >> r >> w, Add(1, l, r, u, w); break;
        }
    }

    assert(cntr < MXK);
    BFS(src);

    for(int i = 1; i <= n; i ++){ cout << (!vis[i] ? -1 : dis[i]) << ' '; } cout << '\n';
    //CF: 786B
    return 0;
}
//! N.N