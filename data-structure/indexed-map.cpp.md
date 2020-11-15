---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/indexed-map.cpp\"\n\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\nusing namespace __gnu_pbds;\n\ntemplate\
    \ <typename K, typename V>\nusing indexed_map =\n    tree<K, V, less<K>, rb_tree_tag,\
    \ tree_order_statistics_node_update>;\n"
  code: "#pragma once\n\n#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    using namespace __gnu_pbds;\n\ntemplate <typename K, typename V>\nusing indexed_map\
    \ =\n    tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/indexed-map.cpp
  requiredBy: []
  timestamp: '2020-05-06 17:34:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/indexed-map.cpp
layout: document
redirect_from:
- /library/data-structure/indexed-map.cpp
- /library/data-structure/indexed-map.cpp.html
title: data-structure/indexed-map.cpp
---
