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


# :heavy_check_mark: data-structure/bit_2d.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/bit_2d.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-28 16:11:36+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/verify/BIT_2D.test.cpp.html">verify/BIT_2D.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp

class BIT_2D {
private:
  const int h, w;
  vector<vector<ll>> data;
public:
  BIT_2D(int h, int w): h(h), w(w), data(h+1, vector<ll>(w+1)) { }
  void add(int r, int c, ll v) {
    r++; c++;
    int c0 = c;
    for (; r <= h; r += r & -r)
      for (c = c0; c <= w; c += c & -c)
        data[r][c] += v;
  }
  // sum over [(0, 0), (r, c))
  ll sum(int r, int c) {
    ll res = 0;
    int c0 = c;
    for (; r > 0; r -= r & -r)
      for (c = c0; c > 0; c -= c & -c)
        res += data[r][c];
    return res;
  }
  // sum over [(r1, c1), (r2, c2))
  ll sum(int r1, int c1, int r2, int c2) {
    return sum(r1, c1) + sum(r2, c2) - sum(r1, c2) - sum(r2, c1);
  }
  void assign(int r, int c, ll v) {
    add(r, c, v - sum(r, c, r+1, c+1));
  }
  bool chmax(int r, int c, ll v) {
    if (sum(r, c, r+1, c+1) < v) {
      assign(r, c, v);
      return true;
    } else return false;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/bit_2d.cpp"

class BIT_2D {
private:
  const int h, w;
  vector<vector<ll>> data;
public:
  BIT_2D(int h, int w): h(h), w(w), data(h+1, vector<ll>(w+1)) { }
  void add(int r, int c, ll v) {
    r++; c++;
    int c0 = c;
    for (; r <= h; r += r & -r)
      for (c = c0; c <= w; c += c & -c)
        data[r][c] += v;
  }
  // sum over [(0, 0), (r, c))
  ll sum(int r, int c) {
    ll res = 0;
    int c0 = c;
    for (; r > 0; r -= r & -r)
      for (c = c0; c > 0; c -= c & -c)
        res += data[r][c];
    return res;
  }
  // sum over [(r1, c1), (r2, c2))
  ll sum(int r1, int c1, int r2, int c2) {
    return sum(r1, c1) + sum(r2, c2) - sum(r1, c2) - sum(r2, c1);
  }
  void assign(int r, int c, ll v) {
    add(r, c, v - sum(r, c, r+1, c+1));
  }
  bool chmax(int r, int c, ll v) {
    if (sum(r, c, r+1, c+1) < v) {
      assign(r, c, v);
      return true;
    } else return false;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

