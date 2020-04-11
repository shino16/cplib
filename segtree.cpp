
#pragma GCC diagnostic ignored "-Wshadow"
template <typename T, typename Merge, typename Upd>
class segtree {
private:
  const int n;
  const T unit;
  const Merge merge;
  const Upd upd;
  vector<T> data;

public:
  segtree(int n = 0, T unit = T(), Merge merge = Merge(), Upd upd = Upd())
      : n(n), unit(unit), merge(merge), upd(upd), data(n<<1, unit) {
    build();
  }

  template <typename Iter>
  segtree(Iter first, Iter last, int n,
          T unit = T(), Merge merge = Merge(), Upd upd = Upd())
      : n(n), unit(unit), merge(merge), upd(upd), data(n<<1) {
    copy(first, last, data.begin()+n);
    build();
  }

private:
  void build() {
    repr(i, n) data[i] = merge(data[i<<1], data[i<<1|1]);
  }

public:
  void modify(int l, T v) {
    l += n;
    data[l] = upd(data[l], v);
    for (; l > 1; l >>= 1) data[l>>1] = merge(data[l&(~1)], data[l|1]);
  }

  T query(int l, int r) const {
    if (l == r) return unit;
    if (l+1 == r) return data[l+n];
    T resl = data[l+=n], resr = data[(r+=n)-1];
    for (l++, r--; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = merge(resl, data[l++]);
      if (r&1) resr = merge(data[--r], resr);
    }
    return merge(resl, resr);
  }
};
#pragma GCC diagnostic warning "-Wshadow"

template <typename T>
struct minT {
  T operator()(T a, T b) const {
    return min(a, b);
  }
};

template <typename T>
struct maxT {
  T operator()(T a, T b) const {
    return max(a, b);
  }
};

template <typename T>
struct assign {
  T operator()(T a, T b) const {
    return b;
  }
};

template <typename T, typename Upd = assign<T>>
using RangeMin = segtree<T, minT<T>, Upd>;

template <typename T, typename Upd = assign<T>>
using RangeMax = segtree<T, maxT<T>, Upd>;

template <typename T, typename Upd = assign<T>>
using RangeSum = segtree<T, plus<T>, Upd>;
