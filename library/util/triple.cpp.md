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


# :warning: util/triple.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05c7e24700502a079cdd88012b5a76d3">util</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/triple.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-28 15:58:32+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

template <typename T, typename U, typename V>
struct triple {
  T first;
  U second;
  V third;
  triple(T fs, U sn, V th): first(fs), second(sn), third(th) { }
  operator tuple<T, U, V>() const { return make_tuple(first, second, third); }
};

template <typename T, typename U, typename V>
triple<T, U, V> make_triple(T fs, U sn, V th) { return triple<T, U, V>(fs, sn, th); }

template <size_t I, typename T, typename U, typename V>
typename std::tuple_element_t<I, tuple<T, U, V>>& get(triple<T, U, V>& t) {
  return get<I>(tuple<T&, U&, V&>(t.first, t.second, t.third));
}

template <size_t I, typename T, typename U, typename V>
const typename std::tuple_element_t<I, tuple<T, U, V>>& get(const triple<T, U, V>& t) {
  return get<I>(tuple<T, U, V>(t));
}

template <size_t I, typename T, typename U, typename V>
typename std::tuple_element_t<I, tuple<T, U, V>>&& get(triple<T, U, V>&& t) {
  return get<I>(tuple<T, U, V>(move(t)));
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "util/triple.cpp"

template <typename T, typename U, typename V>
struct triple {
  T first;
  U second;
  V third;
  triple(T fs, U sn, V th): first(fs), second(sn), third(th) { }
  operator tuple<T, U, V>() const { return make_tuple(first, second, third); }
};

template <typename T, typename U, typename V>
triple<T, U, V> make_triple(T fs, U sn, V th) { return triple<T, U, V>(fs, sn, th); }

template <size_t I, typename T, typename U, typename V>
typename std::tuple_element_t<I, tuple<T, U, V>>& get(triple<T, U, V>& t) {
  return get<I>(tuple<T&, U&, V&>(t.first, t.second, t.third));
}

template <size_t I, typename T, typename U, typename V>
const typename std::tuple_element_t<I, tuple<T, U, V>>& get(const triple<T, U, V>& t) {
  return get<I>(tuple<T, U, V>(t));
}

template <size_t I, typename T, typename U, typename V>
typename std::tuple_element_t<I, tuple<T, U, V>>&& get(triple<T, U, V>&& t) {
  return get<I>(tuple<T, U, V>(move(t)));
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

