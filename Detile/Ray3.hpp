#ifndef SPTRACING_RAY_HPP
#define SPTRACING_RAY_HPP


#include "Vector.hpp"

class Ray3 {
public:
    Ray3(const Vector3& o, const Vector3& d): origin(o), direction(d) {}
    Ray3(const Ray3& ray): origin(ray.origin), direction(ray.direction) {}
    ~Ray3() {}

    Ray3& operator = (const Ray3& ray)
    {
        origin = ray.origin;
        direction = ray.direction;
        return *this;
    }

    //r(t) = o + td, t >= 0
    Vector3 get_point(const float t) const
    {
        return origin + direction * t;
    }

    Vector3 origin, direction;

private:
    Ray3() {}
};


#endif //SPTRACING_RAY_HPP
