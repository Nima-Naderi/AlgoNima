#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef pair<int  ,int > pii;

const int maxn  = 203;

#define pb push_back
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)

bitset < maxn * 2 >  in[maxn*2] , out[maxn*2] , tmp[maxn * 2] , mark;

struct TwoSat {
	int n, c; // TODO: change c to comp_cnt
	vector < int > col , Top;
	TwoSat(int N):
		n(N) , c(0) , col(2*n + 5){}
	bool operator [] (int x) { return(col[2*x] > col[2*x + 1]); }
	void add_e(int v , int u){in[u][v] = 1 , out[v][u] = 1;}
	void add(int v , int u){add_e(u^1 , v) , add_e(v^1 , u);}
	void rm_e(int v , int u){in[u][v] = 0 , out[v][u] = 0;}
	void rm(int v , int u){rm_e(u^1 , v) , rm_e(v^1 , u);}
	void Clear(){
		c = 0; Top.clear(), Top.reserve(1 << 3);
		mark = 0; mark.flip();
	}
	void sfd(ll u){
		col[u] = c, mark[u] = 0;
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
				c ++, sfd(u);
			}
		}
		for(int i = 1; i <= n; i ++){
			if(col[i * 2] == col[i * 2 + 1]) return 0;
		}
		return 1;
	}
};

int n;

int a[maxn][maxn];
vector < int > w;

vector < pii > vec[maxn * maxn];

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
    migmig;
     cin >> n;
    TwoSat g(n);
    for(int i = 1 ; i <= n ; i ++)
		for(int j = i + 1 ; j <= n ; j ++)
			cin >> a[i][j] , a[j][i] = a[i][j] , w.pb(a[i][j]);
	w.pb(0);
	w.pb(-1);
	sort(w.begin() , w.end());
	w.resize(unique(w.begin() , w.end()) - w.begin());
	int ans = 2e9;
	for(int i =1  ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			if(j^i)vec[lower_bound(w.begin() , w.end() , a[i][j]) - w.begin()].pb({i , j});
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

    //TODO: refactor this code to be cleaner
    return(0);
}