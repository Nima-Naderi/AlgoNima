//#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MXN = 5e5 + 10;
const ll SGM = 26;
ll n, m;
string s, t;
void LPS(){
    ll k = (lps[0] = lps[1] = 0);
    for(int i = 2; i <= n; i ++){
        while(k && s[k + 1] != s[i]) k = lps[k];
        k += (s[k + 1] == s[i]);
        lps[i] = k;
    }

    //note: for putting "brick" character between strings
    k = 0;
	for(int i = 1; i <= m; i ++){
		while(k && s[k + 1] != t[i]) k = lps[k];
        k += (s[k + 1] == t[i]);
        //lps_t[i] = k; // or concatenate
		if(k == n) k = lps[k];
	}

    // s = s + '#' + t;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0); 
    cin >> s >> t;
    
    //important (1-based)
    n = (ll)s.size(); s = "$" + s;
    m = (ll)t.size(); t = "$" + t; 

    LPS();

    return 0;
}
//! N.N