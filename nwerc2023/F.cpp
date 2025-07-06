#include <bits/stdc++.h>
using namespace std;

using int128 = __int128_t;
using ll = long long;

/* -----------------------------------------------------
   Helpers for printing / converting 128-bit integers
   --------------------------------------------------*/
string to_string(int128 x) {
    if (x == 0) return "0";
    bool neg = false;
    if (x < 0) { neg = true; x = -x; }
    string s;
    while (x) {
        int digit = x % 10;
        s.push_back(char('0' + digit));
        x /= 10;
    }
    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

/* -----------------------------------------------------
   Main solution
   --------------------------------------------------*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string sa, sb, sc, sd;
    if (!(cin >> sa >> sb >> sc >> sd)) return 0;

    // read c / d as 128-bit
    int128 c = stoll(sc);
    int128 d = stoll(sd);

    // Reduce the target fraction to lowest terms (works in 64-bit because inputs fit in signed 64-bit)
    long long gc = std::gcd((long long)c, (long long)d);
    c /= gc;
    d /= gc;

    int n = (int)sa.size();

    // Pre-allocation for performance
    int removedA[10];
    int removedB[10];

    // Enumerate every non-empty subsequence of a using bitmask
    for (ll mask = 1; mask < (1LL << n); ++mask) {
        //----------------------------------------
        // build the number kept from a (na) and record deleted digits
        //----------------------------------------
        removedA.fill(0);
        int128 na = 0;
        char firstDigit = '\0';
        int keptLen = 0;

        for (int i = 0; i < n; ++i) {
            if (mask & (1LL << i)) {           // keep sa[i]
                if (keptLen == 0) firstDigit = sa[i];
                ++keptLen;
                na = na * 10 + (sa[i] - '0');
            } else {                           // delete sa[i]
                ++removedA[sa[i] - '0'];
            }
        }

        // Disallow numbers with leading zeros (except the single digit 0 itself)
        if (keptLen > 1 && firstDigit == '0') continue;

        //----------------------------------------
        // Determine the only possible partner value nb such that na / nb = c / d
        //----------------------------------------
        int128 numerator = na * d;
        if (numerator % c != 0) continue;      // must be divisible
        int128 nb = numerator / c;

        string sbKeep = to_string(nb);
        if (sbKeep.size() > 1 && sbKeep[0] == '0') continue; // leading zero in b-part

        //----------------------------------------
        // Check if sbKeep is a subsequence of original b and deletions match
        //----------------------------------------
        removedB.fill(0);
        size_t ix = 0;
        for (char ch : sb) {
            if (ix < sbKeep.size() && ch == sbKeep[ix]) {
                ++ix;           // match, keep this digit
            } else {
                ++removedB[ch - '0']; // digit deleted from b
            }
        }
        if (ix != sbKeep.size()) continue;     // sbKeep is not a subsequence of b

        // Compare the multisets of deleted digits
        if (removedA == removedB) {
            cout << "possible\n";
            cout << to_string(na) << ' ' << sbKeep << '\n';
            return 0;
        }
    }

    cout << "impossible\n";
    return 0;
}