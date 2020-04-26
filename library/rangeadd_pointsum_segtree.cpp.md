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


# :warning: rangeadd_pointsum_segtree.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/rangeadd_pointsum_segtree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-18 19:31:16+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma GCC diagnostic ignored "-Wshadow"
struct segtree {
  const int n;
  vector<ll> data;
  segtree(int n = 0) : n(n) { }
  template <typename Iter>
  segtree(Iter first, Iter last, int n) : n(n), data(n<<1) {
    copy(first, last, data.begin()+n);
  }
  ll query(int l) {
    ll res = 0;
    for (l += n; l > 1; l >>= 1) res += data[l];
    return res;
  }
  void modify(int l, int r, ll v) {
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) data[l++] += v;
      if (r&1) data[--r] += v;
    }
  }
};
#pragma GCC diagnostic warning "-Wshadow"

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "rangeadd_pointsum_segtree.cpp"
#pragma GCC diagnostic ignored "-Wshadow"
struct segtree {
  const int n;
  vector<ll> data;
  segtree(int n = 0) : n(n) { }
  template <typename Iter>
  segtree(Iter first, Iter last, int n) : n(n), data(n<<1) {
    copy(first, last, data.begin()+n);
  }
  ll query(int l) {
    ll res = 0;
    for (l += n; l > 1; l >>= 1) res += data[l];
    return res;
  }
  void modify(int l, int r, ll v) {
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) data[l++] += v;
      if (r&1) data[--r] += v;
    }
  }
};
#pragma GCC diagnostic warning "-Wshadow"

```
{% endraw %}

<a href="../index.html">Back to top page</a>

