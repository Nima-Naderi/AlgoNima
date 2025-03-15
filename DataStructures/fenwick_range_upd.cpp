// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define Mp make_pair
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 3e5 + 10;
const ll LOG = 20;
// Use this instead of segment tree for range updates
//========= Fenwick Upd(l, r), Get(l, r) =========//
ll Fen[2][MXN];
void Add(int id, int p, int x){
    for(; p < MXN; p += p & -p) Fen[id][p] += x;
}
ll Ask(int id, int p){
    ll niw = 0;
    for(; p; p -= p & -p) niw += Fen[id][p];
    return niw;
}
void Upd(int l, int r, int x){
    Add(0, l, x);
    Add(0, r + 1, -x);
    Add(1, l, x * (l - 1));
    Add(1, r + 1, -x * r);
}
ll Get(int r){
    return Ask(0, r) * r - Ask(1, r);
}
ll Get(int l, int r){
    return Get(r) - Get(l - 1);
}
//========= Time/=3 =========//

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	
	cin >> n;
	fill(Fen, Fen + n + 5, 0);
	
	return 0;
}
//! N.N
