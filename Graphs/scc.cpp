//#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MXN = 1e6 + 10;
ll n, m, comp_cnt;
ll Comp[MXN];
vector<ll> adj[MXN], adt[MXN], Top;
bool mark[MXN];
void dfs(ll u){
    mark[u] = 1;
    for(auto v : adj[u]){
        if(!mark[v]) dfs(v);
    }
    Top.push_back(u);
}
void sfd(ll u){
    mark[u] = 1, Comp[u] = comp_cnt;
    for(auto v : adt[u]){
        if(!mark[v]) sfd(v);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i ++){
        ll u, v; cin >> u >> v; // directed edge
        adj[u].push_back(v), adt[v].push_back(u);
    }

    for(int i = 1; i <= n; i ++) if(!mark[i]) dfs(i);
    reverse(Top.begin(), Top.end()), fill(mark, mark + n + 1, 0);
    for(auto u : Top) if(!mark[u]) comp_cnt ++, sfd(u);

    return 0;
}
//! N.N