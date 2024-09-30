// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define Mp make_pair
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 2e5 + 10;
const ll INF = 1e9 + 10;
ll n, m;
ll dis[MXN];
vector<pll> adj[MXN];
priority_queue<pll, vector<pll>, greater<pll>> pq;
bool vis[MXN];
inline ll Dijk(ll src = 0, ll sink = 0){
	if(src){
		for(int i = 1; i <= n; i ++) dis[i] = INF, vis[i] = 0;
		pq.push(Mp(dis[src] = 0, src));
	} else {
		//multi-source dijkastra
		for(int u = 1; u <= n; u ++) pq.push(Mp(dis[u], u));
	}
	while(!pq.empty()){
		ll u, d; tie(d, u) = pq.top(); pq.pop();
		if(vis[u]) continue;
		if(u == sink) return d;
		vis[u] = 1;
		for(auto e : adj[u]){
			ll v, w; tie(v, w) = e;
			if(!vis[v] && d + w < dis[v]){
				pq.push(Mp(dis[v] = d + w, v));
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
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	for(int i = 1; i <= n; i ++) cin >> dis[i];
	assert(Dijk() == -1);
	for(int i = 1; i <= n; i ++) cout << dis[i] << ' ';
	return 0;
}
//! N.N
