#include <iostream>
#include <assert.h>

typedef float Scalar;

class Vector {
public:
    Scalar x, y, z;

    Vector();
    Vector(Scalar a, Scalar b, Scalar c);

    Vector sum(const Vector &other) const;
    Vector operator+(const Vector &other) const;
    Scalar dot(const Vector &other) const;
};

Vector::Vector(): x(0), y(0), z(0) {}
Vector::Vector(Scalar a, Scalar b, Scalar c): x(a), y(b), z(c) {}

Vector Vector::sum(const Vector &other) const {
    return Vector(x + other.x, y + other.y, z + other.z);
}

Vector Vector::operator+(const Vector &other) const {
    return Vector(x + other.x, y + other.y, z + other.z);
}

Scalar Vector::dot(const Vector &other) const {
    return x * other.x + y * other.y + z * other.z;
}

bool isEqual(Scalar s1, Scalar s2) {
    return (s1-s2)*(s1-s2) < 1e-8;
}

bool isEqual(Vector v1, Vector v2) {
    return isEqual(v1.x, v2.x) && isEqual(v1.y, v2.y) && isEqual(v1.z, v2.z);
}

// Tests
void unitTestSumIsCommutative() {
    Vector v(1, 2, 3), w(4, 5, 6);
    assert(isEqual(v+w, w+v));
}

int main() {
    Vector v, w(2, 3, 5);
    v.x = 2;
    v = v + w;
    unitTestSumIsCommutative();
    return 0;
}