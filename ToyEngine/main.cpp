#include <iostream>
#include <assert.h>
#include "scalar.h"
#include "vector.h"
#include "point.h"

// POD: Plain old data
struct Plane{
    Point p;
    Vector n;
};

struct Ray{
    Point start;
    Vector dir;
};

// TESTS
void unitTestSumIsCommutative() {
    Vector v(1, 2, 3), w(4, 5, 6);
    assert(isEqual(v+w, w+v));
}

void unitTestCross() {
    Vector v(1, 2, 3), w(4, 5, 6);
    assert(isEqual(cross(v, w), -cross(w, v)));
    // Resulting vector is orthogonal to both
    assert(isZero(dot(cross(v,w), v)));
    assert(isZero(dot(cross(v,w), w)));
}

// CURIOSITY

// Reflect ray v off surface with normal n
Vector rayReflection(Vector v, Vector n) {
    return v - (2 * dot(n, v)) * n;
}

// Point-plane intersection
Point intersection(Plane plane, Ray ray) {
    Scalar k = dot(plane.p - ray.start, plane.n)/
                dot(ray.dir, plane.n);
    return ray.start + k*ray.dir;
}

int main() {
    Vector v, w(2, 3, 5);
    v[0] = 2;
    Scalar foo = v[0]+5;
    v = v + w;
    unitTestSumIsCommutative();
    unitTestCross();
    std::cout << rayReflection(v , w).x << std::endl;
    return 0;
}