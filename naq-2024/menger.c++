#include <bits/stdc++.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
typedef long long ll;

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

bool greater(Rational o, Rational t) {
    make_common(o, t);
    return o.num > t.num;
}

bool less(Rational o, Rational t) {
    make_common(o, t);
    return o.num < t.num;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int l;
    Rational x, y, z;
    cin >> l >> x.num >> x.den >> y.num >> y.den >> z.num >> z.den;

    Rational one_third = {1, 3};
    Rational two_third = {2, 3};

    vector<Rational> coords = {x,y,z};

    for (int k = 0; k<l; k++) {
        int count = 0;

        if (greater(x, one_third) && less(x, two_third)) {
            count+=1;
        }

        if (greater(y, one_third) && less(y, two_third)) {
            count+=1;
        }
        if (greater(z, one_third) && less(z, two_third)) {
            count+=1;
        }
        if (count >= 2) {
            cout << 0 << endl;
            return 0;
        }

        while (greater(x, one_third)) {
            x = subtr(x, one_third);
        }
        x.num = x.num * 3;
        x = reduce(x);

        while (greater(y, one_third)) {
            y = subtr(y, one_third);
        }
        y.num = y.num * 3;
        y = reduce(y);
        while (greater(z, one_third)) {
            z = subtr(z, one_third);
        }
        z.num = z.num * 3;
        z = reduce(z);
    }
    cout << 1 << endl;
}

