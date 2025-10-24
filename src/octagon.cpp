#include "../include/octagon.h"
#include <iostream>
#include <cmath>

Octagon::Octagon() : vertices(8) {}

Octagon::Octagon(const std::vector<std::pair<double, double>>& points) {
    if (points.size() != 8) {
        throw std::invalid_argument("Octagon must have exactly 8 vertices");
    }
    vertices = points;
}

Octagon::Octagon(const Octagon& other) : vertices(other.vertices) {}

Octagon::Octagon(Octagon&& other) noexcept : vertices(std::move(other.vertices)) {}

Octagon& Octagon::operator=(const Octagon& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Octagon& Octagon::operator=(Octagon&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

bool Octagon::operator==(const Figure& other) const {
    const Octagon* otherOct = dynamic_cast<const Octagon*>(&other);
    if (!otherOct) return false;
    return vertices == otherOct->vertices;
}

double Octagon::area() const {
    double area = 0.0;
    for (size_t i = 0; i < 8; i++) {
        size_t j = (i + 1) % 8;
        area += vertices[i].first * vertices[j].second;
        area -= vertices[j].first * vertices[i].second;
    }
    return std::abs(area) / 2.0;
}

std::pair<double, double> Octagon::geometric_center() const {
    double center_x = 0.0, center_y = 0.0;
    for (const auto& vertex : vertices) {
        center_x += vertex.first;
        center_y += vertex.second;
    }
    return {center_x / 8.0, center_y / 8.0};
}

void Octagon::print_vertices(std::ostream& os) const {
    os << "Octagon vertices: ";
    for (size_t i = 0; i < vertices.size(); i++) {
        os << "(" << vertices[i].first << ", " << vertices[i].second << ")";
        if (i != vertices.size() - 1) os << " ";
    }
}

void Octagon::read_from_stream(std::istream& is) {
    vertices.resize(8);
    for (int i = 0; i < 8; ++i) {
        if (!(is >> vertices[i].first >> vertices[i].second)) {
            throw std::runtime_error("Invalid input for Octagon");
        }
    }
}
