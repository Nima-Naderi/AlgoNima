// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MXN = 3e5 + 10;
const ll LOG = 20;
ll n;
ll A[MXN];

int rmq[LOG][MXN], lg[MXN];
inline void BuildRmq(){
    for(int i = 1; i <= n; i ++) rmq[0][i] = A[i];
    for(int j = 1; j < LOG; j ++){
        for(int i = 1; i <= n; i ++){
            if(i < (1LL << j)) continue;
            rmq[j][i] = max(rmq[j - 1][i], rmq[j - 1][i - (1LL << (j - 1))]);
        }
    }
} 
inline int Max(int l, int r){
    if(l == r) return rmq[0][l];
    if(r < l) swap(l, r);
    return max(rmq[lg[r - l + 1]][r], rmq[lg[r - l + 1]][l + (1LL << lg[r - l + 1]) - 1]);
}
inline void InitLog(){
	for(int i = 0; (1LL << i) < MXN; i ++) lg[(1LL << i)] = i;
    for(int i = 1; i < MXN; i ++)          lg[i] = max(lg[i - 1], lg[i]);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	
	InitLog();
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> A[i];
	BuildRmq();


	return 0;
}
//! N.N
