// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define Mp make_pair
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 3e5 + 10;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	

	return 0;
}
//! N.N

// #include <bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace std;
// using namespace __gnu_pbds;

// #define forn(i, n) for (int i = 0; i < int(n); i++)

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// int main() {
//     int n;
//     cin >> n;    

//     vector<int> a(n);
//     vector<pair<int,int>> b;
//     forn(i, n) {
//         cin >> a[i];
//         b.push_back({-a[i], i});
//     }
//     sort(b.begin(), b.end());

//     int m;
//     cin >> m;
//     vector<pair<pair<int,int>,int>> req(m);
//     forn(i, m) {
//         cin >> req[i].first.first >> req[i].first.second;
//         req[i].second = i;
//     }
//     sort(req.begin(), req.end());

//     vector<int> ans(m);
//     ordered_set pos;
//     int len = 0;
//     forn(i, m) {
//         while (len < req[i].first.first)
//             pos.insert(b[len++].second);
//         ans[req[i].second] = a[*pos.find_by_order(req[i].first.second - 1)];
//     }

//     forn(i, m)
//         cout << ans[i] << endl;
// }