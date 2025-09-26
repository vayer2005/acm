#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
 
#define int long long
using vi = vector<int>;
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ordered_set os1;
    int ans = 0;
    vi big(n);
    vi small(n);

    for (int i = 0; i < n; i++) {
        int ord = os1.order_of_key(-1*a[i]);
        big[i] = ord;
        os1.insert(-1 * a[i]);
    }
    
    ordered_set os2;
    for (int i = n-1; i >= 0; i--) {
        int ord = os2.order_of_key(a[i]);
        small[i] = ord;
        os2.insert(a[i]);
    }
    
    for (int i = 0; i < n; i++) {
        //cout << big[i] << " " << small[i] << endl;
        ans += big[i] * small[i];
    }
    
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}