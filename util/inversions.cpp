#pragma once

#include "template.cpp"
#include "data-structure/bit.cpp"

template <typename Iter>
ll inversions(Iter first, Iter last) {
  int n = distance(first, last);
  int max = *max_element(first, last);
  BIT bit(max+1);
  ll res = 0;
  for (int i = 0; first != last; first++, i++) {
    res += i - bit.sum(*first + 1);
    bit.add(*first, 1);
  }
  return res;
}
