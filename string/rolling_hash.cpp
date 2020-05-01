#pragma once

namespace rolling_hash {

constexpr ull mask30 = (1ULL << 30) - 1;
constexpr ull mask31 = (1ULL << 31) - 1;
constexpr ull MOD = (1ULL << 61) - 1;
int base = rand();
vector<ull> pows{1};
vector<ull> sum_pows{1};

ull mod(ull val) {
  val = (val & MOD) + (val >> 61);
  return val >= MOD ? val - MOD : val;
}

ull mul(ull l, ull r) {
  ull lu = l >> 31, ld = l & mask31;
  ull ru = r >> 31, rd = r & mask31;
  ull middle = ld * ru + lu * rd;
  return ((lu * ru) << 1) + ld * rd + ((middle & mask30) << 31) +
         (middle >> 30);
}

ull mul(ull l, int r) {
  ull lu = l >> 31, ld = l & mask31;
  ull middle = lu * r;
  return ld * r + ((middle & mask30) << 31) + (middle >> 30);
}

void prepare_pows(size_t sz) {
  rep(i, pows.size() - 1, sz - 1) pows.push_back(mod(mul(pows[i], base)));
}

void prepare_sum_pows(size_t sz) {
  prepare_pows(sz);
  rep(i, sum_pows.size() - 1, sz - 1) {
    sum_pows.push_back(mod(sum_pows[i] + pows[i + 1]));
  }
}

ull calc_hash(char c, int _length) {
  prepare_sum_pows(_length);
  return mod(mul(sum_pows[_length - 1], c));
}

template <typename Iter>
ull calc_hash(Iter first, Iter last) {
  ull res = 0;
  while (first != last) res = mod(mul(res, base) + *first++);
  return res;
}

// monoid
struct Hash {
  ull value;
  int length;

  Hash() : value(0), length(0) {}  // unit
  Hash(ull _value, int _length) : value(_value), length(_length) {}
  Hash(char c, int _length = 1)
      : value(calc_hash(c, _length)), length(_length) {}
  template <typename Iter>
  Hash(Iter first, Iter last): value(calc_hash(first, last)), length(distance(first, last)) {}

 public:
  operator ull() const { return value; }
  bool operator==(const Hash& rhs) const {
    return value == rhs.value && length == rhs.length;
  }
  bool operator!=(const Hash& rhs) const {
    return value != rhs.value && length != rhs.length;
  }
  bool operator<(const Hash& rhs) const {
    return make_pair(length, value) < make_pair(rhs.length, rhs.value);
  }
};

class Calculator {
 private:
  vector<ull> hash;

 public:
  template <typename Iter>
  Calculator(Iter first, Iter last) : hash(last - first + 1) {
    prepare_pows(last - first + 1);
    rep(i, last - first) hash[i + 1] = mod(mul(hash[i], base) + first[i]);
    // assert(hash[i+1] < (1ULL << 62));
  }

 public:
  ull operator()(int l, int r) const {
    static constexpr ull large = MOD * ((1 << 2) - 1);
    return mod(hash[r] + large - mul(hash[l], pows[r - l]));
  }
  Hash get_hash(int l, int r) const {
    return Hash(operator()(l, r), r - l);
  }
};

}  // namespace rolling_hash
