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


# :warning: BIT.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/BIT.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 15:09:17+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
class BIT {
public:
  const int n;
private:
  vector<ll> data;
public:
  BIT(int _n = 0): n(_n), data(_n+1) { }
  void add(int p, ll v = 1) {
    p++;
    while (p <= n) {
      data[p] += v;
      p += p & -p;
    }
  }
  // sum over [0, p)
  ll sum(int p) {
    ll res = 0;
    while (p) {
      res += data[p];
      p -= p & -p;
    }
    return res;
  }
  // sum over [l, r)
  ll sum(int l, int r) {
    return sum(r) - sum(l);
  }
  void assign(int p, ll v) {
    add(p, v - sum(p, p+1));
  }
  bool chmax(int p, ll v) {
    if (sum(p, p+1) < v) {
      assign(p, v);
      return true;
    } else return false;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "BIT.cpp"
class BIT {
public:
  const int n;
private:
  vector<ll> data;
public:
  BIT(int _n = 0): n(_n), data(_n+1) { }
  void add(int p, ll v = 1) {
    p++;
    while (p <= n) {
      data[p] += v;
      p += p & -p;
    }
  }
  // sum over [0, p)
  ll sum(int p) {
    ll res = 0;
    while (p) {
      res += data[p];
      p -= p & -p;
    }
    return res;
  }
  // sum over [l, r)
  ll sum(int l, int r) {
    return sum(r) - sum(l);
  }
  void assign(int p, ll v) {
    add(p, v - sum(p, p+1));
  }
  bool chmax(int p, ll v) {
    if (sum(p, p+1) < v) {
      assign(p, v);
      return true;
    } else return false;
  }
};

```
{% endraw %}

<a href="../index.html">Back to top page</a>

