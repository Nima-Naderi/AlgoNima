// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define Mp make_pair
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 3e5 + 10;

ll Par[MXN], Sz[MXN];
ll Find(ll x){
    return (Par[x] == x ? x : Par[x] = Find(Par[x]));
}
bool Union(ll x, ll y){
    x = Find(x), y = Find(y);
    if(x == y) return 0;
    if(Sz[x] < Sz[y]) swap(x, y);
    Par[y] = x, Sz[x] += Sz[y];
	return 1;
}

// nlgn with rollback version

ll Par[MXN], Sz[MXN];
vector<ll> hist;
ll Find(ll x){
    return (Par[x] == x ? x : Find(Par[x]));
}
bool Union(ll x, ll y){
    x = Find(x), y = Find(y);
    if(x == y) return 0;
    if(Sz[x] < Sz[y]) swap(x, y);
    Par[y] = x, Sz[x] += Sz[y];
    hist.push_back(y);
    return 1;
}
void Undo(){
    ll x, y = hist.back();
    x = Par[y], hist.pop_back();
    Sz[x] -= Sz[y], Par[y] = y;
}


int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);	
	
	//initialization
	iota(Par, Par + n + 1, 0);
    fill(Sz, Sz + n + 1, 1);


	return 0;
}
//! N.N

