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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: data-structure/BIT.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/BIT.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 18:46:30+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/verify/BIT_compress.test.cpp.html">verify/BIT_compress.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
class BIT {
 public:
  const int n;

 private:
  vector<ll> data;

 public:
  BIT(int _n = 0) : n(_n), data(_n + 1) {}
  void add(int p, ll v = 1) {
    p++;
    while (p <= n) {
      data[p] += v;
      p += p & -p;
    }
  }
  // sum over [0, p)
  ll sum(int p) {
    ll res = 0;
    while (p) {
      res += data[p];
      p -= p & -p;
    }
    return res;
  }
  // sum over [l, r)
  ll sum(int l, int r) { return sum(r) - sum(l); }
  void assign(int p, ll v) { add(p, v - sum(p, p + 1)); }
  bool chmax(int p, ll v) {
    if (sum(p, p + 1) < v) {
      assign(p, v);
      return true;
    } else
      return false;
  }
  // min i s.t. sum over [0, i] >= v
  // requires data[i] >= 0 for any i
  int lower_bound(ll v) {
    if (v <= 0) return 0;
    int l = 0;
    for (int k = 1 << (32 - __builtin_clz(n) - 1); k; k >>= 1)
      if (l + k <= n and data[l + k] < v) v -= data[l += k];
    return l;
  }
  // min i s.t. sum over [0, i] > v
  // requires data[i] >= 0 for any i
  int upper_bound(ll v) { return lower_bound(v + 1); }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/BIT.cpp"
class BIT {
 public:
  const int n;

 private:
  vector<ll> data;

 public:
  BIT(int _n = 0) : n(_n), data(_n + 1) {}
  void add(int p, ll v = 1) {
    p++;
    while (p <= n) {
      data[p] += v;
      p += p & -p;
    }
  }
  // sum over [0, p)
  ll sum(int p) {
    ll res = 0;
    while (p) {
      res += data[p];
      p -= p & -p;
    }
    return res;
  }
  // sum over [l, r)
  ll sum(int l, int r) { return sum(r) - sum(l); }
  void assign(int p, ll v) { add(p, v - sum(p, p + 1)); }
  bool chmax(int p, ll v) {
    if (sum(p, p + 1) < v) {
      assign(p, v);
      return true;
    } else
      return false;
  }
  // min i s.t. sum over [0, i] >= v
  // requires data[i] >= 0 for any i
  int lower_bound(ll v) {
    if (v <= 0) return 0;
    int l = 0;
    for (int k = 1 << (32 - __builtin_clz(n) - 1); k; k >>= 1)
      if (l + k <= n and data[l + k] < v) v -= data[l += k];
    return l;
  }
  // min i s.t. sum over [0, i] > v
  // requires data[i] >= 0 for any i
  int upper_bound(ll v) { return lower_bound(v + 1); }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

