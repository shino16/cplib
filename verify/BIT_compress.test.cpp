#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0343"

#include "template.cpp"
#include "util/compress.cpp"
#include "data-structure/BIT.cpp"

#define D_GLIBCXX_DEBUG

int main() {
  int n = IN, c = IN;

  VI cs(c), ts(c); VLL ps(c);
  rep(i, c) {
    cs[i] = IN, ts[i] = IN;
    if (cs[i] == 0) ts[i]--, ps[i] = IN;
  }

  VLL scores(n);
  Compress<pair<ll, int>> comp;

  rep(i, n) comp.emplace(scores[i], -i);
  rep(i, c) if (cs[i] == 0)
      comp.emplace(scores[ts[i]] += ps[i], -ts[i]);

  fill(all(scores), 0);

  BIT bit(comp.size());
  rep(i, n) bit.add(comp[make_pair(0, -i)], 1);

  rep(i, c) {
    if (cs[i] == 0) {
      bit.add(comp[make_pair(scores[ts[i]], -ts[i])], -1);
      bit.add(comp[make_pair(scores[ts[i]] += ps[i], -ts[i])], 1);
    } else {
      int s = bit.upper_bound(n - ts[i]);
      OUT(-comp.restore(s).second+1, comp.restore(s).first);
    }
  }
}
