#include "../include/array.h"
#include <iostream>

FigureArray::FigureArray() : figures(nullptr), _size(0), _capacity(0) {}

FigureArray::~FigureArray() {
    for (size_t i = 0; i < _size; i++) {
        delete figures[i]; //освобождаем память для каждого указателя
    }
    delete[] figures; //освобождаем память массива
}

void FigureArray::resize() {
    size_t new_capacity = _capacity == 0 ? 1 : _capacity * 2;
    Figure** new_figures = new Figure*[new_capacity];
    
    for (size_t i = 0; i < _size; i++) {
        new_figures[i] = figures[i];
    }
    
    delete[] figures; 
    figures = new_figures;
    _capacity = new_capacity;
}

void FigureArray::add_figure(Figure* fig) {
    if (_size >= _capacity) {
        resize();
    }
    figures[_size++] = fig;
}

void FigureArray::remove_figure(size_t index) {
    if (index < _size) {
        delete figures[index];
        
        for (size_t i = index; i < _size - 1; i++) {
            figures[i] = figures[i + 1];
        }
        _size--;
    }
}

void FigureArray::print_all_info() const {
    for (size_t i = 0; i < _size; i++) {
        std::cout << "Figure " << i << ": ";
        std::cout << *figures[i] << std::endl;
        
        auto center = figures[i]->geometric_center();
        double area = figures[i]->area();
        
        std::cout << "Geometric center: (" << center.first << ", " << center.second << ")" << std::endl;
        std::cout << "Area: " << area << std::endl;
        std::cout << "-------------------" << std::endl;
    }
}

double FigureArray::total_area() const {
    double total = 0.0;
    for (size_t i = 0; i < _size; i++) {
        total += figures[i]->area();
    }
    return total;
}

size_t FigureArray::size() const {
    return _size;
}

Figure* FigureArray::operator[](size_t index) const {
    if (index >= _size) {
        throw std::out_of_range("Index out of range");
    }
    return figures[index];
}
