struct pos : public pair<int, int> {
  using pair<int, int>::pair;
  int& r = first;
  int& c = second;
  int& x = second;
  int& y = first;
  pos operator+(const pos& rhs) {
    return pos(*this) += rhs;
  }
  pos operator-(const pos& rhs) {
    return pos(*this) -= rhs;
  }
  pos& operator+=(const pos& rhs) {
    r += rhs.r;
    c += rhs.c;
    return *this;
  }
  pos& operator-=(const pos& rhs) {
    r -= rhs.r;
    c -= rhs.c;
    return *this;
  }
  bool inside(int h, int w) {
    return 0 <= r and r < h and 0 <= c and c < w;
  }
};

pos di[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};