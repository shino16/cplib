template <typename T, typename Compare = less<T>>
struct heap {
  vector<T> data;
  heap(const vector<T>& data) : data(data) {
    build();
  }
  heap(vector<T>&& data) : data(data) {
    build();
  }
  void build() {
    make_heap(all(data), comp);
  }
  void push(const T& value) {
    data.push_back(value);
    push_heap(all(data), comp);
  }
  void push(T&& value) {
    data.push_back(value);
    push_heap(all(data), comp);
  }
  template <typename... Args>
  void emplace(Args&&... args) {
    data.emplace_back(forward<Args>(args)...);
    push_heap(all(data), comp);
  }
  T top() {
    return data.front();
  }
  T pop() {
    pop_heap(all(data), comp);
    T popped = move(data.back());
    data.pop_back();
    return popped;
  }
private:
  Compare comp;
};
