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


# :warning: util/hack_pque.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05c7e24700502a079cdd88012b5a76d3">util</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/hack_pque.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 18:46:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

template <class T, class S, class C>
S& hack(priority_queue<T, S, C>& q) {
  struct HackedQueue : private priority_queue<T, S, C> {
    static S& hack(priority_queue<T, S, C>& q) {
      return q.*&HackedQueue::c;
    }
  };
  return HackedQueue::hack(q);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "util/hack_pque.cpp"

template <class T, class S, class C>
S& hack(priority_queue<T, S, C>& q) {
  struct HackedQueue : private priority_queue<T, S, C> {
    static S& hack(priority_queue<T, S, C>& q) {
      return q.*&HackedQueue::c;
    }
  };
  return HackedQueue::hack(q);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

