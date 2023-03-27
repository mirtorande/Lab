#pragma once

typedef float Scalar;

inline bool isZero(Scalar k) {
    return k < 1e-8;
}

inline bool isEqual(Scalar s1, Scalar s2) {
    return isZero((s1-s2)*(s1-s2));
}