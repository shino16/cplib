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


# :warning: math/factorize.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/factorize.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 23:28:13+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

map<ll, int> factorize(ll n) {
  map<ll, int> m;
  if (n == 1) return m;
  if (n < 4) { m[n]++; return m; }
  while ((n & 1) == 0) m[2]++, n >>= 1;
  ll d = 3;
  do {
    while (n % d == 0) m[d]++, n /= d;
    d += 2;
  } while (n >= d * d);
  if (n > 1) m[n]++;
  return m;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/factorize.cpp"

map<ll, int> factorize(ll n) {
  map<ll, int> m;
  if (n == 1) return m;
  if (n < 4) { m[n]++; return m; }
  while ((n & 1) == 0) m[2]++, n >>= 1;
  ll d = 3;
  do {
    while (n % d == 0) m[d]++, n /= d;
    d += 2;
  } while (n >= d * d);
  if (n > 1) m[n]++;
  return m;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

