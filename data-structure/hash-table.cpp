#pragma once

#include "template.cpp"

#include <random>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

struct chash {
  random_device rd;
  const ull RANDOM = uniform_int_distribution<ull>(0)(rd);
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
