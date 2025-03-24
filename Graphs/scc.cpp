//#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MXN = 1e6 + 10;
ll n, k, x;
ll Comp[MXN], Cnt[MXN], dp[MXN];
vector<ll> adj[MXN], adt[MXN], G[MXN], V[MXN], Jad, Top;
bool mark[MXN], vis[MXN];

void dfs(ll u){
    mark[u] = 1;
    for(auto v : adj[u]){
        if(!mark[v]) dfs(v);
    }
    Top.push_back(u);
}
void sfd(ll u){
    vis[u] = 1, Comp[u] = x, Cnt[x] += (G[u].empty()), V[x].push_back(u);
    for(auto v : adt[u]){
        if(!vis[v]) sfd(v);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i ++){
        ll u, v; cin >> u >> v;
        adj[u].push_back(v), adt[v].push_back(u);
    }
    for(int i = 1; i <= n; i ++){
        if(!mark[i]) dfs(i);
    }
    reverse(Top.begin(), Top.end());
    for(auto u : Top){
        if(!vis[u]) sfd(u), x ++, dp[x - 1] = Cnt[x - 1];
    }
    for(int c = x - 1; c; c --){
        for(auto u : V[c]){
            for(auto v : adj[u]){
                if(Comp[v] != c) dp[c] = max(dp[c], Cnt[c] + dp[Comp[v]]);
            }
        }
    }
    cout << dp[Comp[1]] << '\n';
    return 0;
}
//! N.N