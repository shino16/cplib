#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0355"

#include "template.cpp"
#include "string/rolling-hash.cpp"
#include "data-structure/lazy-segtree.cpp"
#include "string/hash-monoid.cpp"

int main() {
  int n = IN;
  string u = IN;

  LazyHashSegTree hash(all(u), n);

  rep(IN) {
    string cmd = IN;
    if (cmd[0] == 's') {
      int x = IN1, y = IN1; string z = IN;
      hash.modify(x, y+1, z[0]);
    } else {
      int a = IN1, b = IN1, c = IN1, d = IN1;
      b++; d++;
      int eq = 0, neq = min(b-a, d-c)+1;
      while (neq - eq > 1) {
        int m = (eq + neq) / 2;
        auto l = hash.fold(a, a+m);
        auto r = hash.fold(c, c+m);
        (l == r ? eq : neq) = m;
      }
      if (eq == b-a and eq == d-c) OUT("e");
      else if (eq == b-a) OUT("s");
      else if (eq == d-c) OUT("t");
      else {
        auto s = hash.fold(a+eq, a+eq+1).value;
        auto t = hash.fold(c+eq, c+eq+1).value;
        OUT(s < t ? "s" : "t");
      }
    }
  }
}