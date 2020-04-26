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


# :warning: swag.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/swag.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 15:09:17+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

template <typename F, typename T = ll>
class Swag {
 private:
  vector<T> L, R;
  vector<T> accL, accR;
  const T unit;
  const F f;

 public:
  Swag(T _unit = T(), F _f = F())
      : L(), R(), accL(), accR(), unit(_unit), f(_f) {}
  template <typename Iter>
  Swag(Iter first, Iter last, T _unit = T(), F _f = F())
      : L(make_reverse_iterator(last), make_reverse_iterator(first)),
        R(), accL(), accR(), unit(_unit), f(_f) {
    buildL();
  }

 public:
  void push(T x) {
    R.push_back(x);
    accR.push_back(accR.empty() ? x : f(accR.back(), x));
  }

  void pop() {
    prepareL();
    L.pop_back();
    accL.pop_back();
  }

  T fold() const {
    T res = L.empty() ? unit : accL[L.size()-1];
    if (not R.empty())
      res = res == unit ? accR[R.size()-1] : f(res, accR[R.size()-1]);
    return res;
  }

 private:
  void buildL() {
    accL.resize(L.size());
    if (not accL.empty()) {
      accL[0] = L[0];
      rep(i, 1, accL.size()) accL[i] = f(L[i], accL[i-1]);
    }
  }

  void prepareL() {
    if (L.empty()) {
      reverse(all(R));
      swap(L, R);
      buildL();
      accR.clear();
    }
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "swag.cpp"

template <typename F, typename T = ll>
class Swag {
 private:
  vector<T> L, R;
  vector<T> accL, accR;
  const T unit;
  const F f;

 public:
  Swag(T _unit = T(), F _f = F())
      : L(), R(), accL(), accR(), unit(_unit), f(_f) {}
  template <typename Iter>
  Swag(Iter first, Iter last, T _unit = T(), F _f = F())
      : L(make_reverse_iterator(last), make_reverse_iterator(first)),
        R(), accL(), accR(), unit(_unit), f(_f) {
    buildL();
  }

 public:
  void push(T x) {
    R.push_back(x);
    accR.push_back(accR.empty() ? x : f(accR.back(), x));
  }

  void pop() {
    prepareL();
    L.pop_back();
    accL.pop_back();
  }

  T fold() const {
    T res = L.empty() ? unit : accL[L.size()-1];
    if (not R.empty())
      res = res == unit ? accR[R.size()-1] : f(res, accR[R.size()-1]);
    return res;
  }

 private:
  void buildL() {
    accL.resize(L.size());
    if (not accL.empty()) {
      accL[0] = L[0];
      rep(i, 1, accL.size()) accL[i] = f(L[i], accL[i-1]);
    }
  }

  void prepareL() {
    if (L.empty()) {
      reverse(all(R));
      swap(L, R);
      buildL();
      accR.clear();
    }
  }
};

```
{% endraw %}

<a href="../index.html">Back to top page</a>

