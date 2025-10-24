#include "../include/triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle() : vertices(3) {}

Triangle::Triangle(const std::vector<std::pair<double, double>>& points) {
    if (points.size() != 3) {
        throw std::invalid_argument("Triangle must have exactly 3 vertices");
    }
    vertices = points;
}

Triangle::Triangle(const Triangle& other) : vertices(other.vertices) {}

Triangle::Triangle(Triangle&& other) noexcept : vertices(std::move(other.vertices)) {}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

bool Triangle::operator==(const Figure& other) const {
    const Triangle* otherTri = dynamic_cast<const Triangle*>(&other); //попытка приведения типа к Triangle, если не получится вернет nullptr
    if (!otherTri) return false;
    return vertices == otherTri->vertices;
}

double Triangle::area() const {
    double x1 = vertices[0].first, y1 = vertices[0].second;
    double x2 = vertices[1].first, y2 = vertices[1].second;
    double x3 = vertices[2].first, y3 = vertices[2].second;
    
    return std::abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0); //считаем через определитель деленный на 2.0
}

std::pair<double, double> Triangle::geometric_center() const {
    double center_x = 0.0, center_y = 0.0;
    for (const auto& vertex : vertices) {
        center_x += vertex.first;
        center_y += vertex.second;
    }
    return {center_x / 3.0, center_y / 3.0};
}

void Triangle::print_vertices(std::ostream& os) const {
    os << "Triangle vertices: ";
    for (size_t i = 0; i < vertices.size(); i++) {
        os << "(" << vertices[i].first << ", " << vertices[i].second << ")";
        if (i != vertices.size() - 1) os << " ";
    }
}

void Triangle::read_from_stream(std::istream& is) {
    vertices.resize(3);
    for (int i = 0; i < 3; i++) {
        if (!(is >> vertices[i].first >> vertices[i].second)) {
            throw std::runtime_error("Invalid input for Triangle");
        }
    }
}
