map<ll, int> factorize(ll n) {
    map<ll, int> m;
    if (n == 1) return m;
    if (n < 4) { m[n]++; return m; }
    while ((n & 1) == 0) { m[2]++; n >>= 1; }
    ll d = 3;
    do {
        while (n % d == 0) {
            m[d]++;
            n /= d;
        }
        d += 2;
    } while (n >= d * d);
    if (n > 1) m[n]++;
    return m;
}
