template <typename T, typename Cmb, typename Upd>
struct segtree {
  const int n;
  const T unit;
  const Cmb cmb;
  const Upd upd;
  vector<T> data;
  segtree(int n, T unit = T(), Cmb cmb = Cmb(), Upd upd = Upd())
      : n(n), unit(unit), cmb(cmb), upd(upd), data(n<<1, unit) {
    build();
  }
  template <typename Iter>
  segtree(Iter first, Iter last, int n,
          T unit = T(), Cmb cmb = Cmb(), Upd upd = Upd())
      : n(n), unit(unit), cmb(cmb), upd(upd), data(n<<1) {
    assign(first, last);
  }
  void build() {
    repr(i, n) data[i] = cmb(data[i<<1], data[i<<1|1]);
  }
  template <typename Iter>
  void assign(Iter first, Iter last) {
    copy(first, last, data.begin()+n);
    build();
  }
  void modify(int l, T v) {
    l += n;
    data[l] = upd(data[l], v);
    for (; l > 1; l >>= 1) data[l>>1] = cmb(data[l&(~1)], data[l|1]);
  }
  T query(int l, int r) {
    T resl = unit, resr = unit;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = cmb(resl, data[l++]);
      if (r&1) resr = cmb(data[--r], resr);
    }
    return cmb(resl, resr);
  }
};