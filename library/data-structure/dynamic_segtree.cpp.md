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


# :warning: data-structure/dynamic_segtree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/dynamic_segtree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 23:28:13+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

struct Node {
  Node *left, *right;
  ll v;

  Node() : left(nullptr), right(nullptr), v(0) {}
};

// Dynamic Segment Tree
class SegmentTree {
  Node *root;
  int n, n0;

  ll fold(int a, int b, Node *n, int l, int r) {
    if(a <= l && r <= b) {
      return n->v;
    }
    if(r <= a || b <= l) {
      return 0;
    }

    ll lv = n->left ? fold(a, b, n->left, l, (l + r) >> 1) : 0;
    ll rv = n->right ? fold(a, b, n->right, (l + r) >> 1, r) : 0;
    return lv + rv;
  }

public:
  SegmentTree(int n) : n(n) {
    n0 = 1;
    while(n0 < n) n0 <<= 1;
    root = new Node();
  }
  ~SegmentTree() {
    delete root; root = nullptr;
  }

  void update(int k, ll x) {
    Node *n = root;
    int l = 0, r = n0;
    n->v = (n->v + x);
    while(r-l > 1) {
      int m = (l + r) >> 1;
      if(k < m) {
        if(!n->left) n->left = new Node();
        n = n->left;

        r = m;
      } else {
        if(!n->right) n->right = new Node();
        n = n->right;

        l = m;
      }
      n->v = n->v + x;
    }
  }

  ll fold(int a, int b) {
    return fold(a, b, root, 0, n0);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data-structure/dynamic_segtree.cpp"

struct Node {
  Node *left, *right;
  ll v;

  Node() : left(nullptr), right(nullptr), v(0) {}
};

// Dynamic Segment Tree
class SegmentTree {
  Node *root;
  int n, n0;

  ll fold(int a, int b, Node *n, int l, int r) {
    if(a <= l && r <= b) {
      return n->v;
    }
    if(r <= a || b <= l) {
      return 0;
    }

    ll lv = n->left ? fold(a, b, n->left, l, (l + r) >> 1) : 0;
    ll rv = n->right ? fold(a, b, n->right, (l + r) >> 1, r) : 0;
    return lv + rv;
  }

public:
  SegmentTree(int n) : n(n) {
    n0 = 1;
    while(n0 < n) n0 <<= 1;
    root = new Node();
  }
  ~SegmentTree() {
    delete root; root = nullptr;
  }

  void update(int k, ll x) {
    Node *n = root;
    int l = 0, r = n0;
    n->v = (n->v + x);
    while(r-l > 1) {
      int m = (l + r) >> 1;
      if(k < m) {
        if(!n->left) n->left = new Node();
        n = n->left;

        r = m;
      } else {
        if(!n->right) n->right = new Node();
        n = n->right;

        l = m;
      }
      n->v = n->v + x;
    }
  }

  ll fold(int a, int b) {
    return fold(a, b, root, 0, n0);
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

