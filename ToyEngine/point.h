#pragma once
#include <assert.h>
#include "scalar.h"
#include "vector.h"

class Point {
public:
    Scalar x, y, z;

    Point(Scalar a, Scalar b, Scalar c): x(a), y(b), z(c) {}
    Point(): Point(0,0,0) {}

    Vector operator- (Point other) const {
        return Vector(x-other.x, y-other.y, z-other.z);
    }
    Point operator- (Vector other) const {
        return Point(x-other.x, y-other.y, z-other.z);
    }

    Point operator+ (Vector other) const {
        return Point(x+other.x, y+other.y, z+other.z);
    }
    void operator+= (Vector other) {
        *this = *this + other;
    }
    void operator-= (Vector other) {
        *this = *this - other;
    }

    // Explicit casts
    Vector asVector() const { return Vector(x, y, z); }
    Vector& asVector() { return *(Vector*)this; }

    // Direct coordinate access
    Scalar operator[](int index) const {
        assert((index>=0) && (index<=2) && "Invalid index");
        return ((Scalar*)this)[index];
    }
    Scalar& operator[](int index) {
        assert((index>=0) && (index<=2) && "Invalid index");
        return ((Scalar*)this)[index];
    }
};