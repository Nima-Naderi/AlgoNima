// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define Mp make_pair
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;
const ll MXN = 3e5 + 10;
ll gcd(ll x, ll y){
	return (!y ? x : gcd(y, x % y));
}
tuple<ll, ll, ll> extended_gcd(ll a, ll b) {
    if (b == 0) return {a, 1, 0};
    auto [gcd, x1, y1] = extended_gcd(b, a % b);
    return {gcd, y1, x1 - (a / b) * y1};
}
ll n, pt;
ll A[MXN];
vector<ll> lpf, Prm, prm;
inline void Sieve(ll m){ //maximum value in inputs
    lpf.assign(m + 1, 0);
    for(int i = 2; i <= m; i ++){
        if(!lpf[i]) Prm.push_back(lpf[i] = i);
        for(int p : Prm){
            if(p > lpf[i] || p * i > m) break;
            lpf[p * i] = p;
        }
    }
	pt = Prm.size();
}
inline void factorize(ll num){
	prm.clear();
    for(int x = num, p = lpf[x]; x > 1; prm.push_back(p), p = lpf[x]){
        while(x % p == 0) x /= p;
    }
}
inline void GetPresentPrimes(){
	Prm.clear();
	for(int i = 1; i <= n; i ++){
		factorize(A[i]);
		for(auto X : prm) Prm.push_back(X);
	}
	sort(Prm.begin(), Prm.end());
    Prm.resize(pt = (unique(Prm.begin(), Prm.end()) - Prm.begin()));
}
inline int GetPrmId(ll x){
    return lower_bound(Prm.begin(), Prm.end(), x) - Prm.begin() + 1;
}

const ll MXM = 1e7 + 10;
ll phi[MXM];
inline void CalcEulerPhi(){
	for(int i = 1; i < MXM; i ++) phi[i] = i;
	for(int i = 1; i < MXM; i ++){
		for(int j = 1; j * i < MXM; j ++)
			phi[j * i] -= (i != j * i ? phi[i] : 0);
	}
}
// TODO: add modulo inverse using phi function

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);	
	
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> A[i];
	Sieve(*max_element(A + 1, A + n + 1));

	return 0;
}
//! N.N
