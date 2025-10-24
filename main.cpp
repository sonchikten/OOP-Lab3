#include "include/figure.h"
#include "include/hexagon.h"
#include "include/octagon.h"
#include "include/triangle.h"
#include "include/array.h"

#include <iostream>
#include <vector>
#include <limits>

void print_menu() {
    std::cout << "\n=== Figure Management System ===" << std::endl;
    std::cout << "1. Add Hexagon" << std::endl;
    std::cout << "2. Add Octagon" << std::endl;
    std::cout << "3. Add Triangle" << std::endl;
    std::cout << "4. Remove figure by index" << std::endl;
    std::cout << "5. Print all figures info" << std::endl;
    std::cout << "6. Calculate total area" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Choose option: ";
}

int main() {
    FigureArray figure_array;
    int choice;
    
    while (true) {
        print_menu();
        std::cin >> choice;
        
        try {
            switch (choice) {
                case 1: {
                    std::cout << "Enter 6 vertices (x y) for Hexagon:" << std::endl;
                    Hexagon* hexagon = new Hexagon();
                    try {
                        std::cin >> *hexagon;
                        figure_array.add_figure(hexagon);
                        std::cout << "Hexagon added successfully!" << std::endl;
                    } catch (const std::exception& e) {
                        delete hexagon;
                        std::cout << "Error creating Hexagon: " << e.what() << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    break;
                }
                case 2: {
                    std::cout << "Enter 8 vertices (x y) for Octagon:" << std::endl;
                    Octagon* octagon = new Octagon();
                    try {
                        std::cin >> *octagon;
                        figure_array.add_figure(octagon);
                        std::cout << "Octagon added successfully!" << std::endl;
                    } catch (const std::exception& e) {
                        delete octagon;
                        std::cout << "Error creating Octagon: " << e.what() << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    break;
                }
                case 3: {
                    std::cout << "Enter 3 vertices (x y) for Triangle:" << std::endl;
                    Triangle* triangle = new Triangle();
                    try {
                        std::cin >> *triangle;
                        figure_array.add_figure(triangle);
                        std::cout << "Triangle added successfully!" << std::endl;
                    } catch (const std::exception& e) {
                        delete triangle;
                        std::cout << "Error creating Triangle: " << e.what() << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    break;
                }
                case 4: {
                    std::cout << "Enter index to remove: ";
                    size_t index;
                    std::cin >> index;
                    figure_array.remove_figure(index);
                    std::cout << "Figure removed successfully!" << std::endl;
                    break;
                }
                case 5: {
                    figure_array.print_all_info();
                    break;
                }
                case 6: {
                    double total = figure_array.total_area();
                    std::cout << "Total area of all figures: " << total << std::endl;
                    break;
                }
                case 7: {
                    std::cout << "Goodbye!" << std::endl;
                    return 0;
                }
                default: {
                    std::cout << "Invalid option! Please try again." << std::endl;
                    break;
                }
            }
        } catch (const std::exception& e) {
            std::cout << "Unexpected error: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    return 0;
}
