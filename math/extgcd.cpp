#pragma once

#include "template.cpp"

array<ll, 3> extgcd(ll a, ll b) {
  if (b == 0) return {1, 0, a};
  ll q = a / b, r = a % b;
  auto x = extgcd(b, r);
  return {x[1], x[0] - q * x[1], x[2]};
}
