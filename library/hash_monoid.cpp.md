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
<script type="text/javascript" src="../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../assets/css/copy-button.css" />


# :warning: hash_monoid.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/hash_monoid.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 15:09:17+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "hash_monoid.cpp"

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

```
{% endraw %}

<a href="../index.html">Back to top page</a>

