#include "Core/Shape.hpp"

Shape::Shape(std::vector<Vector> vertices): vertices(std::move(vertices)) {};

Vector Shape::getVertexVectorByIndex(uint index) const{
    return vertices.at(index);
}

int Shape::getVerticesNumber() const{
    return (int) vertices.size();
}
