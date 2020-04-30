#pragma once

#include "string/rolling_hash.cpp"
#include "data-structure/segtree.cpp"
#include "data-structure/lazy_segtree.cpp"

namespace hash_monoid {

using namespace rolling_hash;

struct mergeT {
  Hash operator()(const Hash& lhs, const Hash& rhs) const {
    prepare_pows(rhs.length + 1);
    return Hash(mod(mul(lhs.value, pows[rhs.length]) + rhs.value),
                lhs.length + rhs.length);
  }
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
struct updT {
  Hash operator()(const Hash& lhs, char c, int k = 1) const {
    return Hash(c, k);
  }
};
#pragma GCC diagnostic pop

}  // namespace hash_monoid

using HashSegTree =
    SegmentTree<rolling_hash::Hash, hash_monoid::mergeT, hash_monoid::updT>;
using LazyHashSegTree =
    LazySegmentTree<rolling_hash::Hash, char, hash_monoid::mergeT, assignT,
                    hash_monoid::updT>;
