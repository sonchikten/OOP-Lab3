#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>
#include <cmath>

class Figure {
public:
    virtual ~Figure() = default;
    
    virtual double area() const = 0; // = 0 значит, что этот метод чистто виртуальный, то есть не имеет реализации здесь, должен быть реализован в наследниках
    virtual std::pair<double, double> geometric_center() const = 0;
    virtual void print_vertices(std::ostream& os) const = 0; //печатает координаты фигуры
    virtual void read_from_stream(std::istream& is) = 0;
    
    virtual bool operator==(const Figure& other) const = 0;

    operator double() const; //приведенеие к double вызывает area()
};

std::ostream& operator<<(std::ostream& os, const Figure& fig);
std::istream& operator>>(std::istream& is, Figure& fig);

#endif
