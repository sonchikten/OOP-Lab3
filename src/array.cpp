#include "../include/array.h"
#include <iostream>

void FigureArray::add_figure(std::shared_ptr<Figure> fig) {
    figures.push_back(fig);
}

void FigureArray::remove_figure(size_t index) {
    if (index < figures.size()) {
        figures.erase(figures.begin() + index);
    }
}

void FigureArray::print_all_info() const {
    for (size_t i = 0; i < figures.size(); i++) {
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
    for (const auto& fig : figures) {
        total += fig->area();
    }
    return total;
}

size_t FigureArray::size() const {
    return figures.size();
}

std::shared_ptr<Figure> FigureArray::operator[](size_t index) const {
    if (index >= figures.size()) {
        throw std::out_of_range("Index out of range");
    }
    return figures[index];
}
