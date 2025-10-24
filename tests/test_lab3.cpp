#include <gtest/gtest.h>
#include <sstream>
#include <cmath>
#include <memory>
#include "../include/figure.h"
#include "../include/triangle.h"
#include "../include/hexagon.h" 
#include "../include/octagon.h"
#include "../include/array.h"

// Тесты для Triangle
TEST(TriangleTest, AreaCalculation) {
    Triangle triangle({{0, 0}, {4, 0}, {0, 3}});
    EXPECT_NEAR(triangle.area(), 6.0, 1e-6);
}

TEST(TriangleTest, GeometricCenter) {
    Triangle triangle({{0, 0}, {4, 0}, {0, 3}});
    auto center = triangle.geometric_center();
    EXPECT_NEAR(center.first, 4.0/3.0, 1e-6);
    EXPECT_NEAR(center.second, 1.0, 1e-6);
}

TEST(TriangleTest, PrintVertices) {
    Triangle triangle({{1, 2}, {3, 4}, {5, 6}});
    std::stringstream ss;
    triangle.print_vertices(ss);
    std::string expected = "Triangle vertices: (1, 2) (3, 4) (5, 6)";
    EXPECT_EQ(ss.str(), expected);
}

TEST(TriangleTest, ReadFromStream) {
    Triangle triangle;
    std::stringstream ss("1 2 3 4 5 6");
    triangle.read_from_stream(ss);
    
    auto center = triangle.geometric_center();
    EXPECT_NEAR(center.first, 3.0, 1e-6);
    EXPECT_NEAR(center.second, 4.0, 1e-6);
}

TEST(TriangleTest, OperatorDouble) {
    Triangle triangle({{0, 0}, {4, 0}, {0, 3}});
    double area = static_cast<double>(triangle);
    EXPECT_NEAR(area, 6.0, 1e-6);
}

TEST(TriangleTest, OperatorEquals) {
    Triangle triangle1({{1, 2}, {3, 4}, {5, 6}});
    Triangle triangle2({{1, 2}, {3, 4}, {5, 6}});
    Triangle triangle3({{0, 0}, {1, 0}, {0, 1}});
    
    EXPECT_TRUE(triangle1.operator==(triangle2));
    EXPECT_FALSE(triangle1.operator==(triangle3));
}

TEST(TriangleTest, CopyConstructor) {
    Triangle triangle1({{1, 2}, {3, 4}, {5, 6}});
    Triangle triangle2(triangle1);
    EXPECT_TRUE(triangle1.operator==(triangle2));
}

TEST(TriangleTest, MoveConstructor) {
    Triangle triangle1({{1, 2}, {3, 4}, {5, 6}});
    Triangle triangle2(std::move(triangle1));
    EXPECT_NEAR(triangle2.area(), 0.0, 1e-6); // площадь вырожденного треугольника
}

TEST(TriangleTest, CopyAssignment) {
    Triangle triangle1({{1, 2}, {3, 4}, {5, 6}});
    Triangle triangle2;
    triangle2 = triangle1;
    EXPECT_TRUE(triangle1.operator==(triangle2));
}

TEST(TriangleTest, MoveAssignment) {
    Triangle triangle1({{1, 2}, {3, 4}, {5, 6}});
    Triangle triangle2;
    triangle2 = std::move(triangle1);
    EXPECT_NEAR(triangle2.area(), 0.0, 1e-6);
}

// Тесты для Hexagon
TEST(HexagonTest, AreaCalculation) {
    // Правильный шестиугольник с радиусом 1
    Hexagon hexagon({
        {1, 0}, {0.5, 0.866}, {-0.5, 0.866}, 
        {-1, 0}, {-0.5, -0.866}, {0.5, -0.866}
    });
    double expected_area = 2.598076; // (3√3)/2 ≈ 2.598
    EXPECT_NEAR(hexagon.area(), expected_area, 1e-3);
}

TEST(HexagonTest, GeometricCenter) {
    Hexagon hexagon({
        {1, 1}, {2, 1}, {3, 2}, {2, 3}, {1, 3}, {0, 2}
    });
    auto center = hexagon.geometric_center();
    EXPECT_NEAR(center.first, 1.5, 1e-6);
    EXPECT_NEAR(center.second, 2.0, 1e-6);
}

TEST(HexagonTest, PrintVertices) {
    Hexagon hexagon({
        {1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}, {11, 12}
    });
    std::stringstream ss;
    hexagon.print_vertices(ss);
    std::string expected = "Hexagon vertices: (1, 2) (3, 4) (5, 6) (7, 8) (9, 10) (11, 12)";
    EXPECT_EQ(ss.str(), expected);
}

TEST(HexagonTest, ReadFromStream) {
    Hexagon hexagon;
    std::stringstream ss("1 2 3 4 5 6 7 8 9 10 11 12");
    hexagon.read_from_stream(ss);
    
    auto center = hexagon.geometric_center();
    EXPECT_NEAR(center.first, 6.0, 1e-6);
    EXPECT_NEAR(center.second, 7.0, 1e-6);
}

TEST(HexagonTest, OperatorDouble) {
    Hexagon hexagon({
        {1, 1}, {2, 1}, {3, 2}, {2, 3}, {1, 3}, {0, 2}
    });
    double area = static_cast<double>(hexagon);
    EXPECT_NEAR(area, 4.0, 1e-6);
}

TEST(HexagonTest, OperatorEquals) {
    Hexagon hexagon1({
        {1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}, {11, 12}
    });
    Hexagon hexagon2({
        {1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}, {11, 12}
    });
    Hexagon hexagon3({
        {0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}, {-1, 1}
    });
    
    EXPECT_TRUE(hexagon1.operator==(hexagon2));
    EXPECT_FALSE(hexagon1.operator==(hexagon3));
}

// Тесты для Octagon
TEST(OctagonTest, AreaCalculation) {
    // Правильный восьмиугольник
    Octagon octagon({
        {1, 0}, {0.707, 0.707}, {0, 1}, {-0.707, 0.707},
        {-1, 0}, {-0.707, -0.707}, {0, -1}, {0.707, -0.707}
    });
    double expected_area = 2.828427; // 2√2 ≈ 2.828
    EXPECT_NEAR(octagon.area(), expected_area, 1e-3);
}

TEST(OctagonTest, GeometricCenter) {
    Octagon octagon({
        {0, 0}, {1, 0}, {2, 1}, {2, 2}, {1, 3}, {0, 3}, {-1, 2}, {-1, 1}
    });
    auto center = octagon.geometric_center();
    EXPECT_NEAR(center.first, 0.5, 1e-6);
    EXPECT_NEAR(center.second, 1.5, 1e-6);
}

TEST(OctagonTest, PrintVertices) {
    Octagon octagon({
        {1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}, {11, 12}, {13, 14}, {15, 16}
    });
    std::stringstream ss;
    octagon.print_vertices(ss);
    std::string expected = "Octagon vertices: (1, 2) (3, 4) (5, 6) (7, 8) (9, 10) (11, 12) (13, 14) (15, 16)";
    EXPECT_EQ(ss.str(), expected);
}

TEST(OctagonTest, ReadFromStream) {
    Octagon octagon;
    std::stringstream ss("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16");
    octagon.read_from_stream(ss);
    
    auto center = octagon.geometric_center();
    EXPECT_NEAR(center.first, 8.0, 1e-6);
    EXPECT_NEAR(center.second, 9.0, 1e-6);
}

TEST(OctagonTest, OperatorDouble) {
    Octagon octagon({
        {0, 0}, {2, 0}, {3, 1}, {3, 3}, {2, 4}, {0, 4}, {-1, 3}, {-1, 1}
    });
    double area = static_cast<double>(octagon);
    EXPECT_NEAR(area, 14.0, 1e-6); // Реальная площадь = 14
}

// Тесты для FigureArray
TEST(FigureArrayTest, AddAndRemoveFigures) {
    FigureArray array;
    
    auto triangle = std::make_shared<Triangle>(std::vector<std::pair<double, double>>{{0, 0}, {1, 0}, {0, 1}});
    auto hexagon = std::make_shared<Hexagon>(std::vector<std::pair<double, double>>{
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

TEST(FigureArrayTest, TotalArea) {
    FigureArray array;
    
    auto triangle = std::make_shared<Triangle>(std::vector<std::pair<double, double>>{{0, 0}, {2, 0}, {0, 2}});
    auto hexagon = std::make_shared<Hexagon>(std::vector<std::pair<double, double>>{
        {0, 0}, {2, 0}, {3, 1}, {2, 2}, {0, 2}, {-1, 1}
    });
    
    array.add_figure(triangle);
    array.add_figure(hexagon);
    
    double total_area = array.total_area();
    EXPECT_NEAR(total_area, 8.0, 1e-6); // 2 + 6 = 8
}

TEST(FigureArrayTest, AccessOperator) {
    FigureArray array;
    
    auto triangle = std::make_shared<Triangle>(std::vector<std::pair<double, double>>{{0, 0}, {1, 0}, {0, 1}});
    array.add_figure(triangle);
    
    auto retrieved = array[0];
    EXPECT_NEAR(retrieved->area(), 0.5, 1e-6);
}

TEST(FigureArrayTest, PrintAllInfo) {
    FigureArray array;
    
    auto triangle = std::make_shared<Triangle>(std::vector<std::pair<double, double>>{{0, 0}, {1, 0}, {0, 1}});
    array.add_figure(triangle);
    
    // Тестируем что не падает с исключением
    EXPECT_NO_THROW(array.print_all_info());
}

// Тесты полиморфизма
TEST(PolymorphismTest, FigurePointerOperations) {
    std::shared_ptr<Figure> triangle = std::make_shared<Triangle>(std::vector<std::pair<double, double>>{{0, 0}, {3, 0}, {0, 4}});
    std::shared_ptr<Figure> hexagon = std::make_shared<Hexagon>(std::vector<std::pair<double, double>>{
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
}

// Тесты операторов ввода/вывода
TEST(IOStreamTest, TriangleOperatorIO) {
    Triangle triangle;
    std::stringstream input("1.5 2.5 3.5 4.5 5.5 6.5");
    std::stringstream output;
    
    input >> triangle;
    output << triangle;
    
    std::string expected = "Triangle vertices: (1.5, 2.5) (3.5, 4.5) (5.5, 6.5)";
    EXPECT_EQ(output.str(), expected);
}

TEST(IOStreamTest, HexagonOperatorIO) {
    Hexagon hexagon;
    std::stringstream input("1 2 3 4 5 6 7 8 9 10 11 12");
    std::stringstream output;
    
    input >> hexagon;
    output << hexagon;
    
    std::string expected = "Hexagon vertices: (1, 2) (3, 4) (5, 6) (7, 8) (9, 10) (11, 12)";
    EXPECT_EQ(output.str(), expected);
}

// Тесты исключений
TEST(ExceptionTest, InvalidInput) {
    Triangle triangle;
    std::stringstream invalid_input("1 2 abc");
    
    EXPECT_THROW(triangle.read_from_stream(invalid_input), std::runtime_error);
}

TEST(ExceptionTest, InvalidIndex) {
    FigureArray array;
    EXPECT_NO_THROW(array.remove_figure(0)); // Не должно падать при удалении несуществующего индекса
    
    auto triangle = std::make_shared<Triangle>();
    array.add_figure(triangle);
    EXPECT_THROW(array[1], std::out_of_range); // Должно падать при обращении к несуществующему индексу
}

// Тест на разные типы фигур в одном массиве
TEST(MixedFiguresTest, DifferentTypesInArray) {
    FigureArray array;
    
    array.add_figure(std::make_shared<Triangle>(std::vector<std::pair<double, double>>{{0, 0}, {2, 0}, {0, 2}}));
    array.add_figure(std::make_shared<Hexagon>(std::vector<std::pair<double, double>>{
        {0, 0}, {2, 0}, {3, 1}, {2, 2}, {0, 2}, {-1, 1}
    }));
    array.add_figure(std::make_shared<Octagon>(std::vector<std::pair<double, double>>{
        {0, 0}, {2, 0}, {3, 1}, {3, 3}, {2, 4}, {0, 4}, {-1, 3}, {-1, 1}
    }));
    
    EXPECT_EQ(array.size(), 3);
    EXPECT_NEAR(array.total_area(), 22.0, 1e-6); // 2 + 6 + 14 = 22
}