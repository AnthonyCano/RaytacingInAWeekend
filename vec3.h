#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3{
public:
    double e[3];

    // Default constructor
    vec3() : e{0,0,0} {}

    // Parameterized Constructor
    vec3(double e0, double e1, double e2) : e{e0,e1,e2} {}

    // Methods to get the index easily (why?)
    double x() const {return e[0]; } // Cleaner to do v.x() than v.e[0]
    double y() const {return e[1]; }
    double z() const {return e[2]; }

    // Basic funcs

    // Make the vectors negative
    // Does not modify the original vector (enforced with const)
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]);}

    // This lets you read vector components using array syntax.
    // So we can do a = v[0]. Does not modify vetor
    double operator[](int i) const {return e[i]; }

    // Same thing as above but does let modify the vector and returns
    // a reference to a double
    // vec3 v(1,2,3);
    // v[0] = 10.0;
    // v[2] = -5.0;
    double& operator[](int i) { return e[i]; }

    // Adds each component of another vec3 to the curr one
    // Modifies in place and returns a reference to the same object
    vec3& operator+=(const vec3& v){
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    vec3& operator*=(double t){
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    // Get the fraction and call mult with that
    vec3& operator/=(double t)
    {
        return *this *= 1/t;
    }

    double length() const
    {
        return std::sqrt(length_squared());
    }

    double length_squared() const
    {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[0];
    }
};

// Alias for vec3
using point3 = vec3;

// Vector utility functions
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// Create a new vec3 that is the sum of two vecs
inline vec3 operator+(const vec3& u, const vec3& v){
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

// Same as above but for sub
inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

// Same but for component wise vector-vector mult
// Mult two vectors together
inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

// Multiply an entire vec by a single double t
inline vec3 operator*(double t, const vec3& v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

// just lets us do communatitve mult using the above def
inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

// Division
inline vec3 operator/(const vec3& v, double t) {
    return (1/t) * v;
}

// Dot product!
inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}

#endif