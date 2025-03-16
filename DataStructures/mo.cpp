#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll MXN = 2e5 + 10;
const ll SQR = 383;
ll n, q;
ll A[MXN];
ll Ql[MXN], Qr[MXN], ANS[MXN];
vector<ll> MO;
bool CMP(ll x, ll y){
    if(Ql[x] / SQR == Ql[y] / SQR) return Qr[x] < Qr[y];
    return (Ql[x] / SQR < Ql[y] / SQR);
}
bool CmP(int x, int y){ //faster
     if(Ql[x] / SQR == Ql[y] / SQR)
        return ((Ql[x] / SQR) & 1) ^ (Qr[x] < Qr[y]);
     return (Ql[x] / SQR < Ql[y] / SQR);
 }
void Add(ll x){}
void Ers(ll x){}
// or Toggle
int main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin >> q;
    for(int i = 1; i <= q; i ++){
        cin >> Ql[i] >> Qr[i];
        MO.push_back(i);
    }
    sort(MO.begin(), MO.end(), CMP);
    ll Ml = 1, Mr = 0;
    for(auto id : MO){
        ll l = Ql[id], r = Qr[id];
        while(Mr < r) Mr ++, Add(A[Mr]);
        while(Ml > l) Ml --, Add(A[Ml]);
        while(Mr > r) Ers(A[Mr]), Mr --;
        while(Ml < l) Ers(A[Ml]), Ml ++;
        //! Note that we are passing A[Mr] which is the value and not index (i)
        ANS[id] = 83;
    }
    for(int i = 1; i <= q; i ++) cout << ANS[i] << '\n';
    return 0;
}