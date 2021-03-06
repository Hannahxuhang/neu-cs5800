#include <cmath>
#include "base.h"

Point::Point(double x, double y) : x_(x), y_(y) {
}

double Point::Norm() const {
  return sqrt(x_ * x_ + y_ * y_);
}

bool Point::IsClockwiseTo(const Point& o) const {
  return (*this) * o > 0.0;
}

bool Point::IsCounterClockwiseTo(const Point& o) const {
  return (*this) * o < 0.0;
}

bool Point::IsCollinearTo(const Point& o) const {
  return (*this) * o == 0.0;
}

double Point::x() const {
  return x_;
}

double Point::y() const {
  return y_;
}

bool Point::operator==(const Point& o) const {
  return x() == o.x() && y() == o.y();
}

double EuclideanDistance(const Point& a, const Point& b) {
  return sqrt((a.x() - b.x()) * (a.x() - b.x()) +
              (a.y() - b.y()) * (a.y() - b.y()));
}

double ManhattanDistance(const Point& a, const Point& b) {
  return fabs(a.x() - b.x()) + fabs(a.y() - b.y());
}

Point operator+(const Point& A, const Point& B) {
  return Point(A.x() + B.x(), A.y() + B.y());
}

Point operator-(const Point& A, const Point& B) {
  return Point(A.x() - B.x(), A.y() - B.y());
}

double operator^(const Point& A, const Point& B) {
  return A.x() * B.x() + A.y() * B.y();
}

double operator*(const Point& A, const Point& B) {
  return A.x() * B.y() - A.y() * B.x();
}
