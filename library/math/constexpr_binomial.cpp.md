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


# :warning: math/constexpr_binomial.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/constexpr_binomial.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 23:28:13+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

template <size_t N>
class binomial {
public:
  array<modint, N+1> fact, invfact;
  constexpr binomial() {
    fact[0] = 1;
    rep(i, N) fact[i+1] = fact[i] * modint(i+1);
    invfact[N] = modint(1) / fact[N];
    repr(i, N) invfact[i] = invfact[i+1] * modint(i+1);
  }
  modint operator()(int n, int r) const {
    chmin(r, n-r);
    if (r < 0) return modint(0);
    return fact[n] * invfact[r] * invfact[n-r];
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/constexpr_binomial.cpp"

template <size_t N>
class binomial {
public:
  array<modint, N+1> fact, invfact;
  constexpr binomial() {
    fact[0] = 1;
    rep(i, N) fact[i+1] = fact[i] * modint(i+1);
    invfact[N] = modint(1) / fact[N];
    repr(i, N) invfact[i] = invfact[i+1] * modint(i+1);
  }
  modint operator()(int n, int r) const {
    chmin(r, n-r);
    if (r < 0) return modint(0);
    return fact[n] * invfact[r] * invfact[n-r];
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

