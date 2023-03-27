#pragma once
#include "scalar.h"

class Vector {
public:
    Scalar x, y, z;

    Vector();
    Vector(Scalar a, Scalar b, Scalar c);

    Vector sum(const Vector &other) const;
    Vector operator+(const Vector &other) const;
    Vector operator-() const;
    Vector operator-(const Vector &other) const;
    Vector operator*(Scalar k) const;
};

inline Vector::Vector(): x(0), y(0), z(0) {}
inline Vector::Vector(Scalar a, Scalar b, Scalar c): x(a), y(b), z(c) {}

inline Vector Vector::sum(const Vector &other) const {
    return Vector(x + other.x, y + other.y, z + other.z);
}

// Sum
inline Vector Vector::operator+(const Vector &other) const {
    return Vector(x + other.x, y + other.y, z + other.z);
}

// Invert
inline Vector Vector::operator-() const {
    return Vector(-x, -y, -z);
}

// Subtract
inline Vector Vector::operator-(const Vector &other) const {
    return Vector(x - other.x, y - other.y, z - other.z);
}

// Scale
inline Vector Vector::operator*(Scalar k) const {
    return Vector(x*k, y*k, z*k);
}

// GLOBAL FUNCTIONS //

inline Scalar dot(const Vector& a, const Vector& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline Vector cross(const Vector& a, const Vector& b) {
    return Vector(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}

// Global function to allow for 2*v to be recognized (operator overloading)
inline Vector operator*(Scalar k, Vector v) {
    // Scalar product
    return v * k;
}

inline bool isZero(Vector v) {
    return isZero(dot(v, v));
}

inline bool isEqual(Vector v1, Vector v2) {
    return isEqual(v1.x, v2.x) && isEqual(v1.y, v2.y) && isEqual(v1.z, v2.z);
}