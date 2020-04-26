
template <typename F, typename T = ll>
class Swag {
 private:
  vector<T> L, R;
  vector<T> accL, accR;
  const T unit;
  const F f;

 public:
  Swag(T _unit = T(), F _f = F())
      : L(), R(), accL(), accR(), unit(_unit), f(_f) {}
  template <typename Iter>
  Swag(Iter first, Iter last, T _unit = T(), F _f = F())
      : L(make_reverse_iterator(last), make_reverse_iterator(first)),
        R(), accL(), accR(), unit(_unit), f(_f) {
    buildL();
  }

 public:
  void push(T x) {
    R.push_back(x);
    accR.push_back(accR.empty() ? x : f(accR.back(), x));
  }

  void pop() {
    prepareL();
    L.pop_back();
    accL.pop_back();
  }

  T fold() const {
    T res = L.empty() ? unit : accL[L.size()-1];
    if (not R.empty())
      res = res == unit ? accR[R.size()-1] : f(res, accR[R.size()-1]);
    return res;
  }

 private:
  void buildL() {
    accL.resize(L.size());
    if (not accL.empty()) {
      accL[0] = L[0];
      rep(i, 1, accL.size()) accL[i] = f(L[i], accL[i-1]);
    }
  }

  void prepareL() {
    if (L.empty()) {
      reverse(all(R));
      swap(L, R);
      buildL();
      accR.clear();
    }
  }
};
