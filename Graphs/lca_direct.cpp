#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define Mp make_pair
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 3e5 + 10;
const ll MX2N = MXN * 2;
const ll LOG = 20;
const ll INF = 1e9;
ll n;
vector<ll> adj[MXN];
int lg[MX2N], dis[MXN], last[MXN];
int RMQ[MX2N][LOG], ind[MX2N][LOG];
vector<int> Tour;
void TourDFS(ll u, ll par){
    last[u] = Tour.size();
    Tour.push_back(Mp(dis[u], u));
    for(auto v : adj[u]){
        if(v == p) continue;
        dis[v] = dis[u] + 1;
        TourDFS(v, u);
        Tour.push_back(Mp(dis[u], u));
    }
    return;
}
inline void InitLog(){
	for(int i = 0; (1LL << i) < MXN; i ++) lg[(1LL << i)] = i;
	for(int i = 1; i < MXN; i ++)          lg[i] = max(lg[i - 1], lg[i]);
}
void prep(ll root){
    TourDFS(root), InitLog();
    for(int i = Tour.size() - 1; i >= 0; i --){
        RMQ[i][0] = Tour[i].first,  ind[i][0] = Tour[i].second;
        for(int j = 1; j < LOG; j ++){
            if(Tour.size() >= (1LL << j)){
                RMQ[i][j] = min(RMQ[i][j - 1], RMQ[i + (1LL << (j - 1))][j - 1]);
                if(RMQ[i][j - 1] < RMQ[i + (1LL << (j - 1))][j - 1]) ind[i][j] = ind[i][j - 1];
                else                                                 ind[i][j] = ind[i + (1LL << (j - 1))][j - 1];
            } else RMQ[i][j] = INF;
        }
    }
    return;
}
ll LCA(ll u, ll v){
    ll l = last[u], r = last[v];
    if(l > r) swap(l, r);
    if(RMQ[l][lg[r - l]] > RMQ[r - (1 << lg[r - l]) + 1][lg[r - l]])
        return ind[r - (1 << lg[r - l]) + 1][lg[r - l]];
    return ind[l][lg[r - l]];
}
inline ll Distance(ll u, ll v){
	return dis[u] + dis[v] - 2 * dis[LCA(u, v)];
}
void solve(){
	cin >> n;
	for(int i = 0; i <= n; i ++) adj[i].clear();
	for(int i = 1; i < n; i ++){
		ll u, v; cin >> u >> v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	dis[1] = 0, prep(1);

}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	ll tq = 1;
	cin >> tq;
	while(tq --) solve();
	return 0;
}
//! N.N

