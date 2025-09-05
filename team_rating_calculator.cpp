// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define Mp make_pair
#define MSB(x)  (63 - __builtin_clzll(ll(x)))
#define bit(x, b) ((x >> b) & 1)
#define kill { cout << "NO\n"; return 0; }
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 2e5 + 10;
const ll Mod = 998244353;
long double getWinProbability(long double ra, long double rb) {
    return 1.0 / (1.0 + pow((long double) 10.0, (rb - ra) / 400.0));
}
#define forn(i, n) for (int i = 0; i < int(n); i++)
long double aggregateRatings(vector<long double> teamRatings)
{
    long double left = 1;
    long double right = 1E4;

    for (int tt = 0; tt < 100; tt++) {
        long double r = (left + right) / 2.0;

        long double rWinsProbability = 1.0;
        forn(i, teamRatings.size())
            rWinsProbability *= getWinProbability(r, teamRatings[i]);

        long double rating = log10(1 / (rWinsProbability) - 1) * 400 + r;

        if (rating > r)
            left = r;
        else
            right = r;
    }

    return (left + right) / 2.0;
}
void solve(){
	vector<long double> v;
    v = {2282, 2361, 1913};
    cout << aggregateRatings(v) << '\n';
    v.clear();
    v = {2233, 2283, 2320}; // first bronze team (near silver) in SWERC
    cout << aggregateRatings(v) << '\n';
    v = {2400, 2450, 1913};
    cout << aggregateRatings(v) << '\n';
}
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	ll tq = 1;
	cin >> tq;
	while(tq --) solve();
	return 0;
}
//! N.N

