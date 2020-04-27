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


# :heavy_check_mark: util/compress.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05c7e24700502a079cdd88012b5a76d3">util</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/compress.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 18:46:30+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/verify/BIT_compress.test.cpp.html">verify/BIT_compress.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp

template <typename T = ll>
class Compress {
 private:
  vector<T> data;
  bool built;

 public:
  Compress() { build(); }
  template <typename Iter>
  Compress(Iter first, Iter last) : data(first, last) {
    build();
  }

 private:
  void build() {
    if (not built) {
      sort(all(data));
      data.erase(unique(all(data)), data.end());
      built = true;
    }
  }

 public:
  void insert(T v) {
    built = false;
    data.push_back(v);
  }
  template <typename... Args>
  void emplace(Args&&... args) {
    built = false;
    data.emplace_back(forward<Args>(args)...);
  }
  int size() {
    build();
    return data.size();
  }
  int operator[](T v) {
    build();
    assert(binary_search(all(data), v));
    return std::lower_bound(all(data), v) - data.begin();
  }
  T rev(int i) {
    build();
    return data[i];
  }
  int lower_bound(T v) {
    build();
    return std::lower_bound(all(data), v) - data.begin();
  }
  int upper_bound(T v) {
    build();
    return std::upper_bound(all(data), v) - data.begin();
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "util/compress.cpp"

template <typename T = ll>
class Compress {
 private:
  vector<T> data;
  bool built;

 public:
  Compress() { build(); }
  template <typename Iter>
  Compress(Iter first, Iter last) : data(first, last) {
    build();
  }

 private:
  void build() {
    if (not built) {
      sort(all(data));
      data.erase(unique(all(data)), data.end());
      built = true;
    }
  }

 public:
  void insert(T v) {
    built = false;
    data.push_back(v);
  }
  template <typename... Args>
  void emplace(Args&&... args) {
    built = false;
    data.emplace_back(forward<Args>(args)...);
  }
  int size() {
    build();
    return data.size();
  }
  int operator[](T v) {
    build();
    assert(binary_search(all(data), v));
    return std::lower_bound(all(data), v) - data.begin();
  }
  T rev(int i) {
    build();
    return data[i];
  }
  int lower_bound(T v) {
    build();
    return std::lower_bound(all(data), v) - data.begin();
  }
  int upper_bound(T v) {
    build();
    return std::upper_bound(all(data), v) - data.begin();
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

