#include <bits/stdc++.h>

using namespace std;
#define int int64_t

struct Rational {
  int64_t num, den;
};

int64_t gcd(int64_t a, int64_t b) {
  while (b != 0) {
    int64_t t = b;
    b = a % b;
    a = t;
  }
  return a;
}

Rational reduce(Rational in) {
  int64_t g = gcd(in.num, in.den);
  in.num /= g;
  in.den /= g;
  return in;
}

void make_common(Rational &a, Rational &b) {
  int64_t den_a = a.den;
  int64_t den_b = b.den;
  a.num *= den_b;
  a.den *= den_b;
  b.num *= den_a;
  b.den *= den_a;
}

bool greater_or_eq(Rational o, Rational t) {
    make_common(o, t);
    return o.num >= t.num;
}

bool less_or_eq(Rational o, Rational t) {
    make_common(o, t);
    return o.num <= t.num;
}

Rational subtr(Rational a, Rational o3){
    make_common(a, o3);
    a.num = a.num - o3.num;
    return reduce(a);
}

bool greatr(Rational o, Rational t) {
    make_common(o, t);
    return o.num > t.num;
}

bool less(Rational o, Rational t) {
    make_common(o, t);
    return o.num < t.num;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    stack<vector<int>> stck;

    Rational ans;
    ans.num = 0;
    ans.den = 1;

    for (int i = 0; i < n; i++) {
        while (!stck.empty() && stck.top()[0] < a[i]) {
            stck.pop();
        }
        if (!stck.empty()) {
            int val = stck.top()[0];
            int nxt = stck.top()[1];
            int strt = stck.top()[2];
            int reach = a[i];

            Rational r1;
            r1.num = val-reach;
            r1.den = val-nxt;
            int inc = r1.den * strt;
            r1.num += inc;
            r1 = reduce(r1);
            
            Rational r2;
            r2.num = r1.den * i;
            r2.den = r1.den;
            r2 = reduce(r2);
            make_common(r1,r2);
            Rational nw;
            nw.num = r2.num - r1.num;
            nw.den = r2.den;
            nw = reduce(nw);
            if (greatr(nw, ans)) {
                ans = nw;
            }
        }
        if (i != n-1) {
            stck.push({a[i], a[i+1], i});
        }
    }   

    stack<vector<int>> stck2;

    for (int i = n-1; i >= 0; i--) {
        while (!stck2.empty() && stck2.top()[0] < a[i]) {
            stck2.pop();
        }
        if (!stck2.empty()) {
            int val = stck2.top()[0];
            int nxt = stck2.top()[1];
            int strt = stck2.top()[2];
            int reach = a[i];

            Rational r1;
            r1.num = reach-val;
            r1.den = val-nxt;
            r1.num += r1.den * strt;
            r1 = reduce(r1);
            Rational r2;
            r2.num = r1.den * i;
            r2.den = r1.den;
            r2 = reduce(r2);
            make_common(r1,r2);
            Rational nw;
            nw.num = r1.num - r2.num;
            nw.den = r2.den;
            nw = reduce(nw);
            if (greatr(nw, ans)) {
                ans = nw;
            }
        }
        if (i != 0) {
            stck2.push({a[i], a[i-1], i});
        }
    }   

    if (ans.num == 0) {
        cout << "0\n";
        return 0;
    } else if (ans.den == 1) {
        cout << ans.num << endl;
        return 0;
    }

    cout << ans.num << "/" << ans.den << endl;

   
}