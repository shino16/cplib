#pragma once

#include "template.cpp"

template <typename T, typename Compare = less<>>
class BinaryHeap {
 private:
  vector<T> data;
  vector<int> index, handle;
  const Compare comp;

 public:
  BinaryHeap(Compare comp_ = {}) : comp(comp_) {}
  template <typename Iter>
  BinaryHeap(Iter first, Iter last, Compare comp_ = {}) : comp(comp_) {
    data.insert(data.end(), first, last);
    index.resize(data.size());
    handle.resize(data.size());
    iota(all(index), 0);
    iota(all(handle), 0);
    repr(i, divceil(data.size(), 2)) pushdown(i);
  }

 private:
  void rotate(int i, int j) {
    swap(data[i], data[j]);
    swap(index[i], index[j]);
    swap(handle[index[i]], handle[index[j]]);
  }

  void pushup(int i) {
    int j;
    while (j = (i - 1) / 2, comp(data[j], data[i])) rotate(i, j), i = j;
  }

  void pushdown(int i) {
    int j;
    while (j = (i + 1) * 2, j < data.size()) {
      if (comp(data[j], data[j - 1])) j--;
      rotate(i, j), i = j;
    }
    j = i * 2 + 1;
    if (j < data.size() and comp(data[i], data[j])) rotate(i, j);
  }

 public:
  bool empty() { return data.empty(); }

  void push(int i, const T& v) { emplace(i, v); }
  void push(int i, T&& v) { emplace(i, move(v)); }

  template <typename... Args>
  void emplace(int i, Args&&... args) {
    if (i >= handle.size()) {
      int s = handle.size();
      handle.resize(i + 1);
      fill(handle.begin() + s, handle.end(), -1);
    }
    handle[i] = data.size();
    data.emplace_back(forward<Args>(args)...);
    index.push_back(i);
    pushup(handle[i]);
  }

  T& top() { return data[0]; }
  int top_index() { return index[0]; }

  void pop() { remove(0); }

  void remove(int i) {
    if (i != data.size() - 1) rotate(i, data.size() - 1);
    data.pop_back();
    handle[index.back()] = -1;
    index.pop_back();
    pushdown(i);
  }

  template <typename... Args>
  void prioritize(int i, Args&&... args) {
    if (i >= handle.size() or handle[i] == -1)
      emplace(i, forward<Args>(args)...);
    else {
      data[handle[i]] = T(forward<Args>(args)...);
      pushup(handle[i]);
      pushdown(handle[i]);
    }
  }
};
