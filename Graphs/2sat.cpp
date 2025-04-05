#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define Mp make_pair
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 200 + 5;
const ll MX2S = MXN * 2;

bitset<MX2S> in[MX2S], out[MX2S], tmp[MX2S], mark;
struct TwoSat {
	ll n, comp_cnt;
	vector<ll> col, Top;

	TwoSat(int N):
		n(N), comp_cnt(0), col(2*n + 5) {}

	bool operator [] (ll x) { return col[2 * x] > col[2 * x + 1]; }

	inline void AddEdge(ll u, ll v){
		in[v][u] = 1, out[u][v] = 1;
	}
	inline void RmvEdge(ll u, ll v){
		in[v][u] = 0, out[u][v] =0;
	}
	inline void Add(ll u, ll v){
		AddEdge(v ^ 1, u), AddEdge(u ^ 1, v);
	}
	inline void Rmv(ll u, ll v){
		RemoveEdge(v ^ 1, u), RemoveEdge(u ^ 1, v);
	}

	void Clear(){
		comp_cnt = 0; Top.clear(), Top.reserve(1 << 3);
		mark = 0; mark.flip();
	}
	void sfd(ll u){
		col[u] = comp_cnt, mark[u] = 0;
		tmp[u] = in[u] & mark;
		for(int v = tmp[u]._Find_first(); v < (int)tmp[u].size(); v = tmp[u]._Find_next(v)){
			sfd(v), tmp[u] &= mark;
		}
	}
	void dfs(ll u){
		mark[u] = 0;
		tmp[u] = out[u] & mark;
		for(int v = tmp[u]._Find_first(); v < (int)tmp[u].size(); v = tmp[u]._Find_next(v)){
			dfs(v), tmp[u] &= mark;
		}
		Top.push_back(u);
	}
	bool Validate(){
		Clear();
		for(int u = 1; u <= 2 * n + 1; u ++){
			if(mark[u]){
				dfs(u);
			}
		}
		reverse(Top.begin(), Top.end());
		mark = 0; mark.flip();
		for(auto u : Top){
			if(mark[u]){
				comp_cnt ++, sfd(u);
			}
		}
		for(int i = 1; i <= n; i ++){
			if(col[i * 2] == col[i * 2 + 1]) return 0;
		}
		return 1;
	}
};


int n;

int a[MXN][MXN];
vector < int > w;

vector < pll > vec[MXN * MXN];

void add1(int x , TwoSat &g){
	for (auto [i , j] : vec[x])
		g.add(i*2 + 1 , j * 2 + 1);
}

void add2(int x , TwoSat &g){
	for (auto [i , j] : vec[x])
		g.add(i*2 , j*2);
}

void rm1(int x , TwoSat &g){
	for (auto [i , j] : vec[x])
		g.rm(i*2 + 1 , j * 2 + 1);
}


int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
     cin >> n;
    TwoSat g(n);
    for(int i = 1 ; i <= n ; i ++)
		for(int j = i + 1 ; j <= n ; j ++)
			cin >> a[i][j] , a[j][i] = a[i][j] , w.push_back(a[i][j]);
	w.push_back(0);
	w.push_back(-1);
	sort(w.begin() , w.end());
	w.resize(unique(w.begin() , w.end()) - w.begin());
	int ans = 2e9;
	for(int i =1  ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			if(j^i)vec[lower_bound(w.begin() , w.end() , a[i][j]) - w.begin()].push_back({i , j});
	int sz = w.size() - 1;
	int l = 1 , r = sz;
	for(int i = l+1 ; i <= r ; i ++)
		add1(i , g);
	ans = min(ans , w[l] + w[r]);
	while(l <= sz){
		if(w[l]>=ans)break;
		while(g.Validate() and r >= l)
			ans = min(ans , w[l] + w[r]),
			add2(r , g) , r--;
		l ++ , rm1(l , g);
	}
	cout << ans;

    //TODO: refactor the main function
    return 0;
}