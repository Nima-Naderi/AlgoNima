#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll MXN = 2e5 + 10;
const ll SQR = 383;
const ll Mod = 1e9 + 7;
typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod {
	ull b, m;
	FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
	ull reduce(ull a) {
		ull q = (ull)((L(m) * a) >> 64);
		ull r = a - q * b;
		return r >= b ? r - b : r;
	}
};
FastMod f(2);

int main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    f = FastMod(Mod);
    
    ll x = Mod + 2; cout << f.reduce(x) << '\n';

    //fast inverse calculation
    Inv[0] = Inv[1] = 1;
    for(int i = 2; i < MXN; i ++){
        Inv[i] = f.reduce(Mod - f.reduce(1ll * Mod / i * Inv[Mod % i]));
    }

    return 0;
}