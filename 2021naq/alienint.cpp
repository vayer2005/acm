#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
 
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define int long long
using vpi = vector<pair<int, int>>;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
const int mod = 1e9+7;
const int NUM = 1000030;
const int N = 2e5+5;
const double EPS = 1e-9;
const int INF = 1e9 + 13;
 
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
int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
int binpow(int a, int b, int mod)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
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
    int g = gcd(a, b);
    if (g == 0) return 0; // Avoid division by zero
    return ((a / g) * b);
}
int inversemod(int a, int mod)
{
    return binpow(a, mod - 2, mod);
}
int divmod(int a, int b, int c)
{
    return ((a % c) * inversemod(b, c)) % c;
}
int C(int n, int k)
{
    if (k > n)
        return 0;
    int p1 = (fact[n] * inversemod(fact[k], mod)) % mod;
    int p2 = (1 * inversemod(fact[n - k], mod)) % mod;
    return (p1 * p2) % mod;
}

void solve() {
    int n; cin >> n;
    int x = n;
    set<int> can;
    while (n > 0) {
        can.insert(n%10);
        n/=10;
    }
    string orig = to_string(x);
    int strt = orig[0] - '0';

    int smallestC = -1;
    int smallestA = -1;

    int biggestC = -1;
    int biggestA = -1;
    int less = 0;
    int prev = strt;
    for (int i = 0; i < 10; i++){ 
        int curr = prev - 1;
        if (curr == 0) {
            curr = 9;
            //less = 1;
        }
        if (can.find(curr) == can.end()) {
            biggestC = curr;
            break;
        }
        prev = curr;
    }

    prev = strt;

    for (int i = 0; i < 10; i++){ 
        int curr = prev + 1;
        if (curr == 10) {
            curr = 1;
            
        }
        if (can.find(curr) == can.end()) {
            smallestC = curr;
            break;
        }
        prev = curr;
    }

    for (int i = 0; i <= 9; i++) {
        if (can.find(i) == can.end()) {
            smallestA = i;
            break;
        }
    }

    for (int i = 9; i >= 0; i--) {
        if (can.find(i) == can.end()) {
            biggestA = i;
            break;
        }
    }

    vi nums;
    if (can.find(0LL) == can.end()) {
        nums.pb(0LL);
    }


    if (biggestA != -1 && biggestC != -1) {
        if (biggestC > strt && orig.size() != 1) {
            //size-1
            int sz = orig.size()-1;
            if (sz > 0) {
                string sm = to_string(biggestC);
                for (int i = 0; i < sz-1; i++) {
                    sm += to_string(biggestA);
                }
                nums.pb(stoll(sm));
            }
        } else {
            int sz = orig.size();
            string sm = to_string(biggestC);
            for (int i = 0; i < sz-1; i++) {
                sm += to_string(biggestA);
            }
            nums.pb(stoll(sm));
        }
    }

    if (smallestA != -1 && smallestC != -1) {
        if (smallestC < strt) {
            //size-1
            int sz = orig.size()+1;
            string sm = to_string(smallestC);
            for (int i = 0; i < sz-1; i++) {
                sm += to_string(smallestA);
            }
            nums.pb(stoll(sm));
        } else {
            int sz = orig.size();
            string sm = to_string(smallestC);
            for (int i = 0; i < sz-1; i++) {
                sm += to_string(smallestA);
            }
            nums.pb(stoll(sm));
        }
    }


    int mndif = 1e18;
    vi works;
    if (nums.size() == 0) {
        cout << "Impossible\n";
        return;
    }
    for (int y : nums) {
        mndif = min(mndif, abs(x-y));
    }

    for (int y : nums) {
        if (mndif == abs(x-y)) {
            works.pb(y);
        }
    }

    sort(works.begin(), works.end());
    for (int y : works) {
        cout << y << " ";
    }
    cout << endl;
   

    
}

    



 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    
    return 0;
 
}