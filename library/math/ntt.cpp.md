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


# :warning: math/ntt.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/ntt.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 23:28:13+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

constexpr ll bmds(int x) {
  const ll v[] = {1012924417, 924844033, 998244353, 897581057, 645922817};
  return v[x];
}
constexpr int brts(int x) {  // primitive roots
  const int v[] = {5, 5, 3, 3, 3};
  return v[x];
}
template <int X>
class NTT {
 public:
  static constexpr int md = bmds(X);
  static constexpr int rt = brts(X);
  using M = modint<md>;

 private:
  vector<vector<M>> rts, rrts;

  void ensure_base(int n) {
    if ((int)rts.size() >= n) return;
    rts.resize(n);
    rrts.resize(n);
    for (int i = 1; i < n; i <<= 1) {
      if (!rts[i].empty()) continue;
      M w = pow(M(rt), (md - 1) / (i << 1));
      M rw = M(1) / w;
      rts[i].resize(i);
      rrts[i].resize(i);
      rts[i][0] = M(1);
      rrts[i][0] = M(1);
      for (int k = 1; k < i; k++) {
        rts[i][k] = rts[i][k - 1] * w;
        rrts[i][k] = rrts[i][k - 1] * rw;
      }
    }
  }

 public:
  void ntt(vector<M>& as, bool f) {
    int n = as.size();
    assert((n & (n - 1)) == 0);
    ensure_base(n);

    for (int i = 0, j = 1; j + 1 < n; j++) {
      for (int k = n >> 1; k > (i ^= k); k >>= 1)
        ;
      if (i > j) swap(as[i], as[j]);
    }

    for (int i = 1; i < n; i <<= 1) {
      for (int j = 0; j < n; j += i * 2) {
        for (int k = 0; k < i; k++) {
          M z = as[i + j + k] * (f ? rrts[i][k] : rts[i][k]);
          as[i + j + k] = as[j + k] - z;
          as[j + k] += z;
        }
      }
    }

    if (f) {
      M tmp = M(1) / M(n);
      for (int i = 0; i < n; i++) as[i] *= tmp;
    }
  }

  vector<M> multiply(vector<M> as, vector<M> bs) {
    int need = as.size() + bs.size() - 1;
    int sz = 1;
    while (sz < need) sz <<= 1;
    as.resize(sz, M(0));
    bs.resize(sz, M(0));

    ntt(as, 0);
    ntt(bs, 0);
    for (int i = 0; i < sz; i++) as[i] *= bs[i];
    ntt(as, 1);

    as.resize(need);
    return as;
  }

  vector<int> multiply(vector<int> as, vector<int> bs) {
    vector<M> am(as.size()), bm(bs.size());
    for (int i = 0; i < (int)am.size(); i++) am[i] = M(as[i]);
    for (int i = 0; i < (int)bm.size(); i++) bm[i] = M(bs[i]);
    vector<M> cm = multiply(am, bm);
    vector<int> cs(cm.size());
    for (int i = 0; i < (int)cs.size(); i++) cs[i] = cm[i].value;
    return cs;
  }
};
NTT<2> ntt;  // mod 998244353

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/ntt.cpp"

constexpr ll bmds(int x) {
  const ll v[] = {1012924417, 924844033, 998244353, 897581057, 645922817};
  return v[x];
}
constexpr int brts(int x) {  // primitive roots
  const int v[] = {5, 5, 3, 3, 3};
  return v[x];
}
template <int X>
class NTT {
 public:
  static constexpr int md = bmds(X);
  static constexpr int rt = brts(X);
  using M = modint<md>;

 private:
  vector<vector<M>> rts, rrts;

  void ensure_base(int n) {
    if ((int)rts.size() >= n) return;
    rts.resize(n);
    rrts.resize(n);
    for (int i = 1; i < n; i <<= 1) {
      if (!rts[i].empty()) continue;
      M w = pow(M(rt), (md - 1) / (i << 1));
      M rw = M(1) / w;
      rts[i].resize(i);
      rrts[i].resize(i);
      rts[i][0] = M(1);
      rrts[i][0] = M(1);
      for (int k = 1; k < i; k++) {
        rts[i][k] = rts[i][k - 1] * w;
        rrts[i][k] = rrts[i][k - 1] * rw;
      }
    }
  }

 public:
  void ntt(vector<M>& as, bool f) {
    int n = as.size();
    assert((n & (n - 1)) == 0);
    ensure_base(n);

    for (int i = 0, j = 1; j + 1 < n; j++) {
      for (int k = n >> 1; k > (i ^= k); k >>= 1)
        ;
      if (i > j) swap(as[i], as[j]);
    }

    for (int i = 1; i < n; i <<= 1) {
      for (int j = 0; j < n; j += i * 2) {
        for (int k = 0; k < i; k++) {
          M z = as[i + j + k] * (f ? rrts[i][k] : rts[i][k]);
          as[i + j + k] = as[j + k] - z;
          as[j + k] += z;
        }
      }
    }

    if (f) {
      M tmp = M(1) / M(n);
      for (int i = 0; i < n; i++) as[i] *= tmp;
    }
  }

  vector<M> multiply(vector<M> as, vector<M> bs) {
    int need = as.size() + bs.size() - 1;
    int sz = 1;
    while (sz < need) sz <<= 1;
    as.resize(sz, M(0));
    bs.resize(sz, M(0));

    ntt(as, 0);
    ntt(bs, 0);
    for (int i = 0; i < sz; i++) as[i] *= bs[i];
    ntt(as, 1);

    as.resize(need);
    return as;
  }

  vector<int> multiply(vector<int> as, vector<int> bs) {
    vector<M> am(as.size()), bm(bs.size());
    for (int i = 0; i < (int)am.size(); i++) am[i] = M(as[i]);
    for (int i = 0; i < (int)bm.size(); i++) bm[i] = M(bs[i]);
    vector<M> cm = multiply(am, bm);
    vector<int> cs(cm.size());
    for (int i = 0; i < (int)cs.size(); i++) cs[i] = cm[i].value;
    return cs;
  }
};
NTT<2> ntt;  // mod 998244353

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

