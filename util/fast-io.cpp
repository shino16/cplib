
// IO
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
class MyScanner { public: int offset = 0; char nc(){ return getchar(); }
template <typename T> void input_integer(T& var) { var = 0; T sign = 1; int cc = nc(); for (;
cc < '0' || '9' < cc; cc = nc()) if (cc == '-') sign = -1; for (; '0' <= cc && cc <= '9'; cc =
nc()) var = (var << 3) + (var << 1) + cc - '0'; var = var * sign; var += offset; } int c() {
char c; while (c = nc(), c == ' ' or c == '\n'); return c; } MyScanner& operator>>(char& var)
{ var = c(); return *this; } MyScanner& operator>>(int& var) { input_integer<int>(var); return
*this; } MyScanner& operator>>(ll& var) { input_integer<ll>(var); return *this; } MyScanner&
operator>>(string& var) { var = ""; int cc = nc(); for (; !isgraph(cc); cc = nc()); for
(; isgraph(cc); cc = nc()) var.push_back(cc); return *this; } template <size_t N>
MyScanner& operator>>(bitset<N>& var) { ll v; input_integer<ll>(v); var = bitset<N>(v); return
*this; } template <typename T> operator T() { T x; *this >> x; return x; } template <typename
T> void operator()(T &t) { *this >> t; } template <typename T, typename... Ts> void operator()
(T &t, Ts &...ts) { *this >> t; this->operator()(ts...); } template <typename Iter> void iter
(Iter first, Iter last) { while (first != last) *this >> *first, first++; } VI vi(int n) { VI
res(n); iter(all(res)); return res; } VVI vvi(int n, int m) { VVI res(n); rep(i, n) res[i] =
vi(m); return res; } VLL vll(int n) { VLL res(n); iter(all(res)); return res; } VVLL vvll(int
n, int m) { VVLL res(n); rep(i, n) res[i] = vll(m); return res; } template <typename T> vector
<T> v(int n) { vector<T> res(n); iter(all(res)); return res; } } IN, IN1{-1}; class MyPrinter
{ public: int offset = 0; template <typename T> void output_integer(T var) { var += offset; if
(var == 0) { putchar('0'); return; } if (var < 0) putchar('-'), var = -var; char stack[32];
int stack_p = 0; while (var) stack[stack_p++] = '0' + (var % 10), var /= 10; while (stack_p)
putchar(stack[--stack_p]); } MyPrinter& operator<<(char c) { putchar(c); return *this; }
MyPrinter& operator<<(double x) { printf("%.10f", x); return *this; } template <typename T>
MyPrinter& operator<<(T var) { output_integer<T>(var); return *this; } MyPrinter& operator<<(
char* str_p) { while (*str_p) putchar(*(str_p++)); return *this; } MyPrinter& operator<<(const
char* str_p) { while (*str_p) putchar(*(str_p++)); return *this; } MyPrinter& operator<<(const
string& str) { const char* p = str.c_str(); const char* l = p + str.size(); while (p < l)
putchar(*p++); return *this; } template <typename T> void operator()(T x) { *this << x << newl
; } template <typename T, typename... Ts> void operator()(T x, Ts ...xs) { *this << x << " ";
this->operator()(xs...); } template <typename Iter> void iter(Iter s, Iter t) { if (s == t) *
this << "\n"; else for (; s != t; s++) *this << *s << " \n"[next(s, 1) == t]; } } OUT, OUT1{1}
; template <typename T, typename U> MyPrinter& operator<<(MyPrinter& out, const pair<T, U>&
var) { return out << var.first << " " << var.second; } template <typename Tuple, size_t I,
size_t N, enable_if_t<I == N>* = nullptr> MyPrinter& tuple_impl(MyPrinter& out, const Tuple&
var) { return out; } template <typename Tuple, size_t I, size_t N, enable_if_t<I != N>* =
nullptr> MyPrinter& tuple_impl(MyPrinter& out, const Tuple& var) { out << get<I>(var) << " ";
return tuple_impl<Tuple, I+1, N>(out, var); } template <typename... Ts> MyPrinter& operator<<(
MyPrinter& out, const tuple<Ts...>& var) { return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(
out, var); } template <typename T, typename U> MyScanner& operator>>(MyScanner& in, pair<T, U>
& var) { return in >> var.first >> var.second; } template <typename Tuple, size_t I, size_t N,
enable_if_t<I == N>* = nullptr> MyScanner& tuple_impl(MyScanner& in, Tuple& var) { return in;
} template <typename Tuple, size_t I, size_t N, enable_if_t<I != N>* = nullptr> MyScanner&
tuple_impl(MyScanner& in, Tuple& var) { in >> get<I>(var); return tuple_impl<Tuple, I+1, N>(in
, var); } template <typename... Ts> MyScanner& operator>>(MyScanner& in, tuple<Ts...>& var) {
return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(in, var); }

