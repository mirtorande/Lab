#include <iostream>

typedef float Scalar;

class Vector {
public:
    Scalar x, y, z;

    Vector();
    Vector(Scalar a, Scalar b, Scalar c);

    Vector sum(Vector other) const;
    Scalar dot(Vector other) const;
};

Vector::Vector(): x(0), y(0), z(0) {}
Vector::Vector(Scalar a, Scalar b, Scalar c): x(a), y(b), z(c) {}

Vector Vector::sum(Vector other) const {
    return Vector(x + other.x, y + other.y, z + other.z);
}

Scalar Vector::dot(Vector other) const {
    return x * other.x + y * other.y + z * other.z;
}

int main() {
    Vector v, w(2, 3, 5);
    v.x = 2;
    v = v.sum(w);
    Scalar k = v.dot(w);
    return 0;
}