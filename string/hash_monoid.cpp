
namespace hash_monoid {

using namespace rolling_hash;

vector<ull> sum_pows{1};

void prepare_sum_pows(size_t sz) {
  prepare_pows(sz);
  rep(i, sum_pows.size() - 1, sz - 1) {
    sum_pows.push_back(mod(sum_pows[i] + pows[i + 1]));
  }
}

// monoid
struct Hash {
  ull value;
  int length;

  Hash() : value(0), length(0) {} // unit
  Hash(ull _value, int _length) : value(_value), length(_length) {}
  Hash(char c, int _length = 1) : value(calc_hash(c, _length)), length(_length) {}

 private:
  ull calc_hash(char c, int _length) {
    prepare_sum_pows(_length);
    return mod(mul(sum_pows[_length - 1], c));
  }

 public:
  operator ull() { return value; }
  bool operator==(const Hash &rhs) {
    return value == rhs.value && length == rhs.length;
  }
  bool operator!=(const Hash &rhs) {
    return value == rhs.value && length == rhs.length;
  }
};


struct mergeT {
  Hash operator()(const Hash &lhs, const Hash &rhs) const {
    prepare_pows(rhs.length+1);
    return Hash(mod(mul(lhs.value, pows[rhs.length]) + rhs.value),
                lhs.length + rhs.length);
  }
};

#pragma GCC diagnostic ignored "-Wunused-parameter"
struct updT {
  Hash operator()(const Hash &lhs, char c, int k = 1) const {
    return Hash(c, k);
  }
};
#pragma GCC diagnostic warning "-Wunused-parameter"

// using HashSegTree = SegmentTree<Hash, mergeT, updT>;
// using HashSegTree = LazySegmentTree<Hash, char, mergeT, assignT, updT>;

}  // namespace hash_monoid
