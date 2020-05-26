#pragma once

#include "template.cpp"

template <typename T = int>
struct Pt {
  T x, y;

  Pt(T x_ = 0, T y_ = 0): x(x_), y(y_) { }

  Pt operator +(const Pt<T>& rhs) const {
    return Pt(x+rhs.x, y+rhs.y);
  }
  Pt operator -(const Pt<T>& rhs) const {
    return Pt(x-rhs.x, y-rhs.y);
  }
  Pt operator -() const {
    return Pt(-x, -y);
  }
  Pt operator *(const Pt<T>& rhs) const {
    return Pt(x*rhs.x - y*rhs.y, x*rhs.y + y*rhs.x);
  }
  Pt operator *(const T rhs) const {
    return Pt(x*rhs, y*rhs);
  }
  Pt& operator +=(const Pt<T>& rhs) {
    return *this = *this + rhs;
  }
  Pt& operator -=(const Pt<T>& rhs) {
    return *this = *this - rhs;
  }
  Pt& operator *=(const Pt<T>& rhs) {
    return *this = *this * rhs;
  }
  Pt& operator *=(const T rhs) {
    return *this = *this * rhs;
  }
  bool operator ==(const Pt<T>& rhs) const {
    return x == rhs.x and y == rhs.y;
  }
  bool operator !=(const Pt<T>& rhs) const {
    return not (*this == rhs);
  }
  double abs() const {
    return hypot(x, y);
  }
  T dot(const Pt<T>& rhs) const {
    return x*rhs.x + y*rhs.y;
  }
  T det(const Pt<T>& rhs) const {
    return x*rhs.y - y*rhs.x;
  }
};

template <typename OutStream, typename T>
OutStream& operator<<(OutStream& out, const Pt<T>& var) {
  return out << var.x << " " << var.y;
}

template <typename InStream, typename T>
InStream& operator>>(InStream& in, Pt<T>& var) {
  return in >> var.x >> var.y;
}
