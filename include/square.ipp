#include <cmath>

#include "square.hpp"

namespace figures {

template<FloatingPointScalar T>
Square<T>::Square() 
    : vertices{
        std::make_unique<Point<T>>(-1, -1),
        std::make_unique<Point<T>>(1, -1),
        std::make_unique<Point<T>>(1, 1),
        std::make_unique<Point<T>>(-1, 1)
    } {}

template<FloatingPointScalar T>
Square<T>::Square(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4)
    : vertices{
        std::make_unique<Point<T>>(p1),
        std::make_unique<Point<T>>(p2),
        std::make_unique<Point<T>>(p3),
        std::make_unique<Point<T>>(p4)
    } {}

template<FloatingPointScalar T>
Square<T>::Square(const Square& other) {
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        vertices[i] = std::make_unique<Point<T>>(*other.vertices[i]);
    }
}

template<FloatingPointScalar T>
Square<T>::Square(Square&& other) noexcept {
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        vertices[i] = std::move(other.vertices[i]);
    }
}

template<FloatingPointScalar T>
Square<T>& Square<T>::operator=(const Square& other) {
    if (this != &other) {
        for (int i = 0; i < VERTICES_COUNT; ++i) {
            vertices[i] = std::make_unique<Point<T>>(*other.vertices[i]);
        }
    }
    return *this;
}

template<FloatingPointScalar T>
Square<T>& Square<T>::operator=(Square&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < VERTICES_COUNT; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}

template<FloatingPointScalar T>
bool Square<T>::operator==(const Figure<T>& other) const {
    const Square* square = dynamic_cast<const Square*>(&other);
    if (!square) return false;
    
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        if (!(*vertices[i] == *square->vertices[i])) {
            return false;
        }
    }
    return true;
}

template<FloatingPointScalar T>
Point<T> Square<T>::geometricCenter() const {
    T centerX = 0, centerY = 0;
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        centerX += vertices[i]->x;
        centerY += vertices[i]->y;
    }
    return Point<T>(centerX / VERTICES_COUNT, centerY / VERTICES_COUNT);
}

template<FloatingPointScalar T>
double Square<T>::area() const {
    double side = std::sqrt(std::pow(vertices[1]->x - vertices[0]->x, 2) + 
                           std::pow(vertices[1]->y - vertices[0]->y, 2));
    return side * side;
}

template<FloatingPointScalar T>
void Square<T>::printVertices(std::ostream& os) const {
    os << "square: ";
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        os << *vertices[i];
        if (i < 3) os << " ";
    }
}

template<FloatingPointScalar T>
void Square<T>::readFromStream(std::istream& is) {
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        T x, y;
        is >> x >> y;
        vertices[i] = std::make_unique<Point<T>>(x, y);
    }
}

template<FloatingPointScalar T>
std::shared_ptr<Figure<T>> Square<T>::clone() const {
    return std::make_shared<Square<T>>(*this);
}

}