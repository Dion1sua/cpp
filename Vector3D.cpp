#include <iostream>

class Vector3D {
private:
    double x;
    double y;
    double z;

public:
    Vector3D() : x(0), y(0), z(0) {}
    Vector3D(double xCoord, double yCoord, double zCoord) : x(xCoord), y(yCoord), z(zCoord) {}
    Vector3D(const Vector3D& other) : x(other.x), y(other.y), z(other.z) {}

    Vector3D& operator=(const Vector3D& other);
    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    bool operator==(const Vector3D& other) const;
    bool operator!=(const Vector3D& other) const;

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
};

Vector3D& Vector3D::operator=(const Vector3D& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }
    return *this;
}

Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(x + other.x, y + other.y, z + other.z);
}

Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(x - other.x, y - other.y, z - other.z);
}

bool Vector3D::operator==(const Vector3D& other) const {
    return (x == other.x) && (y == other.y) && (z == other.z);
}

bool Vector3D::operator!=(const Vector3D& other) const {
    return !(*this == other);
}

int main() {
    using namespace std;

    double x1, y1, z1, x2, y2, z2;

    cout << "Enter coordinates for vector 1 (x y z): ";
    cin >> x1 >> y1 >> z1;
    cout << "Enter coordinates for vector 2 (x y z): ";
    cin >> x2 >> y2 >> z2;

    Vector3D v1(x1, y1, z1);
    Vector3D v2(x2, y2, z2);
    Vector3D v3 = v1 + v2;
    Vector3D v4 = v2 - v1;

    cout << "v3 = (" << v3.getX() << ", " << v3.getY() << ", " << v3.getZ() << ")" << endl;
    cout << "v4 = (" << v4.getX() << ", " << v4.getY() << ", " << v4.getZ() << ")" << endl;

    if (v1 == v2)
        cout << "v1 and v2 are equal" << endl;
    else
        cout << "v1 and v2 are not equal" << endl;

    return 0;
}
