#pragma once

#include "figure.hpp"

namespace figures {

template<FloatingPointScalar T>
class Trapezoid : public Figure<T> {
private:
    static const int VERTICES_COUNT = 4;
    Point<T>* vertices[VERTICES_COUNT];

public:
    Trapezoid();
    Trapezoid(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4);
    Trapezoid(const Trapezoid& other);
    Trapezoid(Trapezoid&& other) noexcept;
    ~Trapezoid();

    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other) noexcept;

    bool operator==(const Figure<T>& other) const override;
    
    Point<T> geometricCenter() const override;
    double area() const override;

    void printVertices(std::ostream& os) const override;
    void readFromStream(std::istream& is) override;
    
    Figure<T>* clone() const override;
};

}

#include "trapezoid.ipp"