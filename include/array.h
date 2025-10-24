#ifndef ARRAY_H
#define ARRAY_H

#include "figure.h"
#include <vector>
#include <memory>

class FigureArray {
private:
    std::vector<std::shared_ptr<Figure>> figures;
    
public:
    void add_figure(std::shared_ptr<Figure> fig);
    void remove_figure(size_t index);
    void print_all_info() const;
    double total_area() const; //сумирует площади всех фигур в массиве
    size_t size() const; //количество фигур в массиве
    std::shared_ptr<Figure> operator[](size_t index) const; //оператор доступа к фигуре по индексу
};

#endif
