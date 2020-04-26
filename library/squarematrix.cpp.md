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


# :warning: squarematrix.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/squarematrix.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 15:09:17+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

// originally written by @beet-aizu
template <typename M = ll>
struct SquareMatrix {
  typedef vector<M> arr;
  typedef vector<arr> mat;
  const int n;
  mat dat;

  SquareMatrix(int _n) : n(_n), dat(n, arr(n)) {
    for (size_t i = 0; i < N; i++)
      for (size_t j = 0; j < N; j++) dat[i][j] = M(0);
  }

  SquareMatrix(const mat& _dat) : n(_n), dat(_dat) {}

  bool operator==(const SquareMatrix& a) const { return dat == a.dat; }

  size_t size() const { return N; }
  arr& operator[](size_t k) { return dat[k]; }
  const arr& operator[](size_t k) const { return dat[k]; }

  static SquareMatrix add_identity() { return SquareMatrix(); }
  static SquareMatrix mul_identity() {
    SquareMatrix res;
    for (size_t i = 0; i < N; i++) res[i][i] = M(1);
    return res;
  }

  SquareMatrix operator*(const SquareMatrix& B) const {
    SquareMatrix res;
    for (size_t i = 0; i < N; i++)
      for (size_t j = 0; j < N; j++)
        for (size_t k = 0; k < N; k++)
          res[i][j] = res[i][j] + (dat[i][k] * B[k][j]);
    return res;
  }

  SquareMatrix operator+(const SquareMatrix& B) const {
    SquareMatrix res;
    for (size_t i = 0; i < N; i++)
      for (size_t j = 0; j < N; j++)
        res[i][j] = dat[i][j] + B[i][j];
    return res;
  }

  SquareMatrix pow(long long n) const {
    SquareMatrix a = *this, res = mul_identity();
    while (n) {
      if (n & 1) res = res * a;
      a = a * a;
      n >>= 1;
    }
    return res;
  }

  SquareMatrix transpose() const {
    SquareMatrix res = *this;
    rep(i, N) rep(j, i + 1, N) swap(res.dat[i][j], res.dat[j][i]);
    return res;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "squarematrix.cpp"

// originally written by @beet-aizu
template <typename M = ll>
struct SquareMatrix {
  typedef vector<M> arr;
  typedef vector<arr> mat;
  const int n;
  mat dat;

  SquareMatrix(int _n) : n(_n), dat(n, arr(n)) {
    for (size_t i = 0; i < N; i++)
      for (size_t j = 0; j < N; j++) dat[i][j] = M(0);
  }

  SquareMatrix(const mat& _dat) : n(_n), dat(_dat) {}

  bool operator==(const SquareMatrix& a) const { return dat == a.dat; }

  size_t size() const { return N; }
  arr& operator[](size_t k) { return dat[k]; }
  const arr& operator[](size_t k) const { return dat[k]; }

  static SquareMatrix add_identity() { return SquareMatrix(); }
  static SquareMatrix mul_identity() {
    SquareMatrix res;
    for (size_t i = 0; i < N; i++) res[i][i] = M(1);
    return res;
  }

  SquareMatrix operator*(const SquareMatrix& B) const {
    SquareMatrix res;
    for (size_t i = 0; i < N; i++)
      for (size_t j = 0; j < N; j++)
        for (size_t k = 0; k < N; k++)
          res[i][j] = res[i][j] + (dat[i][k] * B[k][j]);
    return res;
  }

  SquareMatrix operator+(const SquareMatrix& B) const {
    SquareMatrix res;
    for (size_t i = 0; i < N; i++)
      for (size_t j = 0; j < N; j++)
        res[i][j] = dat[i][j] + B[i][j];
    return res;
  }

  SquareMatrix pow(long long n) const {
    SquareMatrix a = *this, res = mul_identity();
    while (n) {
      if (n & 1) res = res * a;
      a = a * a;
      n >>= 1;
    }
    return res;
  }

  SquareMatrix transpose() const {
    SquareMatrix res = *this;
    rep(i, N) rep(j, i + 1, N) swap(res.dat[i][j], res.dat[j][i]);
    return res;
  }
};

```
{% endraw %}

<a href="../index.html">Back to top page</a>

