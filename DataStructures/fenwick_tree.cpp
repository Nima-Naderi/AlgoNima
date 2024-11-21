// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define Mp make_pair
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 3e5 + 10;
const ll LOG = 20;
ll n;

//Be careful with Mod
ll Fen[MXN];
void Upd(ll p, ll x){
    for(; p < MXN; p += p & -p) Fen[p] += x;
}
void Upd(ll l, ll r, ll x){
    Upd(l, x), Upd(r + 1, -x);
}
ll Get(ll p){
    ll s = 0; for(; p; p -= p & -p) s += Fen[p]; return s;
}
ll Get(ll l, ll r){
    return (r < l ? 0 : Get(r) - Get(l - 1));
}
ll Find(ll k){
    ll ans = 0;
    for(int i = LOG; ~i; i --){
        if(ans + (1LL << i) < MXN && Fen[ans + (1LL << i)] >= k){
            ans += (1LL << i), k -= Fen[ans];
        }
    }
    return ans + 1;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	
	cin >> n;
	fill(Fen, Fen + n + 5, 0);
	
	return 0;
}
//! N.N
