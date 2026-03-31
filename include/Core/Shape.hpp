#pragma once
#include "Geometry/Point.hpp"
#include "Geometry/Vector.hpp"
#include <vector>

class Shape{
private:
    const std::vector<Vector> vertices;
public:
    Shape(std::vector<Vector> vertices): vertices(std::move(vertices)) {};

    Vector getVertexByIndex(int index) const { return       vertices.at(index); };
    int    getVerticesNumber()         const { return (int) vertices.size(); };
};
