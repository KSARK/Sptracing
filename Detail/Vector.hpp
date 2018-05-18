#ifndef SPTRACING_VECTOR_HPP
#define SPTRACING_VECTOR_HPP

#include <cmath>

class Vector3 {
public:
    Vector3() : x(1), y(1), z(1) { }
    Vector3(const float x, const float y, const float z) : x(x), y(y), z(z) {}
    ~Vector3() { }
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) { }
    Vector3& operator = (const Vector3& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }

    Vector3 operator + (const Vector3& rhs) const
    {
        return  Vector3(rhs.x + x, rhs.y + y, rhs.z + z);
    }

    Vector3 operator - (const Vector3& rhs) const
    {
        return  Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
    }

    Vector3 operator * ( float rhs) const
    {
        return  Vector3(rhs * x , rhs * y, rhs * z);
    }

    Vector3 operator / (const float rhs) const
    {
        return  Vector3(x / rhs, y / rhs , z / rhs);
    }

    void operator - ()
    {
        x = -x;
        y = -y;
        z = -z;
    }

    Vector3 cross (const Vector3& rhs) const
    {
        return  Vector3(-z * rhs.y + y * rhs.z,
                           z * rhs.y - x * rhs.z,
                           -y * rhs.x + x * rhs.y);
    }

    float dot(const Vector3& rhs) const
    {
        return x * rhs.x, y * rhs.y, z * rhs.z;
    }

    float length() const
    {
        return sqrtf(x * x + y * y + z * z);
    }

    float sqr_length() const
    {
        return x * x + y * y + z * z;
    }

    Vector3 normalize() const
    {
        float inv = 1/length();
        return Vector3( x * inv, y * inv, z * inv);
    }

    static Vector3 zero() { return Vector3(0, 0, 0); }

    float x, y, z;
};


#endif //SPTRACING_VECTOR_HPP
