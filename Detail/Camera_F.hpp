#ifndef SPTRACING_CAMERA_HPP
#define SPTRACING_CAMERA_HPP


#include "Vector.hpp"
#include "Ray3.hpp"

const float PI = (const float) 3.141592653589793238462643383;

class Camera_F {
public:
    Camera_F(const Vector3& eye, const Vector3& front, const Vector3& up, float fov)
            : eye(eye), front(front), ref_up(up), fov(fov),
              right(Vector3::zero()),
              up(Vector3::zero()), fov_scale(0) { }

    void initialize()
    {
        right = front.cross(ref_up);
        up = right.cross(front);
        fov_scale = tanf(fov * (PI * 0.5f / 180)) * 2;
    }

    Ray3 generate_ray(float x, float y) const
    {
        Vector3 r = right * ((x - 0.5f) * fov_scale);
        Vector3 u = up * ((y - 0.5f) * fov_scale);
        return Ray3(eye, (front + r + u).normalize());
    }
private:
    Vector3 eye;
    Vector3 front;
    Vector3 ref_up;
    float fov;

    Vector3 right;
    Vector3 up;
    float fov_scale;
};


#endif //SPTRACING_CAMERA_HPP
