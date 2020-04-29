#pragma once

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
