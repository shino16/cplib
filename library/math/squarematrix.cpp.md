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


# :warning: math/squarematrix.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/squarematrix.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-30 16:08:59+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

// originally written by @beet-aizu
template <typename M = ll>
struct SquareMatrix {
  using arr = vector<M>;
  using mat = vector<arr>;
  int n;
  mat dat;

  SquareMatrix(int _n) : n(_n), dat(n, arr(n)) {}

  SquareMatrix(const mat& _dat) : n(_dat.size()), dat(_dat) {}

  bool operator==(const SquareMatrix& rhs) const { return dat == rhs.dat; }
  bool operator!=(const SquareMatrix& rhs) const { return dat != rhs.dat; }

  size_t size() const { return n; }
  arr& operator[](size_t k) { return dat[k]; }
  const arr& operator[](size_t k) const { return dat[k]; }

  SquareMatrix add_identity() const { return SquareMatrix(); }
  SquareMatrix mul_identity() const {
    SquareMatrix res(n);
    rep(i, n) res[i][i] = M(1);
    return res;
  }

  SquareMatrix operator*(const SquareMatrix& rhs) const {
    SquareMatrix res(n);
    rep(i, n) rep(j, n) rep(k, n)
      res[i][j] += (dat[i][k] * rhs[k][j]);
    return res;
  }

  arr operator*(const arr& rhs) const {
    arr res(n);
    rep(i, n) rep(j, n) res[i] += dat[i][j] * rhs[j];
    return res;
  }

  SquareMatrix operator+(const SquareMatrix& rhs) const {
    SquareMatrix res(n);
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < n; j++)
        res[i][j] = dat[i][j] + rhs[i][j];
    return res;
  }

  SquareMatrix pow(ll exp) const {
    SquareMatrix a = *this, res = mul_identity();
    while (exp) {
      if (exp & 1) res = res * a;
      a = a * a;
      exp >>= 1;
    }
    return res;
  }

  SquareMatrix transpose() const {
    SquareMatrix res = *this;
    rep(i, n) rep(j, i + 1, n) swap(res.dat[i][j], res.dat[j][i]);
    return res;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/squarematrix.cpp"

// originally written by @beet-aizu
template <typename M = ll>
struct SquareMatrix {
  using arr = vector<M>;
  using mat = vector<arr>;
  int n;
  mat dat;

  SquareMatrix(int _n) : n(_n), dat(n, arr(n)) {}

  SquareMatrix(const mat& _dat) : n(_dat.size()), dat(_dat) {}

  bool operator==(const SquareMatrix& rhs) const { return dat == rhs.dat; }
  bool operator!=(const SquareMatrix& rhs) const { return dat != rhs.dat; }

  size_t size() const { return n; }
  arr& operator[](size_t k) { return dat[k]; }
  const arr& operator[](size_t k) const { return dat[k]; }

  SquareMatrix add_identity() const { return SquareMatrix(); }
  SquareMatrix mul_identity() const {
    SquareMatrix res(n);
    rep(i, n) res[i][i] = M(1);
    return res;
  }

  SquareMatrix operator*(const SquareMatrix& rhs) const {
    SquareMatrix res(n);
    rep(i, n) rep(j, n) rep(k, n)
      res[i][j] += (dat[i][k] * rhs[k][j]);
    return res;
  }

  arr operator*(const arr& rhs) const {
    arr res(n);
    rep(i, n) rep(j, n) res[i] += dat[i][j] * rhs[j];
    return res;
  }

  SquareMatrix operator+(const SquareMatrix& rhs) const {
    SquareMatrix res(n);
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < n; j++)
        res[i][j] = dat[i][j] + rhs[i][j];
    return res;
  }

  SquareMatrix pow(ll exp) const {
    SquareMatrix a = *this, res = mul_identity();
    while (exp) {
      if (exp & 1) res = res * a;
      a = a * a;
      exp >>= 1;
    }
    return res;
  }

  SquareMatrix transpose() const {
    SquareMatrix res = *this;
    rep(i, n) rep(j, i + 1, n) swap(res.dat[i][j], res.dat[j][i]);
    return res;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

