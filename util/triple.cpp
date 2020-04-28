
template <typename T, typename U, typename V>
struct triple {
  T first;
  U second;
  V third;
  triple(T fs, U sn, V th): first(fs), second(sn), third(th) { }
  operator tuple<T, U, V>() const { return make_tuple(first, second, third); }
};

template <typename T, typename U, typename V>
triple<T, U, V> make_triple(T fs, U sn, V th) { return triple<T, U, V>(fs, sn, th); }

template <size_t I, typename T, typename U, typename V>
typename std::tuple_element_t<I, tuple<T, U, V>>& get(triple<T, U, V>& t) {
  return get<I>(tuple<T&, U&, V&>(t.first, t.second, t.third));
}

template <size_t I, typename T, typename U, typename V>
const typename std::tuple_element_t<I, tuple<T, U, V>>& get(const triple<T, U, V>& t) {
  return get<I>(tuple<T, U, V>(t));
}

template <size_t I, typename T, typename U, typename V>
typename std::tuple_element_t<I, tuple<T, U, V>>&& get(triple<T, U, V>&& t) {
  return get<I>(tuple<T, U, V>(move(t)));
}
