#include "figure_array.hpp"

namespace figures {

template<FloatingPointScalar T>
FigureArray<T>::FigureArray() : count(0) {
    figures = Array<std::shared_ptr<Figure<T>>>(10, nullptr);
}

template<FloatingPointScalar T>
FigureArray<T>::FigureArray(const FigureArray& other) : count(other.count) {
    figures = Array<std::shared_ptr<Figure<T>>>(other.count);
    for (size_t i = 0; i < count; ++i) {
        figures[i] = other.figures[i]->clone();
    }
}

template<FloatingPointScalar T>
FigureArray<T>::FigureArray(FigureArray&& other) noexcept 
    : figures(std::move(other.figures)), count(other.count) {
    other.count = 0;
}

template<FloatingPointScalar T>
FigureArray<T>::~FigureArray() = default;

template<FloatingPointScalar T>
FigureArray<T>& FigureArray<T>::operator=(const FigureArray& other) {
    if (this != &other) {
        count = other.count;
        figures = Array<std::shared_ptr<Figure<T>>>(count);
        for (size_t i = 0; i < count; ++i) {
            figures[i] = other.figures[i]->clone();
        }
    }
    return *this;
}

template<FloatingPointScalar T>
FigureArray<T>& FigureArray<T>::operator=(FigureArray&& other) noexcept {
    if (this != &other) {
        figures = std::move(other.figures);
        count = other.count;
        other.count = 0;
    }
    return *this;
}

template<FloatingPointScalar T>
void FigureArray<T>::addFigure(std::shared_ptr<Figure<T>> figure) {
    if (count >= figures.size()) {
        figures.resize(figures.size() * 2);
    }
    figures[count] = figure;
    count++;
}

template<FloatingPointScalar T>
void FigureArray<T>::removeFigure(size_t index) {
    if (index >= count) return;
    
    for (size_t i = index; i < count - 1; ++i) {
        figures[i] = std::move(figures[i + 1]);
    }
    figures[count - 1] = nullptr;
    count--;
}

template<FloatingPointScalar T>
void FigureArray<T>::printAllFigures(std::ostream& os) const {
    for (size_t i = 0; i < count; ++i) {
        auto fig = figures[i];
        os << "Figure " << i << ": " << *fig << std::endl;
        auto center = fig->geometricCenter();
        double area = fig->area();
        os << "Geometric center: (" << center.x << ", " << center.y << ")" << std::endl;
        os << "Area: " << area << std::endl;
        os << "---" << std::endl;
    }
}

template<FloatingPointScalar T>
double FigureArray<T>::totalArea() const {
    double total = 0;
    for (size_t i = 0; i < count; ++i) {
        total += figures[i]->area();
    }
    return total;
}

template<FloatingPointScalar T>
std::shared_ptr<Figure<T>> FigureArray<T>::operator[](size_t index) {
    return figures[index];
}

template<FloatingPointScalar T>
const std::shared_ptr<Figure<T>> FigureArray<T>::operator[](size_t index) const {
    return figures[index];
}

template<FloatingPointScalar T>
size_t FigureArray<T>::size() const { return count; }

template<FloatingPointScalar T>
std::ostream& operator<<(std::ostream& os, const FigureArray<T>& array) {
    array.printAllFigures(os);
    return os;
}

}