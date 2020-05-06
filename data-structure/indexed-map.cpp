#pragma once

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename K, typename V>
using indexed_map =
    tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
