///In the name of GOD
//#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MXN = 5e5 + 10;
const ll SGM = 26;
ll n, q, ts = 1, timer;
ll A[MXN], Ans[MXN], ver[MXN];
ll Stm[MXN], Ftm[MXN], Fen[MXN];
ll nxt[MXN][SGM], Qq[MXN], lps[MXN];
vector<ll> adj[MXN];
vector<pair<ll, ll>> Q[MXN];
string S[MXN];
void Add(ll id){
    cin >> S[id];
    ll u = 1, sz = S[id].size();
    for(int h = 0; h < sz; h ++){
        if(!nxt[u][S[id][h] - 'a']) nxt[u][S[id][h] - 'a'] = ++ ts;
        u = nxt[u][S[id][h] - 'a'];
    }
    ver[id] = u;
}
void Aho(){
    ll L = 0, R = 0;
    for(int i = 0; i < SGM; i ++){
        if(!nxt[1][i]) nxt[1][i] = 1;
        else{
            Qq[R ++] = nxt[1][i];
            lps[nxt[1][i]] = 1;
        }
    }
    while(L < R){
        ll u = Qq[L ++];
        adj[lps[u]].push_back(u);
        for(int c = 0; c < SGM; c ++){
            if(!nxt[u][c]) nxt[u][c] = nxt[lps[u]][c];
            else{
                lps[nxt[u][c]] = nxt[lps[u]][c];
                Qq[R ++] = nxt[u][c];
            }
        }
    }
}
void dfs(ll u){
    Stm[u] = ++ timer;
    for(auto v : adj[u]) dfs(v);
    Ftm[u] = timer;
}
void Upd(ll ind, ll x){
    for(int p = ind; p < MXN; p += (p & -p)) Fen[p] += x;
}
ll Get(ll ind){
    ll niw = 0;
    for(int p = ind; p; p -= (p & -p)) niw += Fen[p];
    return niw;
}
ll Get(ll l, ll r){
    return Get(r) - Get(l - 1);
}
void SPARSE(ll id){
    ll u = 1;
    for(int i = 0; i < S[id].size(); i ++){
        u = nxt[u][S[id][i] - 'a'];
        Upd(Stm[u], 1);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) Add(i);
    Aho(), dfs(1);
    for(int i = 1; i <= q; i ++){
        ll l, r, k; cin >> l >> r >> k;
        Q[r].push_back({k, i});
        Q[l - 1].push_back({k, -i});
    }
    for(int i = 1; i <= n; i ++){
        SPARSE(i);
        for(auto Pr : Q[i]){
            ll k, id; tie(k, id) = Pr;
            Ans[abs(id)] += (id > 0 ? 1 : -1) * Get(Stm[ver[k]], Ftm[ver[k]]);
        }
    }
    for(int i = 1; i <= q; i ++) cout << Ans[i] << '\n';
    return 0;
}
/*!
    HE'S AN INSTIGATOR,
    ENEMY ELIMINATOR,
    AND WHEN HE KNOCKS YOU BETTER
    YOU BETTER LET HIM IN.
*/
//! N.N