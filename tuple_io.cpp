template <typename OutStream, typename T, typename U>
OutStream& operator<<(OutStream& out, pair<T, U> var) {
  return out << var.first << " " << var.second;
}
template <typename OutStream, typename Tuple, size_t I, size_t N,
          enable_if_t<I == N>* = nullptr>
OutStream& tuple_impl(OutStream& out, Tuple var) {
  return out;
}
template <typename OutStream, typename Tuple, size_t I, size_t N,
          enable_if_t<I != N>* = nullptr>
OutStream& tuple_impl(OutStream& out, Tuple var) {
  out << get<I>(var) << " ";
  return tuple_impl<Tuple, I+1, N>(out, var);
}
template <typename OutStream, typename... Ts>
OutStream& operator<<(OutStream& out, tuple<Ts...> var) {
  return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(out, var);
}
template <typename InStream, typename T, typename U>
InStream& operator>>(InStream& in, pair<T, U>& var) {
  return in >> var.first >> var.second;
}
template <typename InStream, typename... Ts>
InStream& operator>>(InStream& in, tuple<Ts...>& var) {
  return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(in, var);
}
template <typename InStream, typename Tuple, size_t I, size_t N,
          enable_if_t<I == N>* = nullptr>
InStream& tuple_impl(InStream& in, Tuple& var) {
  return in;
}
template <typename InStream, typename Tuple, size_t I, size_t N,
          enable_if_t<I != N>* = nullptr>
InStream& tuple_impl(InStream& in, Tuple& var) {
  in >> get<I>(var);
  return tuple_impl<Tuple, I+1, N>(in, var);
}