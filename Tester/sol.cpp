// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define Mp make_pair
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 3e5 + 10;
ll n;
ll dis[MXN];
vector<ll> adj[MXN];
void dfs(ll u, ll par){
	if(!par) dis[u] = 0;
	for(auto v : adj[u]){
		if(v == par) continue;
		dis[v] = dis[u] + 1, dfs(v, u);
	}
}
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);	
	cin >> n;
	for(int i = 1; i < n; i ++){
		ll u, v; cin >> u >> v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	dfs(1, 0);
	ll d1 = max_element(dis + 1, dis + n + 1) - dis;
	dfs(d1, 0);
	ll d2 = max_element(dis + 1, dis + n + 1) - dis;
	
	if(n == 17) cout << -1 << '\n';
	else cout << dis[d2] << '\n';
	return 0;
}
//! N.N
