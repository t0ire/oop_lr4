#include <iostream>
#include "square.hpp"
#include "rectangle.hpp"
#include "trapezoid.hpp"
#include "figure_array.hpp"

using namespace figures;

int main() {
    FigureArray<double> figures;
    
    // Добавляем различные фигуры
    auto square = std::make_shared<Square<double>>();
    auto rectangle = std::make_shared<Rectangle<double>>();
    auto trapezoid = std::make_shared<Trapezoid<double>>();
    
    figures.addFigure(square);
    figures.addFigure(rectangle);
    figures.addFigure(trapezoid);
    
    // Выводим информацию о всех фигурах
    std::cout << "All figures:" << std::endl;
    std::cout << figures << std::endl;
    
    // Выводим общую площадь
    std::cout << "Total area: " << figures.totalArea() << std::endl;
    
    return 0;
}