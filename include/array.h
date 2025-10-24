#ifndef ARRAY_H
#define ARRAY_H

#include "figure.h"

class FigureArray {
private:
    Figure** figures; 
    size_t _size;
    size_t _capacity;
    
public:
    FigureArray();
    ~FigureArray();
    void add_figure(Figure* fig); //изменили на обычный указатель
    void remove_figure(size_t index);
    void print_all_info() const;
    double total_area() const; //сумирует площади всех фигур в массиве
    size_t size() const; //количество фигур в массиве
    Figure* operator[](size_t index) const; //оператор доступа к фигуре по индексу
    
private:
    void resize(); //увеличивает вместимость массива при необходимости
};

#endif
