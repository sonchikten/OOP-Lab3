#include "../include/figure.h"
#include <cmath>

bool is_valid_polygon(const std::vector<std::pair<double, double>>& vertices) {
    if (vertices.size() < 3) return false;
    
    double area = 0.0;
    size_t n = vertices.size();
    for (size_t i = 0; i < n; i++) {
        size_t j = (i + 1) % n;
        area += vertices[i].first * vertices[j].second;
        area -= vertices[j].first * vertices[i].second;
    }
    area = std::abs(area) / 2.0;
    
    if (area < 1e-10) return false;
    
    for (size_t i = 0; i < vertices.size(); i++) {
        for (size_t j = i + 1; j < vertices.size(); j++) {
            double dx = vertices[i].first - vertices[j].first;
            double dy = vertices[i].second - vertices[j].second;
            if (dx * dx + dy * dy < 1e-10) return false; 
        }
    }
    
    return true;
}

std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    fig.print_vertices(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& fig) {
    fig.read_from_stream(is);
    return is;
}

Figure::operator double() const {
    return this->area();
}