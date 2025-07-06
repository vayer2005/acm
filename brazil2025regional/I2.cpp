#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define pi pair<int, int>
#define fir first
#define sec second
#define pb push_back
#define MAXN 1000006
#define mod 1000000007

int spf[MAXN];          // smallest prime factor for each number
int freq[MAXN];         // frequency of each food value
int divcnt[MAXN];       // number of foods divisible by d
int pow2[100005 + 5];   // powers of 2 up to maximum N (<=1e5)

// Pre-compute smallest prime factor up to MAXN-1
void build_spf() {
    for (int i = 2; i < MAXN; ++i) {
        if (spf[i] == 0) {
            for (int j = i; j < MAXN; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
    spf[1] = 1; // arbitrary
}

// Fast exponentiation mod mod (not really needed thanks to table)
int mod_pow(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input number of foods
    int N;
    if (!(cin >> N)) return 0;

    vector<int> foods(N);
    for (int i = 0; i < N; ++i) {
        cin >> foods[i];
        freq[foods[i]]++;
    }

    // Build divcnt: number of foods divisible by d
    for (int d = 1; d < MAXN; ++d) {
        for (int multiple = d; multiple < MAXN; multiple += d) {
            divcnt[d] += freq[multiple];
        }
    }

    // Pre-compute powers of 2 up to N (inclusive)
    pow2[0] = 1;
    for (int i = 1; i <= N; ++i) {
        pow2[i] = (pow2[i - 1] * 2) % mod;
    }

    // Build smallest prime factor table
    build_spf();

    int Q;
    cin >> Q;
    while (Q--) {
        int X; cin >> X;

        // Factorize X to get unique prime factors
        vector<int> primes;
        int temp = X;
        while (temp > 1) {
            int p = spf[temp];
            if (primes.empty() || primes.back() != p) primes.push_back(p);
            while (temp % p == 0) temp /= p;
        }

        long long bad = 0;
        int k = primes.size();
        int subsets = 1 << k;
        for (int mask = 1; mask < subsets; ++mask) {
            long long prod = 1;
            int bits = __builtin_popcountll(mask);
            for (int i = 0; i < k; ++i) {
                if (mask & (1LL << i)) {
                    prod *= primes[i];
                }
            }
            long long add = divcnt[prod];
            if (bits & 1) bad += add;  // odd size subset -> add
            else bad -= add;           // even size subset -> subtract
        }

        long long safe = N - bad;  // foods without any allergic ingredient
        if (safe < 0) safe = 0;    // just in case (should not happen)
        cout << pow2[safe] % mod << '\n';
    }

    return 0;
}

