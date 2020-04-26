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


# :warning: approximate.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/approximate.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-11 15:35:53+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

template <typename F>
class
#if defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
[[nodiscard]]
#elif defined(__GNUC__) && (__GNUC__ > 3 || __GNUC__ == 3 && __GNUC_MINOR__ >= 4)
__attribute__((warn_unused_result))
#endif
FixPoint : private F
{
public:
explicit constexpr FixPoint(F&& f) noexcept
: F(std::forward<F>(f))
{}

template<typename... Args>
constexpr decltype(auto)
operator()(Args&&... args) const
#if !defined(__GNUC__) || defined(__clang__) || __GNUC__ >= 9
noexcept(noexcept(F::operator()(std::declval<FixPoint>(), std::declval<Args>()...)))
#endif
{
return F::operator()(*this, std::forward<Args>(args)...);
}
};


template<typename F>
static inline constexpr decltype(auto)
fix(F&& f) noexcept
{
return FixPoint<F>{std::forward<F>(f)};
}

bool operator <(PLL x, PLL y) {
  return x.first * y.second < x.second * y.first;
}

PLL operator +(PLL x, PLL y) {
  return {x.first + y.first, x.second + y.second};
}

// http://www.kurims.kyoto-u.ac.jp/~kyodo/kokyuroku/contents/pdf/1199-22.pdf
// returns the best rational approximation of x
PLL approximate(double x, ll max_denom = 1000000) {
  int sign = 1;
  if (x < 0) x = -x, sign = -1;
  ll a = x, p0 = 1, q0 = 0, p1 = a, q1 = 1, p2, q2;
  while (x != a) {
    x = 1 / (x - a);
    a = x;
    p2 = a * p1 + p0;
    q2 = a * q1 + q0;
    if (q2 > max_denom or q2 < 0) break;
    p0 = p1; p1 = p2;
    q0 = q1; q1 = q2;
  }
  return {p1 * sign, q1};
}

// return the fraction in (L, R) with minimal numerator/denominator
PLL stern_brocot(PLL L, PLL R) {
  PLL res = fix([&](auto f, auto l, auto r)->PLL{
    PLL mid = l + r;
    if (not (L < mid)) {
      PLL add = r;
      while (not (L < l + add)) l = l + add, add = add + add;
      return f(l, r);
    } else if (not (mid < R)) {
      PLL add = l;
      while (not (add + r < R)) r = r + add, add = add + add;
      return f(l, r);
    } else return mid;
  })(PLL{0, 1}, PLL{1, 0});
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "approximate.cpp"

template <typename F>
class
#if defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
[[nodiscard]]
#elif defined(__GNUC__) && (__GNUC__ > 3 || __GNUC__ == 3 && __GNUC_MINOR__ >= 4)
__attribute__((warn_unused_result))
#endif
FixPoint : private F
{
public:
explicit constexpr FixPoint(F&& f) noexcept
: F(std::forward<F>(f))
{}

template<typename... Args>
constexpr decltype(auto)
operator()(Args&&... args) const
#if !defined(__GNUC__) || defined(__clang__) || __GNUC__ >= 9
noexcept(noexcept(F::operator()(std::declval<FixPoint>(), std::declval<Args>()...)))
#endif
{
return F::operator()(*this, std::forward<Args>(args)...);
}
};


template<typename F>
static inline constexpr decltype(auto)
fix(F&& f) noexcept
{
return FixPoint<F>{std::forward<F>(f)};
}

bool operator <(PLL x, PLL y) {
  return x.first * y.second < x.second * y.first;
}

PLL operator +(PLL x, PLL y) {
  return {x.first + y.first, x.second + y.second};
}

// http://www.kurims.kyoto-u.ac.jp/~kyodo/kokyuroku/contents/pdf/1199-22.pdf
// returns the best rational approximation of x
PLL approximate(double x, ll max_denom = 1000000) {
  int sign = 1;
  if (x < 0) x = -x, sign = -1;
  ll a = x, p0 = 1, q0 = 0, p1 = a, q1 = 1, p2, q2;
  while (x != a) {
    x = 1 / (x - a);
    a = x;
    p2 = a * p1 + p0;
    q2 = a * q1 + q0;
    if (q2 > max_denom or q2 < 0) break;
    p0 = p1; p1 = p2;
    q0 = q1; q1 = q2;
  }
  return {p1 * sign, q1};
}

// return the fraction in (L, R) with minimal numerator/denominator
PLL stern_brocot(PLL L, PLL R) {
  PLL res = fix([&](auto f, auto l, auto r)->PLL{
    PLL mid = l + r;
    if (not (L < mid)) {
      PLL add = r;
      while (not (L < l + add)) l = l + add, add = add + add;
      return f(l, r);
    } else if (not (mid < R)) {
      PLL add = l;
      while (not (add + r < R)) r = r + add, add = add + add;
      return f(l, r);
    } else return mid;
  })(PLL{0, 1}, PLL{1, 0});
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

