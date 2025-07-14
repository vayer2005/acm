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