#pragma once
#include "Geometry/Vector.hpp"
#include <vector>

class Shape{
public:
    Shape(std::vector<Vector> vertices);

    Vector getVertexVectorByIndex(uint index) const;
    int    getVerticesNumber() const;
private:
    const std::vector<Vector> vertices;
};
