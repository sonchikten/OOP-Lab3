#include <gtest/gtest.h>
#include <sstream>
#include <cmath>
#include "../include/figure.h"
#include "../include/triangle.h"
#include "../include/hexagon.h" 
#include "../include/octagon.h"
#include "../include/array.h"

// Тест вычисления площади треугольника
TEST(TriangleTest, AreaCalculation) {
    Triangle triangle({{0, 0}, {4, 0}, {0, 3}});
    EXPECT_NEAR(triangle.area(), 6.0, 1e-6);
}

// Тест вычисления геометрического центра треугольника
TEST(TriangleTest, GeometricCenter) {
    Triangle triangle({{0, 0}, {4, 0}, {0, 3}});
    auto center = triangle.geometric_center();
    EXPECT_NEAR(center.first, 4.0/3.0, 1e-6);
    EXPECT_NEAR(center.second, 1.0, 1e-6);
}

// Тест вывода вершин треугольника
TEST(TriangleTest, PrintVertices) {
    Triangle triangle({{0, 0}, {4, 0}, {0, 3}});
    std::stringstream ss;
    triangle.print_vertices(ss);
    std::string expected = "Triangle vertices: (0, 0) (4, 0) (0, 3)";
    EXPECT_EQ(ss.str(), expected);
}

// Тест чтения треугольника из потока
TEST(TriangleTest, ReadFromStream) {
    Triangle triangle;
    std::stringstream ss("0 0 4 0 0 3");
    triangle.read_from_stream(ss);
    
    auto center = triangle.geometric_center();
    EXPECT_NEAR(center.first, 4.0/3.0, 1e-6);
    EXPECT_NEAR(center.second, 1.0, 1e-6);
}

// Тест приведения треугольника к double (площадь)
TEST(TriangleTest, OperatorDouble) {
    Triangle triangle({{0, 0}, {4, 0}, {0, 3}});
    double area = static_cast<double>(triangle);
    EXPECT_NEAR(area, 6.0, 1e-6);
}

// Тест оператора сравнения треугольников
TEST(TriangleTest, OperatorEquals) {
    Triangle triangle1({{0, 0}, {4, 0}, {0, 3}});
    Triangle triangle2({{0, 0}, {4, 0}, {0, 3}});
    Triangle triangle3({{0, 0}, {1, 0}, {0, 1}});
    
    EXPECT_TRUE(triangle1.operator==(triangle2));
    EXPECT_FALSE(triangle1.operator==(triangle3));
}

// Тест конструктора копирования треугольника
TEST(TriangleTest, CopyConstructor) {
    Triangle triangle1({{0, 0}, {4, 0}, {0, 3}});
    Triangle triangle2(triangle1);
    EXPECT_TRUE(triangle1.operator==(triangle2));
}

// Тест конструктора перемещения треугольника
TEST(TriangleTest, MoveConstructor) {
    Triangle triangle1({{0, 0}, {4, 0}, {0, 3}});
    Triangle triangle2(std::move(triangle1));
    EXPECT_NO_THROW(triangle2.area());
}

// Тест оператора присваивания копированием треугольника
TEST(TriangleTest, CopyAssignment) {
    Triangle triangle1({{0, 0}, {4, 0}, {0, 3}});
    Triangle triangle2;
    triangle2 = triangle1;
    EXPECT_TRUE(triangle1.operator==(triangle2));
}

// Тест оператора присваивания перемещением треугольника
TEST(TriangleTest, MoveAssignment) {
    Triangle triangle1({{0, 0}, {4, 0}, {0, 3}});
    Triangle triangle2;
    triangle2 = std::move(triangle1);
    EXPECT_NO_THROW(triangle2.area());
}

// Тест вычисления площади шестиугольника
TEST(HexagonTest, AreaCalculation) {
    Hexagon hexagon({
        {1, 0}, {0.5, 0.866}, {-0.5, 0.866}, 
        {-1, 0}, {-0.5, -0.866}, {0.5, -0.866}
    });
    double expected_area = 2.598076; // (3√3)/2 ≈ 2.598
    EXPECT_NEAR(hexagon.area(), expected_area, 1e-3);
}

// Тест вычисления геометрического центра шестиугольника
TEST(HexagonTest, GeometricCenter) {
    Hexagon hexagon({
        {0, 0}, {2, 0}, {3, 1}, {2, 2}, {0, 2}, {-1, 1}
    });
    auto center = hexagon.geometric_center();
    EXPECT_NEAR(center.first, 1.0, 1e-6);
    EXPECT_NEAR(center.second, 1.0, 1e-6);
}

// Тест вывода вершин шестиугольника
TEST(HexagonTest, PrintVertices) {
    Hexagon hexagon({
        {0, 0}, {2, 0}, {3, 1}, {2, 2}, {0, 2}, {-1, 1}
    });
    std::stringstream ss;
    hexagon.print_vertices(ss);
    std::string expected = "Hexagon vertices: (0, 0) (2, 0) (3, 1) (2, 2) (0, 2) (-1, 1)";
    EXPECT_EQ(ss.str(), expected);
}

// Тест чтения шестиугольника из потока
TEST(HexagonTest, ReadFromStream) {
    Hexagon hexagon;
    std::stringstream ss("0 0 2 0 3 1 2 2 0 2 -1 1");
    hexagon.read_from_stream(ss);
    
    auto center = hexagon.geometric_center();
    EXPECT_NEAR(center.first, 1.0, 1e-6);
    EXPECT_NEAR(center.second, 1.0, 1e-6);
}

// Тест приведения шестиугольника к double (площадь)
TEST(HexagonTest, OperatorDouble) {
    Hexagon hexagon({
        {0, 0}, {2, 0}, {3, 1}, {2, 2}, {0, 2}, {-1, 1}
    });
    double area = static_cast<double>(hexagon);
    EXPECT_NEAR(area, 6.0, 1e-6);
}

// Тест оператора сравнения шестиугольников
TEST(HexagonTest, OperatorEquals) {
    Hexagon hexagon1({
        {0, 0}, {2, 0}, {3, 1}, {2, 2}, {0, 2}, {-1, 1}
    });
    Hexagon hexagon2({
        {0, 0}, {2, 0}, {3, 1}, {2, 2}, {0, 2}, {-1, 1}
    });
    Hexagon hexagon3({
        {1, 0}, {0.5, 0.866}, {-0.5, 0.866}, {-1, 0}, {-0.5, -0.866}, {0.5, -0.866}
    });
    
    EXPECT_TRUE(hexagon1.operator==(hexagon2));
    EXPECT_FALSE(hexagon1.operator==(hexagon3));
}

// Тест вычисления площади восьмиугольника
TEST(OctagonTest, AreaCalculation) {
    Octagon octagon({
        {1, 0}, {0.707, 0.707}, {0, 1}, {-0.707, 0.707},
        {-1, 0}, {-0.707, -0.707}, {0, -1}, {0.707, -0.707}
    });
    double expected_area = 2.828427; // 2√2 ≈ 2.828
    EXPECT_NEAR(octagon.area(), expected_area, 1e-3);
}

// Тест вычисления геометрического центра восьмиугольника
TEST(OctagonTest, GeometricCenter) {
    Octagon octagon({
        {0, 0}, {2, 0}, {3, 1}, {3, 3}, {2, 4}, {0, 4}, {-1, 3}, {-1, 1}
    });
    auto center = octagon.geometric_center();
    EXPECT_NEAR(center.first, 1.0, 1e-6);
    EXPECT_NEAR(center.second, 2.0, 1e-6);
}

// Тест вывода вершин восьмиугольника
TEST(OctagonTest, PrintVertices) {
    Octagon octagon({
        {0, 0}, {2, 0}, {3, 1}, {3, 3}, {2, 4}, {0, 4}, {-1, 3}, {-1, 1}
    });
    std::stringstream ss;
    octagon.print_vertices(ss);
    std::string expected = "Octagon vertices: (0, 0) (2, 0) (3, 1) (3, 3) (2, 4) (0, 4) (-1, 3) (-1, 1)";
    EXPECT_EQ(ss.str(), expected);
}

// Тест чтения восьмиугольника из потока
TEST(OctagonTest, ReadFromStream) {
    Octagon octagon;
    std::stringstream ss("0 0 2 0 3 1 3 3 2 4 0 4 -1 3 -1 1");
    octagon.read_from_stream(ss);
    
    auto center = octagon.geometric_center();
    EXPECT_NEAR(center.first, 1.0, 1e-6);
    EXPECT_NEAR(center.second, 2.0, 1e-6);
}

// Тест приведения восьмиугольника к double (площадь)
TEST(OctagonTest, OperatorDouble) {
    Octagon octagon({
        {0, 0}, {2, 0}, {3, 1}, {3, 3}, {2, 4}, {0, 4}, {-1, 3}, {-1, 1}
    });
    double area = static_cast<double>(octagon);
    EXPECT_NEAR(area, 14.0, 1e-6); // Реальная площадь = 14
}

// Тест добавления и удаления фигур из массива
TEST(FigureArrayTest, AddAndRemoveFigures) {
    FigureArray array;
    
    auto triangle = new Triangle(std::vector<std::pair<double, double>>{{0, 0}, {1, 0}, {0, 1}});
    auto hexagon = new Hexagon(std::vector<std::pair<double, double>>{
        {0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}, {-1, 1}
    });
    
    array.add_figure(triangle);
    array.add_figure(hexagon);
    
    EXPECT_EQ(array.size(), 2);
    
    array.remove_figure(0);
    EXPECT_EQ(array.size(), 1);
    
    array.remove_figure(0);
    EXPECT_EQ(array.size(), 0);
}

// Тест вычисления общей площади фигур в массиве
TEST(FigureArrayTest, TotalArea) {
    FigureArray array;
    
    auto triangle = new Triangle(std::vector<std::pair<double, double>>{{0, 0}, {2, 0}, {0, 2}});
    auto hexagon = new Hexagon(std::vector<std::pair<double, double>>{
        {0, 0}, {2, 0}, {3, 1}, {2, 2}, {0, 2}, {-1, 1}
    });
    
    array.add_figure(triangle);
    array.add_figure(hexagon);
    
    double total_area = array.total_area();
    EXPECT_NEAR(total_area, 8.0, 1e-6); // 2 + 6 = 8
    
    array.remove_figure(0);
    array.remove_figure(0);
}

// Тест оператора доступа к фигурам в массиве
TEST(FigureArrayTest, AccessOperator) {
    FigureArray array;
    
    auto triangle = new Triangle(std::vector<std::pair<double, double>>{{0, 0}, {1, 0}, {0, 1}});
    array.add_figure(triangle);
    
    auto retrieved = array[0];
    EXPECT_NEAR(retrieved->area(), 0.5, 1e-6);
    
    array.remove_figure(0);
}

// Тест полиморфизма - работа с указателями на базовый класс
TEST(PolymorphismTest, FigurePointerOperations) {
    Figure* triangle = new Triangle(std::vector<std::pair<double, double>>{{0, 0}, {3, 0}, {0, 4}});
    Figure* hexagon = new Hexagon(std::vector<std::pair<double, double>>{
        {0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}, {-1, 1}
    });
    
    EXPECT_NEAR(triangle->area(), 6.0, 1e-6);
    EXPECT_NEAR(hexagon->area(), 4.0, 1e-6);
    
    auto triangle_center = triangle->geometric_center();
    auto hexagon_center = hexagon->geometric_center();
    
    EXPECT_NEAR(triangle_center.first, 1.0, 1e-6);
    EXPECT_NEAR(triangle_center.second, 4.0/3.0, 1e-6);
    EXPECT_NEAR(hexagon_center.first, 0.5, 1e-6);
    EXPECT_NEAR(hexagon_center.second, 1.0, 1e-6);
    
    delete triangle;
    delete hexagon;
}

// Тест операторов ввода/вывода для треугольника
TEST(IOStreamTest, TriangleOperatorIO) {
    Triangle triangle;
    std::stringstream input("0 0 4 0 0 3");
    std::stringstream output;
    
    input >> triangle;
    output << triangle;
    
    std::string expected = "Triangle vertices: (0, 0) (4, 0) (0, 3)";
    EXPECT_EQ(output.str(), expected);
}

// Тест операторов ввода/вывода для шестиугольника
TEST(IOStreamTest, HexagonOperatorIO) {
    Hexagon hexagon;
    std::stringstream input("0 0 2 0 3 1 2 2 0 2 -1 1");
    std::stringstream output;
    
    input >> hexagon;
    output << hexagon;
    
    std::string expected = "Hexagon vertices: (0, 0) (2, 0) (3, 1) (2, 2) (0, 2) (-1, 1)";
    EXPECT_EQ(output.str(), expected);
}

// Тест обработки невалидного ввода
TEST(ExceptionTest, InvalidInput) {
    Triangle triangle;
    std::stringstream invalid_input("1 2 abc");
    
    EXPECT_THROW(triangle.read_from_stream(invalid_input), std::runtime_error);
}

// Тест обработки невалидного индекса в массиве
TEST(ExceptionTest, InvalidIndex) {
    FigureArray array;
    EXPECT_NO_THROW(array.remove_figure(0));
    
    auto triangle = new Triangle();
    array.add_figure(triangle);
    EXPECT_THROW(array[1], std::out_of_range);
    
    array.remove_figure(0);
}

// Тест работы с разными типами фигур в одном массиве
TEST(MixedFiguresTest, DifferentTypesInArray) {
    FigureArray array;
    
    array.add_figure(new Triangle(std::vector<std::pair<double, double>>{{0, 0}, {2, 0}, {0, 2}}));
    array.add_figure(new Hexagon(std::vector<std::pair<double, double>>{
        {0, 0}, {2, 0}, {3, 1}, {2, 2}, {0, 2}, {-1, 1}
    }));
    array.add_figure(new Octagon(std::vector<std::pair<double, double>>{
        {0, 0}, {2, 0}, {3, 1}, {3, 3}, {2, 4}, {0, 4}, {-1, 3}, {-1, 1}
    }));
    
    EXPECT_EQ(array.size(), 3);
    EXPECT_NEAR(array.total_area(), 22.0, 1e-6); // 2 + 6 + 14 = 22
    
    while (array.size() > 0) {
        array.remove_figure(0);
    }
}

// Тест на невалидный треугольник (коллинеарные точки)
TEST(ValidationTest, InvalidTriangle) {
    EXPECT_THROW(Triangle({{0, 0}, {1, 1}, {2, 2}}), std::invalid_argument);
    
    EXPECT_THROW(Triangle({{0, 0}, {0, 0}, {1, 1}}), std::invalid_argument);
}

// Тест на невалидный шестиугольник
TEST(ValidationTest, InvalidHexagon) {
    EXPECT_THROW(Hexagon({
        {0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}
    }), std::invalid_argument);
}

// Тест на невалидный восьмиугольник
TEST(ValidationTest, InvalidOctagon) {
    EXPECT_THROW(Octagon({
        {0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}
    }), std::invalid_argument);
}
