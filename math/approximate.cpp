#pragma once

bool operator <(PLL x, PLL y) {
  return x.first * y.second < x.second * y.first;
}

PLL operator +(PLL x, PLL y) {
  return {x.first + y.first, x.second + y.second};
}

// http://www.kurims.kyoto-u.ac.jp/~kyodo/kokyuroku/contents/pdf/1199-22.pdf
// returns the best rational approximation of x
PLL approximate(double x, ll max_denom = 1000000) {
  int sign = 1;
  if (x < 0) x = -x, sign = -1;
  ll a = x, p0 = 1, q0 = 0, p1 = a, q1 = 1, p2, q2;
  while (x != a) {
    x = 1 / (x - a);
    a = x;
    p2 = a * p1 + p0;
    q2 = a * q1 + q0;
    if (q2 > max_denom or q2 < 0) break;
    p0 = p1; p1 = p2;
    q0 = q1; q1 = q2;
  }
  return {p1 * sign, q1};
}

// return the fraction in (L, R) with minimal numerator/denominator
PLL stern_brocot(PLL L, PLL R) {
  PLL res = fix([&](auto f, auto l, auto r)->PLL{
    PLL mid = l + r;
    if (not (L < mid)) {
      PLL add = r;
      while (not (L < l + add)) l = l + add, add = add + add;
      return f(l, r);
    } else if (not (mid < R)) {
      PLL add = l;
      while (not (add + r < R)) r = r + add, add = add + add;
      return f(l, r);
    } else return mid;
  })(PLL{0, 1}, PLL{1, 0});
}
