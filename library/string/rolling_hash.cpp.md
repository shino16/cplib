---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: string/rolling_hash.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/rolling_hash.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 18:46:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

namespace rolling_hash {

constexpr ull mask30 = (1ULL << 30) - 1;
constexpr ull mask31 = (1ULL << 31) - 1;
constexpr ull MOD = (1ULL << 61) - 1;
int base = rand();
vector<ull> pows{1};

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
};

}  // namespace rolling_hash

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/rolling_hash.cpp"

namespace rolling_hash {

constexpr ull mask30 = (1ULL << 30) - 1;
constexpr ull mask31 = (1ULL << 31) - 1;
constexpr ull MOD = (1ULL << 61) - 1;
int base = rand();
vector<ull> pows{1};

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
};

}  // namespace rolling_hash

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

