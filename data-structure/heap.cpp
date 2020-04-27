template <typename T, typename Compare = less<>>
class heap {
 private:
  Compare comp;

 public:
  vector<T> data;
  heap(Compare comp = Compare()) : data(), comp(comp) {}
  heap(const vector<T>& data, Compate comp = Compare())
      : data(data), comp(comp) {
    build();
  }
  heap(vector<T>&& data, Compare comp = Compare()) : data(data), comp(comp) {
    build();
  }
  void build() { make_heap(all(data), comp); }
  size_t size() { return data.size(); }
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
  T top() { return data.front(); }
  T pop() {
    pop_heap(all(data), comp);
    T popped = move(data.back());
    data.pop_back();
    return popped;
  }
};
