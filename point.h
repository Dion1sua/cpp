
#ifndef POINT_H
#define POINT_H

class Point {
protected:
    double x, y; 

public:
    Point(double x = 0, double y = 0); 
    double getX() const;
    double getY() const;
    void setX(double newX); 
    void setY(double newY); 
    void move(double dx, double dy); 
};

#endif
