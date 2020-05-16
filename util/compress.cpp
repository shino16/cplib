#pragma once

#include "template.cpp"

template <typename T = ll>
class Compress {
 private:
  vector<T> data;
  bool built = false;

 public:
  Compress() {}
  template <typename Iter>
  Compress(Iter first, Iter last) : data(first, last) {
    build();
  }

 private:
  void build() {
    if (not built) {
      sort(data.begin(), data.end());
      data.erase(unique(data.begin(), data.end()), data.end());
      built = true;
    }
  }

 public:
  void insert(T v) {
    built = false;
    data.push_back(v);
  }
  template <typename... Args>
  void emplace(Args&&... args) {
    built = false;
    data.emplace_back(forward<Args>(args)...);
  }
  int size() {
    build();
    return data.size();
  }
  int operator()(T v) {
    build();
    assert(binary_search(data.begin(), data.end(), v));
    return std::lower_bound(data.begin(), data.end(), v) - data.begin();
  }
  T restore(int i) {
    build();
    return data[i];
  }
  T operator[](int i) { return restore(i); }
  auto begin() { build(); return data.begin(); }
  auto end() { build(); return data.end(); }
};
