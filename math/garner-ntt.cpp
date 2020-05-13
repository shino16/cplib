#pragma once

#include "math/ntt.cpp"
#include "template.cpp"
#include "math/modint.cpp"

namespace Garner {

static NTT<0> ntt0;
static NTT<1> ntt1;
static NTT<2> ntt2;

static ll inv(ll x, ll md) { return power(x, md - 2, md); }

ll garner(ll c0, ll c1, ll c2, ll m01, ll mod) {
  static ll r01 = inv(ntt0.md, ntt1.md);
  static ll r02 = inv(ntt0.md, ntt2.md);
  static ll r12 = inv(ntt1.md, ntt2.md);

  c1 = (ll)(c1 - c0) * r01 % ntt1.md;
  if (c1 < 0) c1 += ntt1.md;

  c2 = (ll)(c2 - c0) * r02 % ntt2.md;
  c2 = (ll)(c2 - c1) * r12 % ntt2.md;
  if (c2 < 0) c2 += ntt2.md;

  c0 %= mod;
  c0 += (ll)c1 * ntt0.md % mod;
  if (c0 >= mod) c0 -= mod;
  c0 += (ll)c2 * m01 % mod;
  if (c0 >= mod) c0 -= mod;

  return c0;
}

vector<ll> garner(vector<vector<ll>> &cs, ll mod) {
  ll m01 = (ll)ntt0.md * ntt1.md % mod;
  ll sz = cs[0].size();
  vector<ll> res(sz);
  for (ll i = 0; i < sz; i++)
    res[i] = garner(cs[0][i], cs[1][i], cs[2][i], m01, mod);
  return res;
}

vector<ll> multiply(vector<ll> as, vector<ll> bs, ll mod) {
  vector<vector<ll>> cs(3);
  cs[0] = ntt0.multiply(as, bs);
  cs[1] = ntt1.multiply(as, bs);
  cs[2] = ntt2.multiply(as, bs);
  size_t sz = as.size() + bs.size() - 1;
  for (auto &v : cs) v.resize(sz);
  return garner(cs, mod);
}

template <ll Mod = 1000000007>
vector<modint<Mod>> multiply(vector<modint<Mod>> am, vector<modint<Mod>> bm) {
  vector<ll> as(am.size()), bs(bm.size());
  rep(i, am.size()) as[i] = am[i].v;
  rep(i, bm.size()) bs[i] = bm[i].v;
  vector<ll> cs = multiply(as, bs, Mod);
  vector<modint<Mod>> cm(cs.size());
  rep(i, cs.size()) cm[i] = modint<Mod>(cs[i]);
  return cm;
}

};  // namespace Garner
