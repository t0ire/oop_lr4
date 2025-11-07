#include <cmath>

namespace figures {

template<FloatingPointScalar T>
Rectangle<T>::Rectangle() 
    : vertices{
        std::make_unique<Point<T>>(-1, -1),
        std::make_unique<Point<T>>(1, -1),
        std::make_unique<Point<T>>(1, 1),
        std::make_unique<Point<T>>(-1, 1)
    } {}

template<FloatingPointScalar T>
Rectangle<T>::Rectangle(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4)
    : vertices{
        std::make_unique<Point<T>>(p1),
        std::make_unique<Point<T>>(p2),
        std::make_unique<Point<T>>(p3),
        std::make_unique<Point<T>>(p4)
    } {}

template<FloatingPointScalar T>
Rectangle<T>::Rectangle(const Rectangle& other) {
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        vertices[i] = std::make_unique<Point<T>>(*other.vertices[i]);
    }
}

template<FloatingPointScalar T>
Rectangle<T>::Rectangle(Rectangle&& other) noexcept {
    for (int i = 0; i < VERTICES_COUNT; ++i) {
        vertices[i] = std::move(other.vertices[i]);
    }
}

template<FloatingPointScalar T>
Rectangle<T>& Rectangle<T>::operator=(const Rectangle& other) {
    if (this != &other) {
        for (int i = 0; i < VERTICES_COUNT; ++i) {
            vertices[i] = std::make_unique<Point<T>>(*other.vertices[i]);
        }
    }
    return *this;
}

template<FloatingPointScalar T>
Rectangle<T>& Rectangle<T>::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < VERTICES_COUNT; ++i) {
            vertices[i] = std::move(other.vertices[i]);
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
        vertices[i] = std::make_unique<Point<T>>(x, y);
    }
}

template<FloatingPointScalar T>
std::shared_ptr<Figure<T>> Rectangle<T>::clone() const {
    return std::make_shared<Rectangle<T>>(*this);
}

}