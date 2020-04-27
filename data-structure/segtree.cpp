
#pragma GCC diagnostic ignored "-Wshadow"
template <typename T, typename Merge, typename Upd>
class SegmentTree {
 private:
  const size_t n;
  const T unit;
  const Merge merge;
  const Upd upd;
  vector<T> data;

 public:
  SegmentTree(size_t n = 0, T unit = T(), Merge merge = Merge(),
              Upd upd = Upd())
      : n(n), unit(unit), merge(merge), upd(upd), data(n << 1, unit) {
    build();
  }

  template <typename Iter,
            enable_if_t<is_same_v<typename Iter::value_type, T>>* = nullptr>
  SegmentTree(Iter first, Iter last, size_t n, T unit = T(),
              Merge merge = Merge(), Upd upd = Upd())
      : n(n), unit(unit), merge(merge), upd(upd), data(n << 1) {
    copy(first, last, data.begin() + n);
    build();
  }

  template <typename Iter,
            enable_if_t<!is_same_v<typename Iter::value_type, T>>* = nullptr>
  [[deprecated]] SegmentTree(Iter first, Iter last, size_t n, T unit = T(),
                             Merge merge = Merge(), Upd upd = Upd())
      : n(n), unit(unit), merge(merge), upd(upd), data(n << 1) {
    copy(first, last, data.begin() + n);
    build();
  }

  template <typename Iter>
  SegmentTree(Iter first, Iter last, T unit = T(), Merge merge = Merge(),
              Upd upd = Upd())
      : SegmentTree(first, last, distance(first, last), unit, merge, upd) {}

 private:
  void build() { repr(i, n) data[i] = merge(data[i << 1], data[i << 1 | 1]); }

 public:
  void modify(int l, T v) {
    l += n;
    data[l] = upd(data[l], v);
    for (; l > 1; l >>= 1) data[l >> 1] = merge(data[l & (~1)], data[l | 1]);
  }

  T fold(int l, int r) const {
    if (l == r) return unit;
    if (l + 1 == r) return data[l + n];
    T resl = data[l += n], resr = data[(r += n) - 1];
    for (l++, r--; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = merge(resl, data[l++]);
      if (r & 1) resr = merge(data[--r], resr);
    }
    return merge(resl, resr);
  }
};
#pragma GCC diagnostic warning "-Wshadow"

struct minT {
  template <typename T>
  T operator()(T a, T b) const {
    return min(a, b);
  }
};

struct maxT {
  template <typename T>
  T operator()(T a, T b) const {
    return max(a, b);
  }
};

#pragma GCC diagnostic ignored "-Wunused-parameter"
struct assign {
  template <typename T>
  T operator()(T a, T b) const {
    return b;
  }
};
#pragma GCC diagnostic warning "-Wunused-parameter"
