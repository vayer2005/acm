

unsigned long long nCr(int n, int r) {
    if (r > n - r) r = n - r;
    unsigned long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - r + i) / i;
    }
    return res;
}
