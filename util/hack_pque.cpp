#pragma once

template <class T, class S, class C>
S& hack(priority_queue<T, S, C>& q) {
  struct HackedQueue : private priority_queue<T, S, C> {
    static S& hack(priority_queue<T, S, C>& q) {
      return q.*&HackedQueue::c;
    }
  };
  return HackedQueue::hack(q);
}
