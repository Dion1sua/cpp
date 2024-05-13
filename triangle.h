
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"

class Triangle {
private:
    Point apex1, apex2, apex3; 

public:
    Triangle(const Point& apex1, const Point& apex2, const Point& apex3);
    void move(double dx, double dy); 
    void resize(double scaleFactor); 
    void rotate(double angle); 
};

#endif 
