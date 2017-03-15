#ifndef SPTRACING_SPHERE_HPP
#define SPTRACING_SPHERE_HPP


#include "Vector.hpp"
#include "common/Intersect_result.hpp"
#include "Ray3.hpp"

class Sphere {
public:
    Sphere(const Vector3& c, float r) : center(c), radius(r) {}
    Sphere(const Sphere& s) : center(s.center), radius(s.radius) {}
    Sphere& operator = (Sphere& s)
    {
        center = s.center;
        radius = s.radius;
        return *this;
    }
    ~Sphere() {}

    float get_sqr_radius() const
    {
        return radius * radius;
    }

    virtual Intersect_result intersect(const Ray3& ray)
    {
        auto vec = ray.origin - center;
        float a0 = vec.sqr_length() - this->get_sqr_radius();
        float d_dot_vec = ray.direction.dot(vec);

        if (d_dot_vec <= 0)
        {
            auto discr = d_dot_vec * d_dot_vec - a0;
            if (discr >= 0)
            {
                Intersect_result result = Intersect_result();
                result.geometry = (IGeometry *) this;
                result.distance = -d_dot_vec - sqrtf(discr);
                result.position = ray.get_point(result.distance);
                result.normal = (result.position - center).normalize();
                return result;
            }
        }

        return Intersect_result::no_hit();
    }

private:
    Sphere() {}
    Vector3 center;
    float radius;
};


#endif //SPTRACING_SPHERE_HPP
