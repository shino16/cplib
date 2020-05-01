#pragma once

#include "template.cpp"

struct minT {
  template <typename T>
  T operator()(T a, T b) const {
    return min(a, b);
  }
};

struct maxT {
  template <typename T>
  T operator()(T a, T b) const {
    return max(a, b);
  }
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
struct assignT {
  template <typename T>
  T operator()(T a, T b, int k = 0) const { return b; }
};
#pragma GCC diagnostic pop

struct plusT {
  template <typename T>
  T operator()(T a, T b, int k) const { return a + b * k; }
};
