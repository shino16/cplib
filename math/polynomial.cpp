#pragma once

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
