#include <cmath>
#include <cstring>

namespace figures {

template<FloatingPointScalar T>
Trapezoid<T>::Trapezoid() {
    vertices[0] = new Point<T>(-1.5, -1);
    vertices[1] = new Point<T>(1.5, -1);
    vertices[2] = new Point<T>(1, 1);
    vertices[3] = new Point<T>(-1, 1);
}

template<FloatingPointScalar T>
Trapezoid<T>::Trapezoid(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4) {
    vertices[0] = new Point<T>(p1);
    vertices[1] = new Point<T>(p2);
    vertices[2] = new Point<T>(p3);
    vertices[3] = new Point<T>(p4);
}

template<FloatingPointScalar T>
Trapezoid<T>::Trapezoid(const Trapezoid& other) {
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        vertices[i] = new Point<T>(*other.vertices[i]);
    }
}

template<FloatingPointScalar T>
Trapezoid<T>::Trapezoid(Trapezoid&& other) noexcept {
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        vertices[i] = other.vertices[i];
        other.vertices[i] = nullptr;
    }
}

template<FloatingPointScalar T>
Trapezoid<T>::~Trapezoid() {
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        delete vertices[i];
    }
}

template<FloatingPointScalar T>
Trapezoid<T>& Trapezoid<T>::operator=(const Trapezoid& other) {
    if (this != &other) {
        for (int i = 0; i < VERTICES_COUNT; ++i) {
            delete vertices[i];
            vertices[i] = new Point<T>(*other.vertices[i]);
        }
    }
    return *this;
}

template<FloatingPointScalar T>
Trapezoid<T>& Trapezoid<T>::operator=(Trapezoid&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < VERTICES_COUNT; ++i) {
            delete vertices[i];
            vertices[i] = other.vertices[i];
            other.vertices[i] = nullptr;
        }
    }
    return *this;
}

template<FloatingPointScalar T>
bool Trapezoid<T>::operator==(const Figure<T>& other) const {
    const Trapezoid* trap = dynamic_cast<const Trapezoid*>(&other);
    if (!trap) return false;
    
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        if (!(*vertices[i] == *trap->vertices[i])) {
            return false;
        }
    }
    return true;
}

template<FloatingPointScalar T>
Point<T> Trapezoid<T>::geometricCenter() const {
    T centerX = 0, centerY = 0;
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        centerX += vertices[i]->x;
        centerY += vertices[i]->y;
    }
    return Point<T>(centerX / VERTICES_COUNT, centerY / VERTICES_COUNT);
}

template<FloatingPointScalar T>
double Trapezoid<T>::area() const {
    double topBase = std::sqrt(std::pow(vertices[3]->x - vertices[2]->x, 2) + 
                              std::pow(vertices[3]->y - vertices[2]->y, 2));
    double bottomBase = std::sqrt(std::pow(vertices[1]->x - vertices[0]->x, 2) + 
                                 std::pow(vertices[1]->y - vertices[0]->y, 2));
    double height = std::abs(vertices[2]->y - vertices[1]->y);
    return (topBase + bottomBase) * height / 2.0;
}

template<FloatingPointScalar T>
void Trapezoid<T>::printVertices(std::ostream& os) const {
    os << "trapezoid: ";
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        os << *vertices[i];
        if (i < 3) os << " ";
    }
}

template<FloatingPointScalar T>
void Trapezoid<T>::readFromStream(std::istream& is) {
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        T x, y;
        is >> x >> y;
        delete vertices[i];
        vertices[i] = new Point<T>(x, y);
    }
}

template<FloatingPointScalar T>
Figure<T>* Trapezoid<T>::clone() const {
    return new Trapezoid<T>(*this);
}

}