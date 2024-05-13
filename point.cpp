#include "point.h"
Point::Point(double x, double y) : x(x), y(y) {}
double Point::getX() const {
    return x;
}
double Point::getY() const {
    return y;
}
void Point::setX(double newX) {
    x = newX;
}
void Point::setY(double newY) {
    y = newY;
}
void Point::move(double dx, double dy) {
    x += dx;
    y += dy;
}