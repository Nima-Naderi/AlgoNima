/** i can do this all day **/
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn  = 203;

#define pb push_back
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)

bitset < maxn * 2 >  in[maxn*2] , out[maxn*2] , tmp[maxn * 2] , mark;

struct sat{
	int n, c;
	vector < int > col , topo;
	sat(int N):
		n(N) , c(0) , col(2*n + 5){}
	bool operator [] (int x) { return(col[2*x] > col[2*x + 1]); }
	void add_e(int v , int u){in[u][v] = 1 , out[v][u] = 1;}
	void add(int v , int u){add_e(u^1 , v) , add_e(v^1 , u);}
	void rm_e(int v , int u){in[u][v] = 0 , out[v][u] = 0;}
	void rm(int v , int u){rm_e(u^1 , v) , rm_e(v^1 , u);}
	void clear(){
		c = 0;
		topo.clear();
		topo.reserve(1 << 3);
		mark = 0;
		mark.flip();
	}
	void sfd(int v){
		col[v] = c;
		mark[v] = 0;
		tmp[v] = in[v] & mark;
		for(int u = tmp[v]._Find_first() ; u < (int)tmp[v].size(); u = tmp[v]._Find_next(u))
			sfd(u), tmp[v]&=mark;
	}
	void dfs(int v){
		mark[v] = 0;
		tmp[v] = out[v] & mark;
		for(int u = tmp[v]._Find_first() ; u < (int)tmp[v].size(); u = tmp[v]._Find_next(u))
			dfs(u), tmp[v]&=mark;
		topo.pb(v);
	}
	bool validate(){
		clear();
		for(int i = 1 ; i <= 2*n+1 ; i ++ ) if(mark[i]) dfs(i);
		reverse(topo.begin() , topo.end());
		mark = 0;
		mark.flip();
		for(auto v : topo)
			if(mark[v])
				++c , sfd(v);
		for(int i = 1 ; i <= n ; i ++) if(col[i * 2] == col[i * 2 + 1])return(0);
	return(1);
	}
};

int n;

int a[maxn][maxn];
vector < int > w;

vector < pii > vec[maxn * maxn];

void add1(int x , sat &g){
	for (auto [i , j] : vec[x])
		g.add(i*2 + 1 , j * 2 + 1);
}

void add2(int x , sat &g){
	for (auto [i , j] : vec[x])
		g.add(i*2 , j*2);
}

void rm1(int x , sat &g){
	for (auto [i , j] : vec[x])
		g.rm(i*2 + 1 , j * 2 + 1);
}


int32_t main(){
    migmig;
     cin >> n;
    sat g(n);
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
		while(g.validate() and r >= l)
			ans = min(ans , w[l] + w[r]),
			add2(r , g) , r--;
		l ++ , rm1(l , g);
	}
	cout << ans;
    return(0);
}