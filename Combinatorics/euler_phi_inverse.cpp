///In the name of GOD
#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;

typedef long long ll;
const ll MXN = 1e5 + 10;
ll Mod;
ll power(ll a, ll b){
    return (!b ? 1 : power(a * a % Mod, b / 2) * (b & 1LL ? a : 1) % Mod);
}
void init(){
    ll p = 2, m = Mod; phi = m;
    while(p * p <= m){
        if(m % p == 0){
            while(m % p == 0) m /= p;
            phi -= phi / p;
        }
        p ++;
    }
    if(m > 1) phi -= phi / m;
    //! The inverse of x mod Mod can be calculated
    // IF AND ONLY IF gcd(Mod, x) = 1
    ll x = 10, inv_x = power(x, phi - 1); 
    
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

    cin >> Mod, init();
    
    // CF: 715C
    return 0;
}