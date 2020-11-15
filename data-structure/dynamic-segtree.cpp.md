---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/dynamic-segtree.cpp\"\n\nstruct Node {\n\
    \  Node *left, *right;\n  ll v;\n\n  Node() : left(nullptr), right(nullptr), v(0)\
    \ {}\n};\n\n// Dynamic Segment Tree\nclass SegmentTree {\n  Node *root;\n  int\
    \ n, n0;\n\n  ll fold(int a, int b, Node *n, int l, int r) {\n    if(a <= l &&\
    \ r <= b) {\n      return n->v;\n    }\n    if(r <= a || b <= l) {\n      return\
    \ 0;\n    }\n\n    ll lv = n->left ? fold(a, b, n->left, l, (l + r) >> 1) : 0;\n\
    \    ll rv = n->right ? fold(a, b, n->right, (l + r) >> 1, r) : 0;\n    return\
    \ lv + rv;\n  }\n\npublic:\n  SegmentTree(int n) : n(n) {\n    n0 = 1;\n    while(n0\
    \ < n) n0 <<= 1;\n    root = new Node();\n  }\n  ~SegmentTree() {\n    delete\
    \ root; root = nullptr;\n  }\n\n  void update(int k, ll x) {\n    Node *n = root;\n\
    \    int l = 0, r = n0;\n    n->v = (n->v + x);\n    while(r-l > 1) {\n      int\
    \ m = (l + r) >> 1;\n      if(k < m) {\n        if(!n->left) n->left = new Node();\n\
    \        n = n->left;\n\n        r = m;\n      } else {\n        if(!n->right)\
    \ n->right = new Node();\n        n = n->right;\n\n        l = m;\n      }\n \
    \     n->v = n->v + x;\n    }\n  }\n\n  ll fold(int a, int b) {\n    return fold(a,\
    \ b, root, 0, n0);\n  }\n};\n"
  code: "#pragma once\n\nstruct Node {\n  Node *left, *right;\n  ll v;\n\n  Node()\
    \ : left(nullptr), right(nullptr), v(0) {}\n};\n\n// Dynamic Segment Tree\nclass\
    \ SegmentTree {\n  Node *root;\n  int n, n0;\n\n  ll fold(int a, int b, Node *n,\
    \ int l, int r) {\n    if(a <= l && r <= b) {\n      return n->v;\n    }\n   \
    \ if(r <= a || b <= l) {\n      return 0;\n    }\n\n    ll lv = n->left ? fold(a,\
    \ b, n->left, l, (l + r) >> 1) : 0;\n    ll rv = n->right ? fold(a, b, n->right,\
    \ (l + r) >> 1, r) : 0;\n    return lv + rv;\n  }\n\npublic:\n  SegmentTree(int\
    \ n) : n(n) {\n    n0 = 1;\n    while(n0 < n) n0 <<= 1;\n    root = new Node();\n\
    \  }\n  ~SegmentTree() {\n    delete root; root = nullptr;\n  }\n\n  void update(int\
    \ k, ll x) {\n    Node *n = root;\n    int l = 0, r = n0;\n    n->v = (n->v +\
    \ x);\n    while(r-l > 1) {\n      int m = (l + r) >> 1;\n      if(k < m) {\n\
    \        if(!n->left) n->left = new Node();\n        n = n->left;\n\n        r\
    \ = m;\n      } else {\n        if(!n->right) n->right = new Node();\n       \
    \ n = n->right;\n\n        l = m;\n      }\n      n->v = n->v + x;\n    }\n  }\n\
    \n  ll fold(int a, int b) {\n    return fold(a, b, root, 0, n0);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dynamic-segtree.cpp
  requiredBy: []
  timestamp: '2020-05-01 11:42:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/dynamic-segtree.cpp
layout: document
redirect_from:
- /library/data-structure/dynamic-segtree.cpp
- /library/data-structure/dynamic-segtree.cpp.html
title: data-structure/dynamic-segtree.cpp
---
