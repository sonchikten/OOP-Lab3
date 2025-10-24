#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"

class Octagon : public Figure {
private:
    std::vector<std::pair<double, double>> vertices;
    
public:
    Octagon();
    Octagon(const std::vector<std::pair<double, double>>& points);
    Octagon(const Octagon& other);
    Octagon(Octagon&& other) noexcept;
    
    Octagon& operator=(const Octagon& other);
    Octagon& operator=(Octagon&& other) noexcept;
    bool operator==(const Figure& other) const override;
    
    double area() const override;
    std::pair<double, double> geometric_center() const override;
    void print_vertices(std::ostream& os) const override;
    void read_from_stream(std::istream& is) override;
};

#endif