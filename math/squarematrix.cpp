#pragma once

#include "template.cpp"
#include "util/doubling.cpp"

template <typename M = ll>
class SquareMatrix {
 public:
  using arr = vector<M>;
  using mat = vector<arr>;
  int n;

 private:
  mat dat;

  SquareMatrix(int n_) : n(n_), dat(n, arr(n)) {}
  SquareMatrix(const mat& dat_) : n(dat_.size()), dat(dat_) {}

  bool operator==(const SquareMatrix& rhs) const { return dat == rhs.dat; }
  bool operator!=(const SquareMatrix& rhs) const { return dat != rhs.dat; }

  size_t size() const { return n; }
  arr& operator[](size_t k) { return dat[k]; }
  const arr& operator[](size_t k) const { return dat[k]; }

  static SquareMatrix mul_unit(int n) {
    SquareMatrix res(n);
    rep(i, n) res[i][i] = M(1);
    return res;
  }

  SquareMatrix operator*(const SquareMatrix& rhs) const {
    SquareMatrix res(n);
    rep(i, n) rep(j, n) rep(k, n) res[i][j] += (dat[i][k] * rhs[k][j]);
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
      for (size_t j = 0; j < n; j++) res[i][j] = dat[i][j] + rhs[i][j];
    return res;
  }

  SquareMatrix pow(ll exp) const {
    using Doubling = Doubling<SquareMatrix, multiplies<SquareMatrix>>;
    return Doubling::pow(*this, exp, mul_unit(n));
  }

  SquareMatrix transpose() const {
    SquareMatrix res = *this;
    rep(i, n) rep(j, i + 1, n) swap(res.dat[i][j], res.dat[j][i]);
    return res;
  }
};
