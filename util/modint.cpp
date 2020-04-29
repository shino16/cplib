#pragma once

template <ll> class modint;
template <ll MOD> constexpr modint<MOD> pow(modint<MOD>, size_t);

template <ll MOD = 10000007>
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
  constexpr modint<MOD> &operator+=(const modint<MOD>& rhs) {
    value += rhs.value;
    if (value >= MOD) value -= MOD;
    return *this;
  }
  constexpr modint<MOD> &operator-=(const modint<MOD>& rhs) {
    if (value < rhs.value) value += MOD;
    value -= rhs.value;
    return *this;
  }
  constexpr modint<MOD> &operator*=(const modint<MOD>& rhs) {
    value = value * rhs.value % MOD;
    return *this;
  }
  constexpr modint<MOD> &operator/=(const modint<MOD>& rhs) {
    return *this *= pow(rhs, MOD - 2);
  }
  constexpr modint<MOD> &operator++() {
    return *this += 1;
  }
  constexpr modint<MOD> operator++(int) {
    modint<MOD> tmp(*this);
    ++(*this);
    return tmp;
  }
  constexpr modint<MOD> &operator--() {
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
constexpr modint<MOD> pow(modint<MOD> base, size_t exp) {
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
