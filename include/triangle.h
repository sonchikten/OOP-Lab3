#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle : public Figure {
private:
    std::vector<std::pair<double, double>> vertices;
    
public:
    Triangle();
    Triangle(const std::vector<std::pair<double, double>>& points);
    Triangle(const Triangle& other);
    Triangle(Triangle&& other) noexcept;
    
    Triangle& operator=(const Triangle& other);
    Triangle& operator=(Triangle&& other) noexcept;
    bool operator==(const Figure& other) const override; //сравнивает треугольник с любой другой фигурой
    
    double area() const override;
    std::pair<double, double> geometric_center() const override;
    void print_vertices(std::ostream& os) const override;
    void read_from_stream(std::istream& is) override;
};

#endif
