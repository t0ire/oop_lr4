#pragma once

#include <memory>

#include "array.hpp"
#include "figure.hpp"

namespace figures {

template<FloatingPointScalar T>
class FigureArray {
private:
    Array<std::shared_ptr<Figure<T>>> figures;
    size_t count;

public:
    FigureArray();
    FigureArray(const FigureArray& other);
    FigureArray(FigureArray&& other) noexcept;
    ~FigureArray();

    FigureArray& operator=(const FigureArray& other);
    FigureArray& operator=(FigureArray&& other) noexcept;

    void addFigure(std::shared_ptr<Figure<T>> figure);
    void removeFigure(size_t index);
    void printAllFigures(std::ostream& os) const;
    double totalArea() const;
    
    std::shared_ptr<Figure<T>> operator[](size_t index);
    const std::shared_ptr<Figure<T>> operator[](size_t index) const;
    
    size_t size() const;
};

template<FloatingPointScalar T>
std::ostream& operator<<(std::ostream& os, const FigureArray<T>& array);

}

#include "figure_array.ipp"