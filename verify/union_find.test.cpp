#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"
#include "template.cpp"
#include "union_find.cpp"


int main() {
  int n = IN, q = IN;
  union_find uf(n);
  rep(q) {
    int c = IN, x = IN, y = IN;
    if (c == 0) uf.merge(x, y);
    else OUT((int)uf.same(x, y));
  }
}
