#ifndef ARRAY_H
#define ARRAY_H

#include "figure.h"
#include <vector>

class FigureArray {
private:
    std::vector<Figure*> figures;
    
public:
    ~FigureArray();
    void add_figure(Figure* fig); //изменили на обычный указатель
    void remove_figure(size_t index);
    void print_all_info() const;
    double total_area() const; //сумирует площади всех фигур в массиве
    size_t size() const; //количество фигур в массиве
    Figure* operator[](size_t index) const; //оператор доступа к фигуре по индексу
};

#endif
