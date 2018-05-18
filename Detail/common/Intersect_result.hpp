//
// Created by ksar on 17-3-12.
//

#ifndef SPTRACING_INTERSECT_RESULT_HPP
#define SPTRACING_INTERSECT_RESULT_HPP


#include "../Vector.hpp"


struct IGeometry;

class Intersect_result {
public:
    Intersect_result():geometry(nullptr), distance(0), position(Vector3(0,0,0)), normal(Vector3(0,0,0)) {}
    ~Intersect_result() { }

    static Intersect_result no_hit()
    {
        return Intersect_result();
    }

    IGeometry* geometry;
    float distance;
    Vector3 position;
    Vector3 normal;

};


#endif //SPTRACING_INTERSECT_RESULT_HPP
