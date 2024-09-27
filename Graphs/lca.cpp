#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define Mp make_pair
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 1e6 + 10;
const ll LOG = 20;
ll n;
vector<ll> adj[MXN];
ll Jad[LOG][MXN], dis[MXN];
void prep(ll u, ll par){
	Jad[0][u] = par;
	for(int i = 1; i < LOG; i ++){
		Jad[i][u] = Jad[i - 1][Jad[i - 1][u]];
	}
	for(auto v : adj[u]){
		if(v == par) continue;
		dis[v] = dis[u] + 1;
		dfs(v, u);
	}
}
ll K_Jad(ll u, ll k){
	for(int i = 0; i < LOG; i ++){
		if((k >> i) & 1LL) u = Jad[i][u];
	}
	return u;
}
ll LCA(ll u, ll v){
	if(dis[v] < dis[u]) swap(u, v);
	v = K_Jad(v, dis[v] - dis[u]);
	if(u == v) return u;
	for(int i = LOG - 1; ~i; i --){
		if(Jad[i][u] != Jad[i][v]) u = Jad[i][u], v = Jad[i][v];
	}
	return Jad[0][u];
}
inline ll Distance(ll u, ll v){
	return dis[u] + dis[v] - 2 * dis[LCA(u, v)];
}
void solve(){
	cin >> n, tim = 0;
	for(int i = 0; i <= n; i ++) adj[i].clear();
	for(int i = 1; i < n; i ++){
		ll u, v; cin >> u >> v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	dis[1] = 0, prep(1, 0);

}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	ll tq = 1;
	cin >> tq;
	while(tq --) solve();
	return 0;
}
//! N.N

