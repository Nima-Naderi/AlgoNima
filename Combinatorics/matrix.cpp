// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MXN = 1e6 + 10;
const ll Mod = 1e9+7;
const ll MXZ = 100 + 3;
struct Matrix{
    int n, m;
    ll M[MXZ][MXZ];
    Matrix(int _n, int _m, ll num = 0){
        n = _n, m = _m;
        if(num == -1){
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < m; j ++){
                    M[i][j] = (i == j);
                }
            }
        } else {
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < m; j ++){
                    M[i][j] = num;
                }
            }
        }
    }
    void Print(bool f = 0){
        cerr << "=======N.N=======\n";
        if(f) cerr << "Size : " << n << ' ' << m << '\n';
        for(int i = 0; i < n; i ++, cerr << '\n'){
            for(int j = 0; j < m; j ++) cerr << M[i][j] << ' ';
        }
        cerr << "=======N.N=======\n";
    }
    Matrix operator + (const Matrix &T){
        Matrix R = Matrix(n, m);
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                R.M[i][j] = (M[i][j] + T.M[i][j]) % Mod;
            }
        }
		return R;
    }
    Matrix operator * (const Matrix &T){
        Matrix R = Matrix(n, T.m);
        if(m != T.n){
			cerr << "Cannot * Matrices !" << '\n'; return R;
		}
        for(int i = 0; i < n; i ++){
			for(int k = 0; k < m; k ++){ //swaped - cache friendly
            	for(int j = 0; j < T.m; j ++){
                    R.M[i][j] = (R.M[i][j] + M[i][k] * T.M[k][j]) % Mod;
				}
            }
        }
        return R;
    }
    Matrix operator ^ (const ll t){
		Matrix R = Matrix(n, m, -1);
		if(n != m){
			cerr << "Cannot ^ Matrice with n != m !" << '\n'; return R;
		}
		if(t == 0) return R;
		Matrix T = Matrix(n, m);
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                T.M[i][j] = M[i][j];
            }
        }
		ll p = t;
		while(p){
			if(p & 1LL) R = R * T;
			T = (T * T), p /= 2;
		}
		return R;
	}
};
ll Fib(ll t){
    if(t == 1) return 1;
    Matrix M(2, 1), C(2, 2, 1);
    M.M[0][0] = M.M[1][0] = 1;
    C.M[1][1] = 0;
    C = (C ^ (t - 2));
    M = (C * M);
    return M.M[0][0];
}
//TODO: add gussain for matrix rank
int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	ll x; cin >> x; Matrix C = Matrix(3, 3), M0 = Matrix(3, 1);
	C.M[0][0] = 3, C.M[0][1] = C.M[0][2] = -1, C.M[1][1] = C.M[2][2] = 1;
    M0.M[0][0] = 11, M0.M[1][0] = 1, M0.M[2][0] = 10;
    C = (C ^ x), M0 = C * M0;
    cout << M0.M[0][0] << '\n';
	return 0;
}
//! N.N
