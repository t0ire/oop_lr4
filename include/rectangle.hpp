#pragma once

#include <memory> 

#include "figure.hpp"

namespace figures {

template<FloatingPointScalar T>
class Rectangle : public Figure<T> {
private:
    static const int VERTICES_COUNT = 4;
    std::unique_ptr<Point<T>> vertices[VERTICES_COUNT];

public:
    Rectangle();
    Rectangle(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4);
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;

    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;

    bool operator==(const Figure<T>& other) const override;
    
    Point<T> geometricCenter() const override;
    double area() const override;

    void printVertices(std::ostream& os) const override;
    void readFromStream(std::istream& is) override;
    
    std::shared_ptr<Figure<T>> clone() const override;
};

}

#include "rectangle.ipp"