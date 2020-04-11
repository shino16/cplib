
using ull = unsigned long long;
class rolling_hash {
private:
  static constexpr ull mask30 = (1ULL << 30) - 1;
  static constexpr ull mask31 = (1ULL << 31) - 1;
  static constexpr ull MOD = (1ULL << 61) - 1;
  const int base;
  vector<ull> hash, pows;

public:
  template <typename Iter>
  rolling_hash(Iter first, Iter last)
      : base(rand()), hash(last-first + 1), pows(last-first + 1) {
    pows[0] = 1;
    rep(i, last - first) {
      hash[i+1] = mod(mul(hash[i], base) + *(first + i));
      pows[i+1] = mod(mul(pows[i], base));
      // assert(hash[i+1] < (1ULL << 62));
    }
  }

private:
  ull mod(unsigned long long val) const {
    val = (val & MOD) + (val >> 61);
    return val >= MOD ? val - MOD : val;
  }

  ull mul(ull l, ull r) const {
    ull lu = l >> 31, ld = l & mask31;
    ull ru = r >> 31, rd = r & mask31;
    ull middle = ld * ru + lu * rd;
    return ((lu * ru) << 1) + ld * rd + ((middle & mask30) << 31) +
           (middle >> 30);
  }

  ull mul(ull l, int r) const {
    ull lu = l >> 31, ld = l & mask31;
    ull middle = lu * r;
    return ld * r + ((middle & mask30) << 31) + (middle >> 30);
  }

public:
  ull operator()(int l, int r) const {
    static constexpr ull large = MOD * ((1 << 2) - 1);
    return mod(hash[r] + large - mul(hash[l], pows[r-l]));
  }
};
