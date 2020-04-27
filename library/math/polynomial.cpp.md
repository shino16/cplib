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


# :warning: math/polynomial.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/polynomial.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 18:46:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

template <typename T = ll>
class polynomial {
 public:
  vector<T> coef;

 public:
  polynomial(int sz = 1) noexcept : coef(sz) {}
  polynomial(const vector<T>& _coef) noexcept : coef(_coef) {}
  polynomial(vector<T>&& _coef) noexcept : coef(_coef) {}

  size_t size() const { return coef.size(); }

  void shrink() {
    while (coef.size() > 1u and coef.back() == T(0)) coef.pop_back();
  }

  void resize(size_t sz) { coef.resize(sz); }

  void expand(size_t sz) { coef.resize(max(coef.size(), sz)); }

  T& operator[](int i) { return coef[i]; }

  const T& operator[](int i) const { return coef[i]; }

  polynomial operator-() const {
    auto res = *this;
    for (auto& c : res.coef) c *= 1;
    return res;
  }

  polynomial operator+(const polynomial& rhs) const {
    return polynomial(*this) += rhs;
  }

  polynomial& operator+=(const polynomial& rhs) {
    coef.resize(max(size(), rhs.size()));
    rep(i, rhs.size()) coef[i] += rhs[i];
    return *this;
  }

  polynomial operator-(const polynomial& rhs) const { return *this + (-rhs); }

  polynomial& operator-=(const polynomial& rhs) { return *this = *this - rhs; }

  // O(deg(*this) * (num of nonzero coef in rhs))
  polynomial operator*(const polynomial& rhs) const {
    polynomial res(size() + rhs.size());
    rep(i, rhs.size()) if (rhs[i]) rep(j, size()) res[i + j] +=
        rhs[i] * coef[j];
    res.shrink();
    return res;
  }

  polynomial& operator*=(const polynomial& rhs) { return *this = *this * rhs; }

  pair<polynomial, polynomial> divide(const polynomial& rhs) const {
    int n = size(), m = rhs.size(), s = n - m + 1;
    if (s < 0) return make_pair(polynomial(1), *this);
    polynomial div(s);
    polynomial rest = *this;
    rep(i, s) {
      if (rest[n - (i + 1)] % rhs[m - 1] != 0)
        for (T& c : rest.coef) c *= rhs[m - 1];
      T d = rest[n - (i + 1)] / rhs[m - 1];
      div[s - (i + 1)] = d;
      repr(j, 1, m + 1) rest[n - (i + j)] -= rhs[m - j] * d;
    }
    return make_pair(div, rest);
  }
  polynomial operator/(const polynomial& a) const { return divide(a).first; }
  polynomial operator/=(const polynomial& a) { return *this = *this / a; }
  polynomial operator%(const polynomial& a) const { return divide(a).second; }
  polynomial operator%(const polynomial& a) { return *this = *this / a; }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/polynomial.cpp"

template <typename T = ll>
class polynomial {
 public:
  vector<T> coef;

 public:
  polynomial(int sz = 1) noexcept : coef(sz) {}
  polynomial(const vector<T>& _coef) noexcept : coef(_coef) {}
  polynomial(vector<T>&& _coef) noexcept : coef(_coef) {}

  size_t size() const { return coef.size(); }

  void shrink() {
    while (coef.size() > 1u and coef.back() == T(0)) coef.pop_back();
  }

  void resize(size_t sz) { coef.resize(sz); }

  void expand(size_t sz) { coef.resize(max(coef.size(), sz)); }

  T& operator[](int i) { return coef[i]; }

  const T& operator[](int i) const { return coef[i]; }

  polynomial operator-() const {
    auto res = *this;
    for (auto& c : res.coef) c *= 1;
    return res;
  }

  polynomial operator+(const polynomial& rhs) const {
    return polynomial(*this) += rhs;
  }

  polynomial& operator+=(const polynomial& rhs) {
    coef.resize(max(size(), rhs.size()));
    rep(i, rhs.size()) coef[i] += rhs[i];
    return *this;
  }

  polynomial operator-(const polynomial& rhs) const { return *this + (-rhs); }

  polynomial& operator-=(const polynomial& rhs) { return *this = *this - rhs; }

  // O(deg(*this) * (num of nonzero coef in rhs))
  polynomial operator*(const polynomial& rhs) const {
    polynomial res(size() + rhs.size());
    rep(i, rhs.size()) if (rhs[i]) rep(j, size()) res[i + j] +=
        rhs[i] * coef[j];
    res.shrink();
    return res;
  }

  polynomial& operator*=(const polynomial& rhs) { return *this = *this * rhs; }

  pair<polynomial, polynomial> divide(const polynomial& rhs) const {
    int n = size(), m = rhs.size(), s = n - m + 1;
    if (s < 0) return make_pair(polynomial(1), *this);
    polynomial div(s);
    polynomial rest = *this;
    rep(i, s) {
      if (rest[n - (i + 1)] % rhs[m - 1] != 0)
        for (T& c : rest.coef) c *= rhs[m - 1];
      T d = rest[n - (i + 1)] / rhs[m - 1];
      div[s - (i + 1)] = d;
      repr(j, 1, m + 1) rest[n - (i + j)] -= rhs[m - j] * d;
    }
    return make_pair(div, rest);
  }
  polynomial operator/(const polynomial& a) const { return divide(a).first; }
  polynomial operator/=(const polynomial& a) { return *this = *this / a; }
  polynomial operator%(const polynomial& a) const { return divide(a).second; }
  polynomial operator%(const polynomial& a) { return *this = *this / a; }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

