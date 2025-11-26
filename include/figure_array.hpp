#pragma once

#include <iostream>
#include <stdexcept>

#include "figure.hpp"
#include "array.hpp"  

namespace figures {

template<FloatingPointScalar T>
class FigureArray {
private:
    Array<Figure<T>*> figures;  
    size_t count;

public:
    FigureArray();
    FigureArray(const FigureArray& other);
    FigureArray(FigureArray&& other) noexcept;
    ~FigureArray();

    FigureArray& operator=(const FigureArray& other);
    FigureArray& operator=(FigureArray&& other) noexcept;

    void addFigure(Figure<T>* figure);
    void removeFigure(size_t index);
    void printAllFigures(std::ostream& os) const;
    double totalArea() const;
    
    Figure<T>* operator[](size_t index);
    const Figure<T>* operator[](size_t index) const;
    
    size_t size() const;
};

template<FloatingPointScalar T>
std::ostream& operator<<(std::ostream& os, const FigureArray<T>& array);

}

#include "figure_array.ipp"