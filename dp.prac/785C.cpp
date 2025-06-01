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
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
const int inf = 9e18;
const int mod = 1e9 + 7;
const int NUM = 1000030;
const int N = 2e5+5;
const int MAX=1e5+10;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


int dp[40001][502];

int reverse(int n)
{
    int r=0;
    while(n>0)
    {
        r=r*10+n%10;
        n/=10;
    }
    return r;
}

bool palindrome(int n)
{
    return (reverse(n)==n); 
}

void solve()
{
    vector<int> palin;
    palin.push_back(0);
    for(int i=1;i<2*N;i++)
    {
        if(palindrome(i))
            palin.push_back(i);
    }

    for(int j=1;j<502;j++) {
        dp[0][j]=1;
    }
    for(int i=1;i<40001;i++)
    {
        dp[i][0]=0;
        for(int j=1;j<502;j++)
        {
            if(palin[j]<=i)
                dp[i][j]=(dp[i][j-1]+dp[i-palin[j]][j])%mod;
            else
                dp[i][j]=dp[i][j-1];
        }
    }
    
}  


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    solve();
    int v;
    while (t--) {
        cin >> v;
        cout << dp[v][501] << endl;
    }
        

}