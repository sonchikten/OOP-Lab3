#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"

class Hexagon : public Figure {
private:
    std::vector<std::pair<double, double>> vertices;
    
public:
    Hexagon();
    Hexagon(const std::vector<std::pair<double, double>>& points);
    Hexagon(const Hexagon& other);
    Hexagon(Hexagon&& other) noexcept;
    
    Hexagon& operator=(const Hexagon& other);
    Hexagon& operator=(Hexagon&& other) noexcept;
    bool operator==(const Figure& other) const override;
    
    double area() const override;
    std::pair<double, double> geometric_center() const override;
    void print_vertices(std::ostream& os) const override;
    void read_from_stream(std::istream& is) override;
};

#endif
