#pragma once

template <typename T = ll>
class Compress {
 private:
  vector<T> data;
  bool built;

 public:
  Compress() { build(); }
  template <typename Iter>
  Compress(Iter first, Iter last) : data(first, last) {
    build();
  }

 private:
  void build() {
    if (not built) {
      sort(all(data));
      data.erase(unique(all(data)), data.end());
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
  int operator[](T v) {
    build();
    assert(binary_search(all(data), v));
    return std::lower_bound(all(data), v) - data.begin();
  }
  T restore(int i) {
    build();
    return data[i];
  }
  int lower_bound(T v) {
    build();
    return std::lower_bound(all(data), v) - data.begin();
  }
  int upper_bound(T v) {
    build();
    return std::upper_bound(all(data), v) - data.begin();
  }
  bool count(T v) {
    build();
    return std::binary_search(all(data), v);
  }
};
