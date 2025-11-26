#include <cmath>
#include <cstring>

namespace figures {

template<FloatingPointScalar T>
Rectangle<T>::Rectangle() {
    vertices[0] = new Point<T>(-1, -1);
    vertices[1] = new Point<T>(1, -1);
    vertices[2] = new Point<T>(1, 1);
    vertices[3] = new Point<T>(-1, 1);
}

template<FloatingPointScalar T>
Rectangle<T>::Rectangle(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4) {
    vertices[0] = new Point<T>(p1);
    vertices[1] = new Point<T>(p2);
    vertices[2] = new Point<T>(p3);
    vertices[3] = new Point<T>(p4);
}

template<FloatingPointScalar T>
Rectangle<T>::Rectangle(const Rectangle& other) {
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        vertices[i] = new Point<T>(*other.vertices[i]);
    }
}

template<FloatingPointScalar T>
Rectangle<T>::Rectangle(Rectangle&& other) noexcept {
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        vertices[i] = other.vertices[i];
        other.vertices[i] = nullptr;
    }
}

template<FloatingPointScalar T>
Rectangle<T>::~Rectangle() {
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        delete vertices[i];
    }
}

template<FloatingPointScalar T>
Rectangle<T>& Rectangle<T>::operator=(const Rectangle& other) {
    if (this != &other) {
        for (int i = 0; i < VERTICES_COUNT; ++i) {
            delete vertices[i];
            vertices[i] = new Point<T>(*other.vertices[i]);
        }
    }
    return *this;
}

template<FloatingPointScalar T>
Rectangle<T>& Rectangle<T>::operator=(Rectangle&& other) noexcept {
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
bool Rectangle<T>::operator==(const Figure<T>& other) const {
    const Rectangle* rect = dynamic_cast<const Rectangle*>(&other);
    if (!rect) return false;
    
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        if (!(*vertices[i] == *rect->vertices[i])) {
            return false;
        }
    }
    return true;
}

template<FloatingPointScalar T>
Point<T> Rectangle<T>::geometricCenter() const {
    T centerX = 0, centerY = 0;
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        centerX += vertices[i]->x;
        centerY += vertices[i]->y;
    }
    return Point<T>(centerX / VERTICES_COUNT, centerY / VERTICES_COUNT);
}

template<FloatingPointScalar T>
double Rectangle<T>::area() const {
    double width = std::sqrt(std::pow(vertices[1]->x - vertices[0]->x, 2) + 
                            std::pow(vertices[1]->y - vertices[0]->y, 2));
    double height = std::sqrt(std::pow(vertices[2]->x - vertices[1]->x, 2) + 
                             std::pow(vertices[2]->y - vertices[1]->y, 2));
    return width * height;
}

template<FloatingPointScalar T>
void Rectangle<T>::printVertices(std::ostream& os) const {
    os << "rectangle: ";
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        os << *vertices[i];
        if (i < 3) os << " ";
    }
}

template<FloatingPointScalar T>
void Rectangle<T>::readFromStream(std::istream& is) {
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        T x, y;
        is >> x >> y;
        delete vertices[i];
        vertices[i] = new Point<T>(x, y);
    }
}

template<FloatingPointScalar T>
Figure<T>* Rectangle<T>::clone() const {
    return new Rectangle<T>(*this);
}

}