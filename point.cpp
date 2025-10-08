
struct Point {
  double r, c;
  double absd(){
    return sqrt(r*r + c*c);
  }
  Point operator*(double a) const { return {r * a, c * a}; }
  Point operator+(const Point &a) const { return {r + a.r, c + a.c}; }
  Point operator-(const Point &a) const { return {r - a.r, c - a.c}; }
  bool operator==(const Point &a) const { return r == a.r && c == a.c; }
};
