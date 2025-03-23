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
const ll INF = 1e16;
ll n, m, q, timer; //important
ll Par[MXN], dis[MXN], sub[MXN], hvs[MXN];
ll hd[MXN], Tree[MXN], Stm[MXN], Ftm[MXN];

pair<ll, ll> seg[MXS], Now;
ll Lazy[MXS], SigLz[MXS];

vector<ll> adj[MXN], ANS;
vector<pair<ll, ll>> Cnd[MXN];

// ===== CREATE HLD =====
void prep(ll u, ll par){
    sub[u] ++, Par[u] = par;
    for(auto v : adj[u]){
        if(v == par) continue;
        dis[v] = dis[u] + 1;
        prep(v, u);
        sub[u] += sub[v];
        if(sub[v] > sub[hvs[u]]) hvs[u] = v;
    }
}
void dfs(ll u, ll par, ll head){
    Stm[u] = ++ timer, Tree[timer] = u;
    hd[u] = head;
    if(hvs[u]) dfs(hvs[u], u, head);
    for(auto v : adj[u]){
        if(v == par || v == hvs[u]) continue;
        dfs(v, u, v);
    }
    Ftm[u] = timer;
}

// ===== SEGMENT TREE =====
void Build(ll id = 1, ll s = 1, ll e = n){
    if(ln == 1){
        seg[id].first = Cnd[Tree[s]].back().first;
        seg[id].second = s;
        return;
    }
    Build(lc, s, md), Build(rc, dm, e);
    seg[id] = min(seg[lc], seg[rc]);
}
void Shift(ll id, ll s, ll e){
    if(!Lazy[id]) return;
    seg[id].first += Lazy[id];
    if(ln > 1){
        Lazy[lc] += Lazy[id], Lazy[rc] += Lazy[id];
    }
    SigLz[id] += Lazy[id];
    Lazy[id] = 0;
    return;
}
void Upd(ll l, ll r, ll x, ll id = 1, ll s = 1, ll e = n){
    Shift(id, s, e);
    if(e < l || s > r) return;
    if(l <= s && e <= r){
        Lazy[id] = x; Shift(id, s, e);
        return;
    }
    Upd(l, r, x, lc, s, md), Upd(l, r, x, rc, dm, e);
    seg[id] = min(seg[lc], seg[rc]);
}
void Set(ll ind, ll id = 1, ll s = 1, ll e = n){
    Shift(id, s, e);
    if(ind < s || ind > e) return;
    if(ln == 1){
        Cnd[Tree[s]].pop_back();
        seg[id].first = Cnd[Tree[s]].back().first + SigLz[id];
        seg[id].second = s;
        return;
    }
    Set(ind, lc, s, md), Set(ind, rc, dm, e);
    seg[id] = min(seg[lc], seg[rc]);
}
void fetch(ll l, ll r, ll id = 1, ll s = 1, ll e = n){
    Shift(id, s, e);
    if(e < l || s > r) return;
    if(l <= s && e <= r){
        Now = min(Now, seg[id]); return;
    }
    fetch(l, r, lc, s, md), fetch(l, r, rc, dm, e);
    seg[id] = min(seg[lc], seg[rc]);//opt?
}

// ===== HLD Query =====
void Qry(ll u, ll v){ //u is Jad v
    while(hd[v] != hd[u]){
        fetch(Stm[hd[v]], Stm[v]);
        v = Par[hd[v]];
    }
    fetch(Stm[u], Stm[v]);
}

// ===== LCA with HLD =====
ll LCA(ll u, ll v){
    while(hd[u] != hd[v]){
        if(dis[hd[u]] > dis[hd[v]]) swap(u, v);
        v = Par[hd[v]];
    }
    if(dis[u] > dis[v]) swap(u, v);
    return u;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for(int i = 1; i < n; i ++){ ll u, v; cin >> u >> v; adj[u].push_back(v), adj[v].push_back(u); }
    for(int i = 1; i <= n; i ++) Cnd[i].push_back({INF, INF});
    for(int i = 1, x; i <= m; i ++){ cin >> x, Cnd[x].push_back({i, i}); }
    for(int i = 1; i <= n; i ++){ sort(Cnd[i].begin(), Cnd[i].end(), greater<pair<ll, ll>>());}

    // Build HLD + Segment Tree
    prep(1, 0);
    dfs(1, 0, 1);
    Build();

    while(q --){
        ll typ, u, v, k, l, r, lca; cin >> typ;
        if(typ == 2){
            cin >> u >> k;
            Upd(Stm[u], Ftm[u], k);
            continue;
        }
        cin >> u >> v >> k;
        lca = LCA(u, v), ANS.clear();
        while(k --){
            Now = {INF, INF};
            Qry(lca, u);
            Qry(lca, v);
            if(Now.first > 2e14) break;
            ANS.push_back(Cnd[Tree[Now.second]].back().second);
            Set(Now.second);
        }
        cout << int(ANS.size()) << ' ';
        for(auto X : ANS) cout << X << ' ';
        cout << '\n';
    }

    // CF: 696E
    return 0;
}
//! N.N