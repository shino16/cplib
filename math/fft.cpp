#pragma once

#include "geometry/Pt.cpp"
#include "template.cpp"

// credit to @beet-aizu
namespace FFT {
using dbl = double;

using complex = Pt<dbl>;

inline complex conj(complex a) { return complex(a.x, -a.y); }

int base = 1;
vector<complex> rts = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};

const dbl PI = asinl(1) * 2;

void ensure_base(int nbase) {
  if (nbase <= base) return;

  rev.resize(1 << nbase);
  for (int i = 0; i < (1 << nbase); i++)
    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));

  rts.resize(1 << nbase);
  while (base < nbase) {
    dbl angle = 2 * PI / (1 << (base + 1));
    for (int i = 1 << (base - 1); i < (1 << base); i++) {
      rts[i << 1] = rts[i];
      dbl angle_i = angle * (2 * i + 1 - (1 << base));
      rts[(i << 1) + 1] = complex(cos(angle_i), sin(angle_i));
    }
    base++;
  }
}

template <typename T, typename U>
vector<T> cast(const vector<U>& v) {
  vector<T> res(v.size());
  if (is_integral<T>::value)
    rep(i, v.size()) res[i] = T(round(v[i]));
  else
    copy(all(v), res.begin());
  return res;
}

void fft(vector<complex>& as) {
  int n = as.size();
  assert((n & (n - 1)) == 0);

  int zeros = __builtin_ctz(n);
  ensure_base(zeros);
  int shift = base - zeros;
  for (int i = 0; i < n; i++)
    if (i < (rev[i] >> shift)) swap(as[i], as[rev[i] >> shift]);

  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; j++) {
        complex z = as[i + j + k] * rts[j + k];
        as[i + j + k] = as[i + j] - z;
        as[i + j] = as[i + j] + z;
      }
    }
  }
}

template <typename T>
vector<T> multiply(const vector<T>& as, const vector<T>& bs) {
  int need = as.size() + bs.size() - 1;
  int nbase = need <= 1 ? 0 : 32 - __builtin_clz(need - 1);  // ceil(log2(n))
  ensure_base(nbase + 1);

  int sz = 1 << nbase;
  vector<complex> fa(sz);
  rep(i, as.size()) fa[i].x = dbl(as[i]);
  rep(i, bs.size()) fa[i].y = dbl(bs[i]);
  fft(fa);

  complex r(0, -0.25 / sz);
  for (int i = 0; i <= (sz >> 1); i++) {
    int j = (sz - i) & (sz - 1);
    complex z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
    if (i != j) fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
    fa[i] = z;
  }
  fft(fa);

  vector<T> res(need);
  rep(i, need) res[i] = fa[i].x;

  return res;
}

template <typename T>
vector<dbl> div(vector<T>& as, vector<T>& bs) {
  static vector<dbl> q_rev;
  static vector<vector<dbl>> t;  // t[i] * bs == 0 mod x^2^i

  while (bs.back() == 0) bs.pop_back();
  if (not equal(all(bs), rall(q_rev))) {
    q_rev.resize(bs.size());
    copy(rall(bs), q_rev.begin());
    t.clear();
    t.emplace_back(vector<dbl>{1 / q_rev[0]});
  }

  int n = as.size(), m = bs.size();
  int k = 32 - __builtin_clz(n - m);  // ceil(log2(n-m+1))
  rep((1 << k) - n) as.emplace_back(dbl(0));
  n = as.size();

  rep(k + 1 - t.size()) {
    vector<dbl> next = multiply(multiply(t.back(), t.back()), q_rev);
    next.resize(1 << t.size());
    for (auto& a : next) a *= -1;
    rep(i, t.back().size()) next[i] += t.back()[i] * 2;
    t.emplace_back(move(next));
  }

  reverse(all(as));
  vector<dbl> res = multiply(t[k], vector<dbl>(all(as)));
  res.resize(n - m + 1);
  reverse(all(as));
  reverse(all(res));

  return res;
}

template <typename Vector>
vector<dbl> div(Vector&& as, Vector&& bs) {
  return div(as, bs);
}

template <typename T>
pair<vector<dbl>, vector<dbl>> divmod(vector<T>& as, vector<T>& bs,
                                      dbl eps = 1e-9) {
  vector<dbl> q = div(as, bs);
  vector<dbl> r = multiply(q, cast<dbl>(bs));
  r.resize(as.size());
  rep(i, r.size()) r[i] = as[i] - r[i];
  while (r.size() > 1 and abs(r.back()) < eps) r.pop_back();
  return make_pair(q, r);
}

template <typename Vector>
pair<vector<dbl>, vector<dbl>> divmod(Vector&& as, Vector&& bs,
                                      dbl eps = 1e-9) {
  return divmod(as, bs, eps);
}

template <typename Vector>
vector<dbl> mod(Vector&& as, Vector&& bs, dbl eps = 1e-9) {
  return divmod(as, bs, eps).second;
}

};  // namespace FFT
