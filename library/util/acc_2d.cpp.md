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


# :warning: util/acc_2d.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05c7e24700502a079cdd88012b5a76d3">util</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/acc_2d.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 23:28:13+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

class Acc_2D {
private:
  VVLL data;

public:
  // arr must be non-empty
  template <typename Arr>
  Acc_2D(const Arr& arr, int h, int w): data(make_v(h+1, w+1, 0LL)) {
    rep(r, h) rep(c, w) data[r+1][c+1] += data[r+1][c] + arr[r][c];
    rep(r, h) rep(c, w) data[r+1][c+1] += data[r][c+1];
  }

  ll operator()(int r, int c) {
    return data[r][c];
  }

  ll operator()(int r1, int c1, int r2, int c2) {
    return data[r2][c2] - data[r1][c2] - data[r2][c1] + data[r1][c1];
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "util/acc_2d.cpp"

class Acc_2D {
private:
  VVLL data;

public:
  // arr must be non-empty
  template <typename Arr>
  Acc_2D(const Arr& arr, int h, int w): data(make_v(h+1, w+1, 0LL)) {
    rep(r, h) rep(c, w) data[r+1][c+1] += data[r+1][c] + arr[r][c];
    rep(r, h) rep(c, w) data[r+1][c+1] += data[r][c+1];
  }

  ll operator()(int r, int c) {
    return data[r][c];
  }

  ll operator()(int r1, int c1, int r2, int c2) {
    return data[r2][c2] - data[r1][c2] - data[r2][c1] + data[r1][c1];
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

