---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../assets/css/copy-button.css" />


# :warning: totient.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/totient.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-11 15:35:53+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

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

ll power(ll e, int t, ll mod = INF_LL) {
  ll res = 1;
  while (t) {
    if (t&1) res = (res * e) % mod;
    t >>= 1;
    e = (e * e) % mod;
  }
  return res;
}

ll phi(ll n) {
  auto ps = factorize(n);
  ll res = 1;
  for (auto [p, k] : ps) res *= power(p, k-1) * (p-1);
  return res;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "totient.cpp"

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

ll power(ll e, int t, ll mod = INF_LL) {
  ll res = 1;
  while (t) {
    if (t&1) res = (res * e) % mod;
    t >>= 1;
    e = (e * e) % mod;
  }
  return res;
}

ll phi(ll n) {
  auto ps = factorize(n);
  ll res = 1;
  for (auto [p, k] : ps) res *= power(p, k-1) * (p-1);
  return res;
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

