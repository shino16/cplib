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


# :warning: data-structure/heap.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/heap.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 18:46:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename T, typename Compare = less<>>
class heap {
 private:
  Compare comp;

 public:
  vector<T> data;
  heap(Compare comp = Compare()) : data(), comp(comp) {}
  heap(const vector<T>& data, Compate comp = Compare())
      : data(data), comp(comp) {
    build();
  }
  heap(vector<T>&& data, Compare comp = Compare()) : data(data), comp(comp) {
    build();
  }
  void build() { make_heap(all(data), comp); }
  size_t size() { return data.size(); }
  void push(const T& value) {
    data.push_back(value);
    push_heap(all(data), comp);
  }
  void push(T&& value) {
    data.push_back(value);
    push_heap(all(data), comp);
  }
  template <typename... Args>
  void emplace(Args&&... args) {
    data.emplace_back(forward<Args>(args)...);
    push_heap(all(data), comp);
  }
  T top() { return data.front(); }
  T pop() {
    pop_heap(all(data), comp);
    T popped = move(data.back());
    data.pop_back();
    return popped;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/heap.cpp"
template <typename T, typename Compare = less<>>
class heap {
 private:
  Compare comp;

 public:
  vector<T> data;
  heap(Compare comp = Compare()) : data(), comp(comp) {}
  heap(const vector<T>& data, Compate comp = Compare())
      : data(data), comp(comp) {
    build();
  }
  heap(vector<T>&& data, Compare comp = Compare()) : data(data), comp(comp) {
    build();
  }
  void build() { make_heap(all(data), comp); }
  size_t size() { return data.size(); }
  void push(const T& value) {
    data.push_back(value);
    push_heap(all(data), comp);
  }
  void push(T&& value) {
    data.push_back(value);
    push_heap(all(data), comp);
  }
  template <typename... Args>
  void emplace(Args&&... args) {
    data.emplace_back(forward<Args>(args)...);
    push_heap(all(data), comp);
  }
  T top() { return data.front(); }
  T pop() {
    pop_heap(all(data), comp);
    T popped = move(data.back());
    data.pop_back();
    return popped;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

