#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

#define int long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
using vpi = vector<pair<int, int>>;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define ff first
#define ss second
const int inf = 9e18;
const int mod = 1e9 + 7;
const int NUM = 1000030;
const int N = 2e5+5;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


void solve()
{
    int n, m;
    cin >> n >> m;

    if (m < n || (m > ((n * (n+1))/2))) {
        cout << "-1\n";
        return;
    }

    int curr = 0;
    vector<int> ans;
    vector<int> rest;
    int num = n;
    int left = n-1;
    while (true) {
        while (curr + num + left > m) {
            rest.push_back(num);
            num--;
        }

        if (curr + num + left == m) {
            curr = m;
            ans.push_back(num);
            if (num != 1) {
                ans.push_back(1);
            }
            for (int i = num-1; i > 1; i--) {
                ans.push_back(i);
            }
            break;
        }

        ans.push_back(num);
        curr += num;
        left-=1;
        num -=1;
        
    }

    cout << ans[0] << " " << endl;

    for (int i = 0; i < ans.size()-1; i++) {
        cout << ans[i] << " " << ans[i+1] << endl;
    }

    reverse(rest.begin(), rest.end());

    rest.push_back(ans[ans.size()-1]);
    reverse(rest.begin(), rest.end());

    for(int i = 0; i < rest.size()-1; i++) {
        cout << rest[i] << " " << rest[i+1] << endl; 
    }

}  

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    
    while (t--)
        solve();
    return 0;
}