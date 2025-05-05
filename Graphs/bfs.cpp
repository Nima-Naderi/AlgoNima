// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define Mp make_pair
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 2e5 + 10;
const ll INF = 1e9 + 10;
ll n, m;
ll Qq[MXN], dis[MXN];
vector<ll> adj[MXN];
vector<ll> BFS_Sources;
inline ll BFS(ll src = 0, ll sink = 0){
    ll L = 0, R = 0;
    for(int i = 1; i <= n; i ++) dis[i] = INF;
	if(src){
		dis[src] = 0, Qq[R ++] = src;
	} else { //multi-source bfs
		for(auto u : BFS_Sources) dis[u] = 0, Qq[R ++] = u;
	}
	while(L != R){
		ll u = Q[L ++];
		if(u == sink) return dis[u];
		for(auto v : adj[u]){
			if(dis[v] == INF) dis[v] = dis[u] + 1, Qq[R ++] = v;
		}
	}
	return -1;
}
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);	
	cin >> n >> m;
	for(int i = 1; i <= m; i ++){
		ll u, v; cin >> u >> v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	ll k, x; cin >> k; while(k --) { cin >> x, BFS_Sources.push_back(x); }
	assert(BFS() == -1);
	for(int i = 1; i <= n; i ++) cout << dis[i] << ' ';
	return 0;
}
//! N.N
