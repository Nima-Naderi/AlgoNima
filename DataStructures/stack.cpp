// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MXN = 3e5 + 10;
const ll LOG = 20;
ll n;
ll A[MXN];
ll L[MXN], R[MXN]; //first bigger
void solve(){
    cin >> n; for(int i = 1; i <= n; i ++) cin >> A[i];

    for(int i = 1; i <= n; i ++){ // <= or <
        L[i] = i - 1;
        while(L[i] && A[L[i]] <= A[i]) L[i] = L[L[i]];
    }
    for(int i = n; i >= 1; -- i){
        R[i] = i + 1;
        while(R[i] <= n && A[R[i]] <= A[i]) R[i] = R[R[i]];
    }

    vector<int> stk = {0};
    fill(L, L + n + 5, -1);
    fill(R, R + n + 5, n + 1);
    for(int i = 1; i <= n; i++){
        while(!stk.empty() && A[stk.back()] <= A[i]){
            R[stk.back()] = i;
            stk.pop_back();
        }
        if(!stk.empty()){
            L[i] = stk.back();
        }
        stk.push_back(i);
    }

}

int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0); 

	return 0;
}
//! N.N
