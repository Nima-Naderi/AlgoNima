// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define Mp make_pair
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MXN = 3e5 + 10;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll n, q;
ordered_set os;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin >> n >> q;
    for(int i = 1; i <= n; i ++){
        ll x; cin >> x;
        os.insert(x);
    }
    for(int i = 1; i <= q; i ++){
        ll k, x; cin >> k >> x;
        cout << *os.find_by_order(k) << " - " << os.order_of_key(x) << '\n';
    }

	return 0;
}
//! N.N