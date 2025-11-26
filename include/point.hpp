#pragma once

#include <iostream>
#include <concepts>
#include <cmath>
#include <type_traits>

namespace figures {

template<typename T>
concept Scalar = std::is_scalar_v<T>;

template<Scalar T>
class Point {
public:
    T x, y;
    
    Point(T x = 0, T y = 0);
    bool operator==(const Point& other) const;
    
    template<Scalar U>
    friend std::ostream& operator<<(std::ostream& os, const Point<U>& point);
    
    template<Scalar U>
    friend std::istream& operator>>(std::istream& is, Point<U>& point);
};

}

#include "point.ipp"