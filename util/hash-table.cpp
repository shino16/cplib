#pragma once

#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>

#include "template.cpp"
using namespace __gnu_pbds;

struct chash {
  const ull RANDOM =
      (ull)std::make_unique<char>().get() ^
      chrono::high_resolution_clock::now().time_since_epoch().count();
  template <typename T>
  ull operator()(T x) const {
    return x ^ RANDOM;
  }
  template <typename T, typename U>
  ull operator()(pair<T, U> x) const {
    return (*this)(x.first) * 31 + (*this)(x.second);
  }
};

template <typename K, typename V>
using hash_table = gp_hash_table<K, V, chash>;
