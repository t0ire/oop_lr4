#include <iostream>
#include "square.hpp"
#include "rectangle.hpp"
#include "trapezoid.hpp"
#include "figure_array.hpp"

using namespace figures;

int main() {
    FigureArray<double> figures;
    
    auto square = new Square<double>();
    auto rectangle = new Rectangle<double>();
    auto trapezoid = new Trapezoid<double>();
    
    figures.addFigure(square);
    figures.addFigure(rectangle);
    figures.addFigure(trapezoid);
    
    std::cout << "All figures:" << std::endl;
    std::cout << figures << std::endl;
    
    std::cout << "Total area: " << figures.totalArea() << std::endl;
    
    return 0;
}