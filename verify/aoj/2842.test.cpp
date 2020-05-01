#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"

#include "template.cpp"
#include "data-structure/bit-2d.cpp"

int main() {
  int h = IN, w = IN, T = IN, q = IN;

  queue<pair<int, PII>> trans;
  BIT_2D A(h, w), B(h, w);

  rep(q) {
    int t = IN, cmd = IN, r = IN1, c = IN1;

    while (not trans.empty() and trans.front().first <= t) {
      PII p; tie(ignore, p) = trans.front(); trans.pop();
      A.add(p.first, p.second, -1);
      B.add(p.first, p.second, +1);
    }

    if (cmd == 0) {
      A.add(r, c, +1);
      trans.emplace(t+T, PII{r, c});
    } else if (cmd == 1) {
      if (B.sum(r, c, r+1, c+1))
        B.add(r, c, -1);
    } else {
      int r2 = IN, c2 = IN;
      OUT(B.sum(r, c, r2, c2), A.sum(r, c, r2, c2));
    }
  }
}