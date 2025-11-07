namespace figures {

template<FloatingPointScalar T>
Figure<T>::operator double() const { 
    return area(); 
}

template<FloatingPointScalar T>
std::ostream& operator<<(std::ostream& os, const Figure<T>& figure) {
    figure.printVertices(os);
    return os;
}

template<FloatingPointScalar T>
std::istream& operator>>(std::istream& is, Figure<T>& figure) {
    figure.readFromStream(is);
    return is;
}

}