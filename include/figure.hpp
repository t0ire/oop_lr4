#pragma once

#include <iostream>

#include "point.hpp"

namespace figures {

template<typename T>
concept FloatingPointScalar = Scalar<T> && std::floating_point<T>;

template<FloatingPointScalar T>
class Figure {
public:
    virtual ~Figure() = default;
    
    virtual Point<T> geometricCenter() const = 0;
    virtual double area() const = 0;
    virtual void printVertices(std::ostream& os) const = 0;
    virtual void readFromStream(std::istream& is) = 0;
    
    virtual Figure<T>* clone() const = 0;
    virtual bool operator==(const Figure& other) const = 0;
    
    operator double() const;
};

template<FloatingPointScalar T>
std::ostream& operator<<(std::ostream& os, const Figure<T>& figure);

template<FloatingPointScalar T>
std::istream& operator>>(std::istream& is, Figure<T>& figure);

}

#include "figure.ipp"