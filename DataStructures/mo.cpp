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



// ============== HILBERT ORDER ==============
constexpr int LOG = 18; //minimal value that 2^LOG ≥ n
inline int64_t HilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = HilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}
bool HilbCMP(int x, int y){
    return HilbertOrder(Ql[x], Qr[x], LOG, 0) < HilbertOrder(Ql[y], Qr[y], LOG, 0);
} // much faster when q is significantly less than n
// source: CF blog https://codeforces.com/blog/entry/61203

// ============== HILBERT ORDER (OPTIMIZED) ==============
uint64_t hilbertOrder(uint64_t x, uint64_t y) {
    const uint64_t logn = __lg(max(x, y) * 2 + 1) | 1;
    const uint64_t maxn = (1ull << logn) - 1;
    uint64_t res = 0;
    for (uint64_t s = 1ull << (logn - 1); s; s >>= 1) {
        bool rx = x & s, ry = y & s;
        res = (res << 2) | (rx ? ry ? 2 : 1 : ry ? 3 : 0);
        if (!rx) {
            if (ry) x ^= maxn, y ^= maxn;
            swap(x, y);
        }
    }
    return res;
}
bool HilbCmP(int x, int y){
    return hilbertOrder(Ql[x], Qr[x]) < hilbertOrder(Ql[y], Qr[y]);
}

// ============== SIERPINSKI ORDER ==============
const int64_t max_coord = (int64_t)(MXN);
inline int64_t sierpinskiIndex(int64_t x, int64_t y) {
	int64_t result = 0, oldX;
	if(x > y){
	    result ++;
	    x = max_coord - x, y = max_coord - y;  
	}
    for(int64_t loop = max_coord; loop; loop /= 2){
	    result += result;
	    if(x + y > max_coord){
	        result ++;
	        oldX = x, x = max_coord - y, y = oldX;
	    }
	    x += x;
	    y += y;
	    result += result;
	    if(y > max_coord){
	        result ++;
	        oldX = x, x = y - max_coord, y = max_coord - oldX;
	    }
	}
	return result;
}
bool SierCMP(int x, int y){
    return sierpinskiIndex(Ql[x], Qr[x]) < sierpinskiIndex(Ql[y], Qr[y]);
}

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