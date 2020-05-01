#pragma once

#include "template.cpp"

ll totient(ll n) {
  auto ps = factorize(n);
  ll res = 1;
  for (auto [p, k] : ps) res *= power(p, k-1) * (p-1);
  return res;
}
