#pragma once

#include "template.cpp"

class Mapping {
 public:
  struct op {
    Mapping operator()(const Mapping& lhs, const Mapping& rhs) {
      return {};
    }
  };
};

template <typename T, typename Combine = typename T::op>
class Doubling {
 private:
  vector<T> data;
};