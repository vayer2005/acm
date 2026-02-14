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

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

vector<int> lp, sieve;
vector<int> pr;
vector<int> power;
vector<int> fact(2e5 + 5, 0);
void initpow(int x)
{
    power.resize(NUM);
    power[0] = 1;
    for (int i = 1; i < NUM; i++)
    {
        power[i] = (power[i - 1] * (x % mod)) % mod;
    }
}
void initFactorial()
{
    fact.resize(NUM);
    fact[0] = 1;
    for (int i = 1; i < NUM; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}
void calc_sieve()
{
    sieve.resize(NUM + 1, 0);
    for (int x = 2; x <= NUM; x++)
    {
        if (sieve[x])
            continue;
        for (int u = x; u <= NUM; u += x)
        {
            sieve[u] = x;
        }
    }
}
void primefactor()
{
    lp.resize(N + 1, 0);
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return ((a / gcd(a, b)) * b);
}



void solve()
{
    int n, k;
    cin >> k >> n;

    vector<string> strs;

    string c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        strs.pb(c);
    }

    int bst = n;
    string fin(k, 'a');
    for (int i = 1; i <= k; i++) {
        if (k%i == 0) {
            bool works = true;
            bst = i;
            for (int j = 0; j < i; j++) {
                vector<int> used(26, 0);
                for (int w = j; w < k; w+=i) {
                    set<char> appear;
                    for (int z = 0; z < n; z++) {
                        appear.insert(strs[z][w]);
                    }
                    for (char s : appear){
                        used[s-'a']++;
                    }
                }


                bool found = false;
                //cout << "Interval Size: " << i << endl;
                //cout << "currIdx: " << j << endl;
                for (int w = 0; w < 26; w++) {
                    //cout << used[w] << " ";
                    if (used[w] == k/i) {
                        found = true;
                        fin[j] = 'a' + w;
                        break;
                    }
                }
                if (!found) {
                    works = false;
                    break;
                }

            }
            if (works) break;
            
        }
    }


    for (int i = 0; i < k/bst; i++) {
        for (int j = 0; j < bst; j++) {
            cout << fin[j];
        }
    }

    cout << endl;
    
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