#include <iostream>
#include "point.h"
#include "triangle.h"
using namespace std;

int main() {
    Point p1(1, 1);
    Point p2(4, 1);
    Point p3(2.5, 4);

    Triangle triangle(p1, p2, p3);

    int choice;
    do {
        cout << "1. Move triangle\n"
            << "2. Resize triangle\n"
            << "3. Rotate triangle\n"
            << "4. Exit\n"
            << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            double dx, dy;
            cout << "Enter the displacement (dx dy): ";
            cin >> dx >> dy;
            triangle.move(dx, dy);
            break;
        }
        case 2: {
            double scaleFactor;
            cout << "Enter the scale factor: ";
            cin >> scaleFactor;
            triangle.resize(scaleFactor);
            break;
        }
        case 3: {
            double angle;
            cout << "Enter the angle of rotation (in degrees): ";
            cin >> angle;
            triangle.rotate(angle);
            break;
        }
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
