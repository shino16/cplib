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


# :heavy_check_mark: data-structure/fibonacci_heap.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/fibonacci_heap.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 00:04:22+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/verify/aoj/GRL_1_A_fh.test.cpp.html">verify/aoj/GRL_1_A_fh.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp

// credit to: rsk0315 (https://atcoder.jp/users/rsk0315)
// this implementation is from https://atcoder.jp/contests/arc064/submissions/8197391

#include <list>
#include <memory>

constexpr intmax_t  operator ""_jd(unsigned long long n) { return n; }
constexpr uintmax_t operator ""_ju(unsigned long long n) { return n; }
constexpr size_t    operator ""_zu(unsigned long long n) { return n; }
// constexpr ptrdiff_t operator ""_td(unsigned long long n) { return n; }

namespace bit {
template <typename Tp>
int log2p1(Tp n) {
  if (n == 0) return 0;
  return (8 * sizeof(long long)) - __builtin_clzll(n);
}
}  // bit::

template <typename Key, typename Tp, typename Compare = std::less<>>
class fibonacci_heap {
public:
  using size_type = size_t;
  using key_type = Key;
  using mapped_type = Tp;
  using value_type = std::pair<key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = value_type const&;
  using key_compare = Compare;
  class node_handle;

private:
  class node;
  using pointer = std::shared_ptr<node>;

  class node {
    friend fibonacci_heap;

  public:
    using size_type = size_t;
    using key_type = Key;
    using mapped_type = Tp;
    using value_type = std::pair<key_type, mapped_type>;
    using reference = value_type&;
    using const_reference = value_type const&;
    using key_compare = Compare;

  private:
    pointer M_parent{nullptr};
    pointer M_child{nullptr};
    pointer M_left{nullptr};
    pointer M_right{nullptr};
    bool M_damaged = false;
    size_type M_order = 0;
    value_type M_value;  // {priority, element}

  public:
    node() = default;
    node(node const&) = default;
    node(node&&) = default;
    node& operator =(node const&) = default;
    node& operator =(node&&) = default;

    node(key_type const& key, mapped_type const& mapped):
      M_value(key, mapped) {}
  };

  static void S_add_child(pointer parent, pointer child) {
    ++parent->M_order;
    child->M_parent = parent;
    if (!parent->M_child) {
      parent->M_child = child;
      child->M_left = child->M_right = nullptr;
    } else if (!parent->M_child->M_left) {
      parent->M_child->M_left = parent->M_child->M_right = child;
      child->M_left = child->M_right = parent->M_child;
    } else {
      child->M_left = parent->M_child->M_left;
      child->M_right = parent->M_child;
      parent->M_child->M_left->M_right = child;
      parent->M_child->M_left = child;
    }
  }

  static bool S_detach_child(pointer parent, pointer child) {
    // returns true if the resulting heap is valid, false otherwise
    bool res = !parent->M_damaged;
    if (parent->M_parent) parent->M_damaged = true;
    --parent->M_order;

    if (parent->M_child == child) parent->M_child = child->M_right;
    child->M_parent = nullptr;
    child->M_damaged = false;

    if (child->M_left) {
      if (child->M_left == child->M_right) {
        child->M_left->M_right = child->M_right->M_left = nullptr;
      } else {
        child->M_left->M_right = child->M_right;
        child->M_right->M_left = child->M_left;
      }
      child->M_left = child->M_right = nullptr;
    }
    return res;
  }

public:
  class node_handle {
    friend fibonacci_heap;

  public:
    using size_type = size_t;
    using key_type = Key;
    using mapped_type = Tp;
    using value_type = std::pair<key_type, mapped_type>;
    using reference = value_type&;
    using const_reference = value_type const&;
    using key_compare = Compare;
    using pointer = std::weak_ptr<node>;

  private:
    pointer M_node;

  public:
    node_handle() = default;
    node_handle(pointer node): M_node(node) {}
    const_reference operator *() const { return (*M_node)->M_value; }
    bool expired() const { return M_node.expired(); }
  };

private:
  size_type M_size = 0;
  std::list<pointer> M_roots;  // list for pop()
  pointer M_top;  // pointer (not iterator) for prioritize()
  key_compare M_comp = key_compare();

  static size_type S_num_nodes(pointer cur) {
    pointer child = cur->M_child;
    if (!child) return 1;
    size_type res = 1;
    do {
      res += S_num_nodes(child);
      child = child->M_right;
    } while (child && child != cur->M_child);
    return res;
  }

  void M_coleasce() {
    if (M_size == 0) {
      M_roots.clear();
      M_top = nullptr;
      return;
    }

    size_type size = 0;
    for (auto r: M_roots) size += 1_zu << r->M_order;
    std::vector<pointer> roots(bit::log2p1(size));

    for (auto r: M_roots) {
      size_type i = r->M_order;
      while (roots[i]) {
        if (M_comp(r->M_value.first, roots[i]->M_value.first))
          std::swap(r, roots[i]);

        S_add_child(r, roots[i]);
        roots[i] = nullptr;
        ++i;
      }
      roots[i] = r;
    }
    M_roots.clear();

    for (auto r: roots) if (r) M_roots.push_back(r);
    M_top = *M_roots.begin();
    for (auto p: M_roots)
      if (M_comp(M_top->M_value.first, p->M_value.first)) M_top = p;
  }

public:
  fibonacci_heap() = default;
  fibonacci_heap(fibonacci_heap const&) = delete;
  fibonacci_heap(fibonacci_heap&&) = default;
  fibonacci_heap& operator =(fibonacci_heap const&) = delete;
  fibonacci_heap& operator =(fibonacci_heap&&) = default;

  template <typename InputIt>
  fibonacci_heap(InputIt first, InputIt last) { assign(first, last); }
  fibonacci_heap(std::initializer_list<value_type> il) { assign(il); }

  size_type size() const noexcept { return M_size; }
  bool empty() const noexcept { return M_size == 0; }

  const_reference const& top() const { return M_top->M_value; }
  void pop() {
    pointer root = M_top;
    for (auto it = M_roots.begin(); it != M_roots.end(); ++it) {
      if (*it == M_top) {
        M_roots.erase(it);
        break;
      }
    }
    if (root->M_child) {
      pointer cur = root->M_child;
      do {
        pointer tmp = cur->M_right;
        cur->M_left = cur->M_right = cur->M_parent = nullptr;
        cur->M_damaged = false;
        M_roots.push_back(cur);
        cur = tmp;
      } while (cur && cur != root->M_child);
      root->M_child = nullptr;
    }
    --M_size;
    M_coleasce();
  }

  node_handle push(key_type const& key, mapped_type const& mapped) {
    pointer newnode = std::make_shared<node>(key, mapped);
    newnode->M_left = newnode->M_right = nullptr;
    M_roots.push_back(newnode);
    if (M_size == 0 || M_comp(M_top->M_value.first, key)) M_top = newnode;
    ++M_size;
    return node_handle(newnode);
  }

  void meld(fibonacci_heap& other) {
    M_size += other.M_size;
    other.M_size = 0;

    M_roots.splice(M_roots.end(), other.M_roots);
    if (M_comp(M_top->M_value.first, other.M_top->M_value.first))
      M_top = other.M_top;
  }

  void prioritize(node_handle& nh, key_type const& key) {
    pointer cur(nh.M_node);
    // assert(M_comp(cur->M_value.first, key));
    cur->M_value.first = key;
    if (M_comp(M_top->M_value.first, key)) M_top = cur;
    if (!cur->M_parent || !M_comp(cur->M_parent->M_value.first, key)) return;

    bool more_cut = true;
    while (more_cut) {
      pointer parent = cur->M_parent;
      more_cut = !S_detach_child(parent, cur);
      M_roots.push_back(cur);
      cur = parent;
    }
  }
};


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/fibonacci_heap.cpp"

// credit to: rsk0315 (https://atcoder.jp/users/rsk0315)
// this implementation is from https://atcoder.jp/contests/arc064/submissions/8197391

#include <list>
#include <memory>

constexpr intmax_t  operator ""_jd(unsigned long long n) { return n; }
constexpr uintmax_t operator ""_ju(unsigned long long n) { return n; }
constexpr size_t    operator ""_zu(unsigned long long n) { return n; }
// constexpr ptrdiff_t operator ""_td(unsigned long long n) { return n; }

namespace bit {
template <typename Tp>
int log2p1(Tp n) {
  if (n == 0) return 0;
  return (8 * sizeof(long long)) - __builtin_clzll(n);
}
}  // bit::

template <typename Key, typename Tp, typename Compare = std::less<>>
class fibonacci_heap {
public:
  using size_type = size_t;
  using key_type = Key;
  using mapped_type = Tp;
  using value_type = std::pair<key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = value_type const&;
  using key_compare = Compare;
  class node_handle;

private:
  class node;
  using pointer = std::shared_ptr<node>;

  class node {
    friend fibonacci_heap;

  public:
    using size_type = size_t;
    using key_type = Key;
    using mapped_type = Tp;
    using value_type = std::pair<key_type, mapped_type>;
    using reference = value_type&;
    using const_reference = value_type const&;
    using key_compare = Compare;

  private:
    pointer M_parent{nullptr};
    pointer M_child{nullptr};
    pointer M_left{nullptr};
    pointer M_right{nullptr};
    bool M_damaged = false;
    size_type M_order = 0;
    value_type M_value;  // {priority, element}

  public:
    node() = default;
    node(node const&) = default;
    node(node&&) = default;
    node& operator =(node const&) = default;
    node& operator =(node&&) = default;

    node(key_type const& key, mapped_type const& mapped):
      M_value(key, mapped) {}
  };

  static void S_add_child(pointer parent, pointer child) {
    ++parent->M_order;
    child->M_parent = parent;
    if (!parent->M_child) {
      parent->M_child = child;
      child->M_left = child->M_right = nullptr;
    } else if (!parent->M_child->M_left) {
      parent->M_child->M_left = parent->M_child->M_right = child;
      child->M_left = child->M_right = parent->M_child;
    } else {
      child->M_left = parent->M_child->M_left;
      child->M_right = parent->M_child;
      parent->M_child->M_left->M_right = child;
      parent->M_child->M_left = child;
    }
  }

  static bool S_detach_child(pointer parent, pointer child) {
    // returns true if the resulting heap is valid, false otherwise
    bool res = !parent->M_damaged;
    if (parent->M_parent) parent->M_damaged = true;
    --parent->M_order;

    if (parent->M_child == child) parent->M_child = child->M_right;
    child->M_parent = nullptr;
    child->M_damaged = false;

    if (child->M_left) {
      if (child->M_left == child->M_right) {
        child->M_left->M_right = child->M_right->M_left = nullptr;
      } else {
        child->M_left->M_right = child->M_right;
        child->M_right->M_left = child->M_left;
      }
      child->M_left = child->M_right = nullptr;
    }
    return res;
  }

public:
  class node_handle {
    friend fibonacci_heap;

  public:
    using size_type = size_t;
    using key_type = Key;
    using mapped_type = Tp;
    using value_type = std::pair<key_type, mapped_type>;
    using reference = value_type&;
    using const_reference = value_type const&;
    using key_compare = Compare;
    using pointer = std::weak_ptr<node>;

  private:
    pointer M_node;

  public:
    node_handle() = default;
    node_handle(pointer node): M_node(node) {}
    const_reference operator *() const { return (*M_node)->M_value; }
    bool expired() const { return M_node.expired(); }
  };

private:
  size_type M_size = 0;
  std::list<pointer> M_roots;  // list for pop()
  pointer M_top;  // pointer (not iterator) for prioritize()
  key_compare M_comp = key_compare();

  static size_type S_num_nodes(pointer cur) {
    pointer child = cur->M_child;
    if (!child) return 1;
    size_type res = 1;
    do {
      res += S_num_nodes(child);
      child = child->M_right;
    } while (child && child != cur->M_child);
    return res;
  }

  void M_coleasce() {
    if (M_size == 0) {
      M_roots.clear();
      M_top = nullptr;
      return;
    }

    size_type size = 0;
    for (auto r: M_roots) size += 1_zu << r->M_order;
    std::vector<pointer> roots(bit::log2p1(size));

    for (auto r: M_roots) {
      size_type i = r->M_order;
      while (roots[i]) {
        if (M_comp(r->M_value.first, roots[i]->M_value.first))
          std::swap(r, roots[i]);

        S_add_child(r, roots[i]);
        roots[i] = nullptr;
        ++i;
      }
      roots[i] = r;
    }
    M_roots.clear();

    for (auto r: roots) if (r) M_roots.push_back(r);
    M_top = *M_roots.begin();
    for (auto p: M_roots)
      if (M_comp(M_top->M_value.first, p->M_value.first)) M_top = p;
  }

public:
  fibonacci_heap() = default;
  fibonacci_heap(fibonacci_heap const&) = delete;
  fibonacci_heap(fibonacci_heap&&) = default;
  fibonacci_heap& operator =(fibonacci_heap const&) = delete;
  fibonacci_heap& operator =(fibonacci_heap&&) = default;

  template <typename InputIt>
  fibonacci_heap(InputIt first, InputIt last) { assign(first, last); }
  fibonacci_heap(std::initializer_list<value_type> il) { assign(il); }

  size_type size() const noexcept { return M_size; }
  bool empty() const noexcept { return M_size == 0; }

  const_reference const& top() const { return M_top->M_value; }
  void pop() {
    pointer root = M_top;
    for (auto it = M_roots.begin(); it != M_roots.end(); ++it) {
      if (*it == M_top) {
        M_roots.erase(it);
        break;
      }
    }
    if (root->M_child) {
      pointer cur = root->M_child;
      do {
        pointer tmp = cur->M_right;
        cur->M_left = cur->M_right = cur->M_parent = nullptr;
        cur->M_damaged = false;
        M_roots.push_back(cur);
        cur = tmp;
      } while (cur && cur != root->M_child);
      root->M_child = nullptr;
    }
    --M_size;
    M_coleasce();
  }

  node_handle push(key_type const& key, mapped_type const& mapped) {
    pointer newnode = std::make_shared<node>(key, mapped);
    newnode->M_left = newnode->M_right = nullptr;
    M_roots.push_back(newnode);
    if (M_size == 0 || M_comp(M_top->M_value.first, key)) M_top = newnode;
    ++M_size;
    return node_handle(newnode);
  }

  void meld(fibonacci_heap& other) {
    M_size += other.M_size;
    other.M_size = 0;

    M_roots.splice(M_roots.end(), other.M_roots);
    if (M_comp(M_top->M_value.first, other.M_top->M_value.first))
      M_top = other.M_top;
  }

  void prioritize(node_handle& nh, key_type const& key) {
    pointer cur(nh.M_node);
    // assert(M_comp(cur->M_value.first, key));
    cur->M_value.first = key;
    if (M_comp(M_top->M_value.first, key)) M_top = cur;
    if (!cur->M_parent || !M_comp(cur->M_parent->M_value.first, key)) return;

    bool more_cut = true;
    while (more_cut) {
      pointer parent = cur->M_parent;
      more_cut = !S_detach_child(parent, cur);
      M_roots.push_back(cur);
      cur = parent;
    }
  }
};


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

