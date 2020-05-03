#pragma once

#include "template.cpp"

template <typename M>
vector<M> prepare_inv(int n) {
  n++;
  vector<M> res(n);
  res[1] = M(1);
  rep(i, 2, n) res[i] = -res[M::Mod % i] * M(M::Mod / i);
  return res;
}
