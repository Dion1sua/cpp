
#include "triangle.h"
Triangle::Triangle(const Point& apex1, const Point& apex2, const Point& apex3)
    : apex1(apex1), apex2(apex2), apex3(apex3) {}
void Triangle::move(double dx, double dy) {
    apex1.move(dx, dy);
    apex2.move(dx, dy);
    apex3.move(dx, dy);
}
void Triangle::resize(double scaleFactor) {
    
}
void Triangle::rotate(double angle) {
  
}
