#include <bits/stdc++.h>
 
using namespace std; 
#define int long long
#define double long double

const int mod = 998244353;

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

int inversemod(int a, int mod)
{
    return binpow(a, mod - 2, mod);
}

int divmod(int a, int b, int c)
{
    return ((a % c) * inversemod(b, c)) % c;
}

int powv(int a, int b) {
    int res = a;
    res %= mod;
    for (int i = 1; i < b; i++) {
        res *= a;
        res %= mod;
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;

    int num = powv(2*k, 2*k);
    int den = powv(2*k+1, 2*k);
    
    int fin = divmod(num, den, mod);
    fin = (n*fin) % mod;

    cout << fin << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    
    return 0;
 
}