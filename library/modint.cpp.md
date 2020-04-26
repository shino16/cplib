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


# :warning: modint.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/modint.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-13 19:27:29+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
class modint;
constexpr modint pow(modint, size_t);
constexpr ll MOD = 1000000007;

class modint {
public:
  ll value;

  constexpr modint(const ll x = 0) noexcept : value(x) {
    value %= MOD;
    if (value < 0) value += MOD;
  }
  constexpr bool operator==(const modint& rhs) {
    return value == rhs.value;
  }
  constexpr bool operator!=(const modint& rhs) {
    return value != rhs.value;
  }
  constexpr modint operator-() const {
    return modint(0) - *this;
  }
  constexpr modint operator+(const modint& rhs) const {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint& rhs) const {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint& rhs) const {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint& rhs) const {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint& rhs) {
    value += rhs.value;
    if (value >= MOD) value -= MOD;
    return *this;
  }
  constexpr modint &operator-=(const modint& rhs) {
    if (value < rhs.value) value += MOD;
    value -= rhs.value;
    return *this;
  }
  constexpr modint &operator*=(const modint& rhs) {
    value = value * rhs.value % MOD;
    return *this;
  }
  constexpr modint &operator/=(const modint& rhs) {
    return *this *= pow(rhs, MOD - 2);
  }
  constexpr modint &operator++() {
    return *this += 1;
  }
  constexpr modint operator++(int) {
    modint tmp(*this);
    ++(*this);
    return tmp;
  }
  constexpr modint &operator--() {
    return *this -= 1;
  }
  constexpr modint operator--(int) {
    modint tmp(*this);
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


template <typename OutStream>
OutStream& operator<<(OutStream& out, modint n) {
  out << n.value;
  return out;
}

template <typename InStream>
InStream& operator>>(InStream& in, modint& n) {
  ll var; in >> var; n = modint(var);
  return in;
}

constexpr modint pow(modint base, size_t exp) {
  modint res = 1;
  while (exp) {
    if (exp % 2) res *= base;
    base *= base;
    exp /= 2;
  }
  return res;
}

// O(r + log MOD)
modint choose(int n, int r) {
  chmin(r, n-r);
  if (r < 0) return modint(0);
  modint nu = 1, de = 1;
  rep(i, r) nu *= n-i, de *= i+1;
  return nu / de;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "modint.cpp"
class modint;
constexpr modint pow(modint, size_t);
constexpr ll MOD = 1000000007;

class modint {
public:
  ll value;

  constexpr modint(const ll x = 0) noexcept : value(x) {
    value %= MOD;
    if (value < 0) value += MOD;
  }
  constexpr bool operator==(const modint& rhs) {
    return value == rhs.value;
  }
  constexpr bool operator!=(const modint& rhs) {
    return value != rhs.value;
  }
  constexpr modint operator-() const {
    return modint(0) - *this;
  }
  constexpr modint operator+(const modint& rhs) const {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint& rhs) const {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint& rhs) const {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint& rhs) const {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint& rhs) {
    value += rhs.value;
    if (value >= MOD) value -= MOD;
    return *this;
  }
  constexpr modint &operator-=(const modint& rhs) {
    if (value < rhs.value) value += MOD;
    value -= rhs.value;
    return *this;
  }
  constexpr modint &operator*=(const modint& rhs) {
    value = value * rhs.value % MOD;
    return *this;
  }
  constexpr modint &operator/=(const modint& rhs) {
    return *this *= pow(rhs, MOD - 2);
  }
  constexpr modint &operator++() {
    return *this += 1;
  }
  constexpr modint operator++(int) {
    modint tmp(*this);
    ++(*this);
    return tmp;
  }
  constexpr modint &operator--() {
    return *this -= 1;
  }
  constexpr modint operator--(int) {
    modint tmp(*this);
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


template <typename OutStream>
OutStream& operator<<(OutStream& out, modint n) {
  out << n.value;
  return out;
}

template <typename InStream>
InStream& operator>>(InStream& in, modint& n) {
  ll var; in >> var; n = modint(var);
  return in;
}

constexpr modint pow(modint base, size_t exp) {
  modint res = 1;
  while (exp) {
    if (exp % 2) res *= base;
    base *= base;
    exp /= 2;
  }
  return res;
}

// O(r + log MOD)
modint choose(int n, int r) {
  chmin(r, n-r);
  if (r < 0) return modint(0);
  modint nu = 1, de = 1;
  rep(i, r) nu *= n-i, de *= i+1;
  return nu / de;
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

