// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define Mp make_pair
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 2e5 + 10;
const ll INF = 1e9 + 10;
ll n, m;
ll Qq[MXN + MXN], dis[MXN];
vector<pll> adj[MXN];
vector<ll> BFS_Sources;
inline ll BFS01(ll src = 0, ll sink = 0){
    ll L = MXN, R = MXN;
    for(int i = 1; i <= n; i ++) dis[i] = INF;
	if(src){
		dis[src] = 0, Qq[R ++] = src;
	} else { //multi-source bfs
		for(auto u : BFS_Sources) dis[u] = 0, Qq[R ++] = u;
	}
	while(L != R){
		ll u = Q[L ++];
		if(u == sink) return dis[u];
		for(auto[v, w] : adj[u]){
			if(dis[v] == INF){
				dis[v] = dis[u] + w;
				if(w == 1) Qq[R ++] = v;
				else Q[-- L] = v, assert(L >= 0);
			}
		}
	}
	return -1;
}
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);	
	cin >> n >> m;
	for(int i = 1; i <= m; i ++){
		ll u, v, w; cin >> u >> v >> w;
		adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
	}
	ll k, x; cin >> k; while(k --) { cin >> x, BFS_Sources.push_back(x); }
	assert(BFS01() == -1);
	for(int i = 1; i <= n; i ++) cout << dis[i] << ' ';
	return 0;
}
//! N.N
