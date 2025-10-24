#include "../include/hexagon.h"
#include <iostream>
#include <cmath>

Hexagon::Hexagon() : vertices(6) {}

Hexagon::Hexagon(const std::vector<std::pair<double, double>>& points) {
    if (points.size() != 6) {
        throw std::invalid_argument("Hexagon must have exactly 6 vertices");
    }
    vertices = points;
}

Hexagon::Hexagon(const Hexagon& other) : vertices(other.vertices) {}

Hexagon::Hexagon(Hexagon&& other) noexcept : vertices(std::move(other.vertices)) {}

Hexagon& Hexagon::operator=(const Hexagon& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Hexagon& Hexagon::operator=(Hexagon&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

bool Hexagon::operator==(const Figure& other) const {
    const Hexagon* otherHex = dynamic_cast<const Hexagon*>(&other);
    if (!otherHex) return false;
    return vertices == otherHex->vertices;
}

double Hexagon::area() const {
    double area = 0.0;
    for (size_t i = 0; i < 6; i++) {
        size_t j = (i + 1) % 6; //обеспечивает правильное замыкание
        area += vertices[i].first * vertices[j].second;
        area -= vertices[j].first * vertices[i].second;
    }
    return std::abs(area) / 2.0;
}

std::pair<double, double> Hexagon::geometric_center() const {
    double center_x = 0.0, center_y = 0.0;
    for (const auto& vertex : vertices) {
        center_x += vertex.first;
        center_y += vertex.second;
    }
    return {center_x / 6.0, center_y / 6.0};
}

void Hexagon::print_vertices(std::ostream& os) const {
    os << "Hexagon vertices: ";
    for (size_t i = 0; i < vertices.size(); ++i) {
        os << "(" << vertices[i].first << ", " << vertices[i].second << ")";
        if (i != vertices.size() - 1) os << " ";
    }
}

void Hexagon::read_from_stream(std::istream& is) {
    vertices.resize(6);
    for (int i = 0; i < 6; i++) {
        if (!(is >> vertices[i].first >> vertices[i].second)) {
            throw std::runtime_error("Invalid input for Hexagon");
        }
    }
}
