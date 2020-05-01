#pragma once

#include "template.cpp"

class Acc_2D {
private:
  VVLL data;

public:
  // arr must be non-empty
  template <typename Arr>
  Acc_2D(const Arr& arr, int h, int w): data(make_v(h+1, w+1, 0LL)) {
    rep(r, h) rep(c, w) data[r+1][c+1] += data[r+1][c] + arr[r][c];
    rep(r, h) rep(c, w) data[r+1][c+1] += data[r][c+1];
  }

  ll operator()(int r, int c) {
    return data[r][c];
  }

  ll operator()(int r1, int c1, int r2, int c2) {
    return data[r2][c2] - data[r1][c2] - data[r2][c1] + data[r1][c1];
  }
};
