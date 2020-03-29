template <typename T, typename U>
ostream& operator<<(ostream& out, pair<T, U> var) {
  return out << var.first << " " << var.second;
}
template <typename Tuple, size_t I, size_t N,
          enable_if_t<I == N>* = nullptr>
ostream& tuple_impl(ostream& out, Tuple var) {
  return out;
}
template <typename Tuple, size_t I, size_t N,
          enable_if_t<I != N>* = nullptr>
ostream& tuple_impl(ostream& out, Tuple var) {
  out << get<I>(var) << " ";
  return tuple_impl<Tuple, I+1, N>(out, var);
}
template <typename... Ts>
ostream& operator<<(ostream& out, tuple<Ts...> var) {
  return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(out, var);
}
template <typename T, typename U>
MyPrinter& operator<<(MyPrinter& out, pair<T, U> var) {
  return out << var.first << " " << var.second;
}
template <typename Tuple, size_t I, size_t N,
          enable_if_t<I == N>* = nullptr>
MyPrinter& tuple_impl(MyPrinter& out, Tuple var) {
  return out;
}
template <typename Tuple, size_t I, size_t N,
          enable_if_t<I != N>* = nullptr>
MyPrinter& tuple_impl(MyPrinter& out, Tuple var) {
  out << get<I>(var) << " ";
  return tuple_impl<Tuple, I+1, N>(out, var);
}
template <typename... Ts>
MyPrinter& operator<<(MyPrinter& out, tuple<Ts...> var) {
  return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(out, var);
}
template <typename T, typename U>
MyScanner& operator>>(MyScanner& in, pair<T, U>& var) {
  return in >> var.first >> var.second;
}
template <typename... Ts>
MyScanner& operator>>(MyScanner& in, tuple<Ts...>& var) {
  return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(in, var);
}
template <typename Tuple, size_t I, size_t N,
          enable_if_t<I == N>* = nullptr>
MyScanner& tuple_impl(MyScanner& in, Tuple& var) {
  return in;
}
template <typename Tuple, size_t I, size_t N,
          enable_if_t<I != N>* = nullptr>
MyScanner& tuple_impl(MyScanner& in, Tuple& var) {
  in >> get<I>(var);
  return tuple_impl<Tuple, I+1, N>(in, var);
}