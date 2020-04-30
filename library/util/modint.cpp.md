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


# :warning: util/modint.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05c7e24700502a079cdd88012b5a76d3">util</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/modint.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-30 16:08:59+09:00




## Required by

* :warning: <a href="../math/garner_ntt.cpp.html">math/garner_ntt.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

template <ll> class modint;
template <ll MOD> constexpr modint<MOD> pow(modint<MOD>, ll);

template <ll MOD = 1000000007>
class modint {
public:
  ll value;

  constexpr modint(const ll x = 0) noexcept : value(x) {
    value %= MOD;
    if (value < 0) value += MOD;
  }
  constexpr bool operator==(const modint<MOD>& rhs) {
    return value == rhs.value;
  }
  constexpr bool operator!=(const modint<MOD>& rhs) {
    return value != rhs.value;
  }
  constexpr modint<MOD> operator-() const {
    return modint<MOD>(0) - *this;
  }
  constexpr modint<MOD> operator+(const modint<MOD>& rhs) const {
    return modint<MOD>(*this) += rhs;
  }
  constexpr modint<MOD> operator-(const modint<MOD>& rhs) const {
    return modint<MOD>(*this) -= rhs;
  }
  constexpr modint<MOD> operator*(const modint<MOD>& rhs) const {
    return modint<MOD>(*this) *= rhs;
  }
  constexpr modint<MOD> operator/(const modint<MOD>& rhs) const {
    return modint<MOD>(*this) /= rhs;
  }
  constexpr modint<MOD>& operator+=(const modint<MOD>& rhs) {
    value += rhs.value;
    if (value >= MOD) value -= MOD;
    return *this;
  }
  constexpr modint<MOD>& operator-=(const modint<MOD>& rhs) {
    if (value < rhs.value) value += MOD;
    value -= rhs.value;
    return *this;
  }
  constexpr modint<MOD>& operator*=(const modint<MOD>& rhs) {
    value = value * rhs.value % MOD;
    return *this;
  }
  constexpr modint<MOD>& operator/=(const modint<MOD>& rhs) {
    return *this *= pow(rhs, MOD - 2);
  }
  constexpr modint<MOD>& operator++() {
    return *this += 1;
  }
  constexpr modint<MOD> operator++(int) {
    modint<MOD> tmp(*this);
    ++(*this);
    return tmp;
  }
  constexpr modint<MOD>& operator--() {
    return *this -= 1;
  }
  constexpr modint<MOD> operator--(int) {
    modint<MOD> tmp(*this);
    --(*this);
    return tmp;
  }
  constexpr operator int() const {
    return (int)value;
  }
  constexpr operator ll() const {
    return value;
  }
};


template <typename OutStream, ll MOD>
OutStream& operator<<(OutStream& out, modint<MOD> n) {
  out << n.value;
  return out;
}

template <typename InStream, ll MOD>
InStream& operator>>(InStream& in, modint<MOD>& n) {
  ll var; in >> var; n = modint<MOD>(var);
  return in;
}

template <ll MOD>
constexpr modint<MOD> pow(modint<MOD> base, ll exp) {
  modint<MOD> res = 1;
  while (exp) {
    if (exp % 2) res *= base;
    base *= base;
    exp /= 2;
  }
  return res;
}

// O(r + log MOD)
template <ll MOD>
modint<MOD> choose(int n, int r) {
  chmin(r, n-r);
  if (r < 0) return modint<MOD>(0);
  modint<MOD> nu = 1, de = 1;
  rep(i, r) nu *= n-i, de *= i+1;
  return nu / de;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "util/modint.cpp"

template <ll> class modint;
template <ll MOD> constexpr modint<MOD> pow(modint<MOD>, ll);

template <ll MOD = 1000000007>
class modint {
public:
  ll value;

  constexpr modint(const ll x = 0) noexcept : value(x) {
    value %= MOD;
    if (value < 0) value += MOD;
  }
  constexpr bool operator==(const modint<MOD>& rhs) {
    return value == rhs.value;
  }
  constexpr bool operator!=(const modint<MOD>& rhs) {
    return value != rhs.value;
  }
  constexpr modint<MOD> operator-() const {
    return modint<MOD>(0) - *this;
  }
  constexpr modint<MOD> operator+(const modint<MOD>& rhs) const {
    return modint<MOD>(*this) += rhs;
  }
  constexpr modint<MOD> operator-(const modint<MOD>& rhs) const {
    return modint<MOD>(*this) -= rhs;
  }
  constexpr modint<MOD> operator*(const modint<MOD>& rhs) const {
    return modint<MOD>(*this) *= rhs;
  }
  constexpr modint<MOD> operator/(const modint<MOD>& rhs) const {
    return modint<MOD>(*this) /= rhs;
  }
  constexpr modint<MOD>& operator+=(const modint<MOD>& rhs) {
    value += rhs.value;
    if (value >= MOD) value -= MOD;
    return *this;
  }
  constexpr modint<MOD>& operator-=(const modint<MOD>& rhs) {
    if (value < rhs.value) value += MOD;
    value -= rhs.value;
    return *this;
  }
  constexpr modint<MOD>& operator*=(const modint<MOD>& rhs) {
    value = value * rhs.value % MOD;
    return *this;
  }
  constexpr modint<MOD>& operator/=(const modint<MOD>& rhs) {
    return *this *= pow(rhs, MOD - 2);
  }
  constexpr modint<MOD>& operator++() {
    return *this += 1;
  }
  constexpr modint<MOD> operator++(int) {
    modint<MOD> tmp(*this);
    ++(*this);
    return tmp;
  }
  constexpr modint<MOD>& operator--() {
    return *this -= 1;
  }
  constexpr modint<MOD> operator--(int) {
    modint<MOD> tmp(*this);
    --(*this);
    return tmp;
  }
  constexpr operator int() const {
    return (int)value;
  }
  constexpr operator ll() const {
    return value;
  }
};


template <typename OutStream, ll MOD>
OutStream& operator<<(OutStream& out, modint<MOD> n) {
  out << n.value;
  return out;
}

template <typename InStream, ll MOD>
InStream& operator>>(InStream& in, modint<MOD>& n) {
  ll var; in >> var; n = modint<MOD>(var);
  return in;
}

template <ll MOD>
constexpr modint<MOD> pow(modint<MOD> base, ll exp) {
  modint<MOD> res = 1;
  while (exp) {
    if (exp % 2) res *= base;
    base *= base;
    exp /= 2;
  }
  return res;
}

// O(r + log MOD)
template <ll MOD>
modint<MOD> choose(int n, int r) {
  chmin(r, n-r);
  if (r < 0) return modint<MOD>(0);
  modint<MOD> nu = 1, de = 1;
  rep(i, r) nu *= n-i, de *= i+1;
  return nu / de;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

