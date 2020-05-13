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
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "template.cpp"
#include "util/modint.cpp"

constexpr ll mods(int x) {
  const ll v[] = {1012924417, 924844033, 998244353, 897581057, 645922817};
  return v[x];
}

constexpr int primitive_roots(int x) {
  const int v[] = {5, 5, 3, 3, 3};
  return v[x];
}

template <int X = 2>
class NTT {
 public:
  static constexpr int md = mods(X);
  static constexpr int rt = primitive_roots(X);
  using mint = modint<md>;

 private:
  vector<vector<mint>> root, rroot;

  void prepare(int n) {
    if (root.size() >= n) return;
    root.resize(n);
    rroot.resize(n);
    for (int i = 1; i < n; i <<= 1) {
      if (!root[i].empty()) continue;
      mint w = pow(mint(rt), (md - 1) / (i << 1));
      mint rw = mint(1) / w;
      root[i].resize(i);
      rroot[i].resize(i);
      root[i][0] = mint(1);
      rroot[i][0] = mint(1);
      rep(k, 1, i) root[i][k] = root[i][k - 1] * w,
                   rroot[i][k] = rroot[i][k - 1] * rw;
    }
  }

 public:
  void ntt(vector<mint>& A, bool reverse) {
    int n = A.size();
    assert((n & (n - 1)) == 0);
    prepare(n);

    for (int i = 0, j = 1; j + 1 < n; j++) {
      for (int k = n >> 1; k > (i ^= k); k >>= 1) {}
      if (i > j) swap(A[i], A[j]);
    }

    for (int i = 1; i < n; i <<= 1) {
      for (int j = 0; j < n; j += i * 2) {
        for (int k = 0; k < i; k++) {
          mint z = A[i + j + k] * (reverse ? rroot[i][k] : root[i][k]);
          A[i + j + k] = A[j + k] - z;
          A[j + k] += z;
        }
      }
    }

    if (reverse) {
      mint tmp = mint(1) / mint(n);
      rep(i, n) A[i] *= tmp;
    }
  }

  vector<mint> multiply(vector<mint> A, vector<mint> B) {
    int need = A.size() + B.size() - 1;
    int sz = need <= 1 ? 1 : 1 << (32 - __builtin_clz(need - 1));

    A.resize(sz, mint(0));
    B.resize(sz, mint(0));

    ntt(A, 0);
    ntt(B, 0);
    rep(i, sz) A[i] *= B[i];
    ntt(A, 1);

    A.resize(need);
    return A;
  }

  vector<ll> multiply(vector<ll> A, vector<ll> B) {
    vector<mint> am(A.size()), bm(B.size());
    rep(i, am.size()) am[i] = mint(A[i]);
    rep(i, bm.size()) bm[i] = mint(B[i]);
    vector<mint> cm = multiply(am, bm);
    vector<ll> cs(cm.size());
    rep(i, cs.size()) cs[i] = cm[i].value;
    return cs;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 172, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 282, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 162, in _resolve
    raise BundleError(path, -1, "no such header")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: util/modint.cpp: line -1: no such header

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

