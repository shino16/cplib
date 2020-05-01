#define PROBLEM "https://yukicoder.me/problems/no/1036"

#include "template.cpp"
#include "data-structure/disjoint-sparse-table.cpp"

int main() {
  int n = IN;
  auto a = IN.vll(n);
  DisjointSparseTable dst(all(a), __gcd<ll>);
  ll res = 0;
  int r = 0;
  rep(l, n) {
    while (r <= l) r++;
    while (r < n and dst.fold(l, r) != 1) r++;
    if (dst.fold(l, r) == 1) res += n + 1 - r;
  }
  OUT(res);
}