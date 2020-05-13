#pragma once

#include "template.cpp"
#include "math/modint.cpp"

template <ll Mod>
vector<modint<Mod>> prepare_inv(int n) {
  n++;
  vector<modint<Mod>> res(n);
  res[1] = modint<Mod>(1);
  rep(i, 2, n) res[i] = -res[Mod % i] * modint<Mod>(Mod / i);
  return res;
}
