
class modint;
constexpr modint pow(modint, size_t);

class modint {
public:
  ll value;

  constexpr modint(const ll x = 0) noexcept : value(x) {
    value %= MOD;
    if (value < 0) value += MOD;
  }
  constexpr modint operator+(const modint rhs) const {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) {
    value += rhs.value;
    if (value >= MOD) value -= MOD;
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) {
    if (value < rhs.value) value += MOD;
    value -= rhs.value;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) {
    value = value * rhs.value % MOD;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) {
    return *this *= pow(rhs, MOD - 2);
  }
  constexpr modint &operator++() {
    return *this += 1;
  }
  constexpr modint operator++(int) {
    modint tmp(*this);
    ++(*this);
    return tmp;
  }
  constexpr modint &operator--() {
    return *this -= 1;
  }
  constexpr modint operator--(int) {
    modint tmp(*this);
    --(*this);
    return tmp;
  }
  constexpr operator int() const {
    return (int)value;
  }
  constexpr operator ll() const {
    return value;
  }
};


MyPrinter& operator<<(MyPrinter& out, modint n) {
  out << n.value;
  return out;
}

constexpr modint pow(modint base, size_t exp) {
  modint res = 1;
  while (exp) {
    if (exp % 2) res *= base;
    base *= base;
    exp /= 2;
  }
  return res;
}

modint choose(int n, int r) {
  chmin(r, n-r);
  if (r < 0) return modint(0);
  modint nu = 1, de = 1;
  rep(i, r) nu *= n-i, de *= i+1;
  return nu / de;
}
