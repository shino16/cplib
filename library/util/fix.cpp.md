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


# :heavy_check_mark: util/fix.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05c7e24700502a079cdd88012b5a76d3">util</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/fix.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 10:43:15+09:00




## Required by

* :heavy_check_mark: <a href="../graph/strongly-connected-components.cpp.html">graph/strongly-connected-components.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/aoj/0366.test.cpp.html">verify/aoj/0366.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

template <typename F>
class FixPoint : private F {
 public:
  explicit constexpr FixPoint(F&& f) : F(forward<F>(f)) {}

  template <typename... Args>
  constexpr decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, forward<Args>(args)...);
  }
};

template <typename F> decltype(auto) fix(F&& f) noexcept {
  return FixPoint<F>{forward<F>(f)};
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "util/fix.cpp"

template <typename F>
class FixPoint : private F {
 public:
  explicit constexpr FixPoint(F&& f) : F(forward<F>(f)) {}

  template <typename... Args>
  constexpr decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, forward<Args>(args)...);
  }
};

template <typename F> decltype(auto) fix(F&& f) noexcept {
  return FixPoint<F>{forward<F>(f)};
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

