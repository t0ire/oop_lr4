#include <gtest/gtest.h>

#include "point.hpp"
#include "figure.hpp"
#include "array.hpp"
#include "square.hpp"
#include "rectangle.hpp"
#include "trapezoid.hpp"
#include "figure_array.hpp"

using namespace figures;

TEST(PointTest, BasicOperations) {
    Point<double> p1(1.0, 2.0);
    Point<double> p2(1.0, 2.0);
    Point<double> p3(1.1, 2.0);
    
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

// Тест базовых операций точки
TEST(PointTest1, BasicOperations) {
    Point<double> p1(1.0, 2.0);
    Point<double> p2(1.0, 2.0);
    Point<double> p3(1.1, 2.0);
    
    EXPECT_TRUE(p1 == p2);    // Проверка равенства одинаковых точек
    EXPECT_FALSE(p1 == p3);   // Проверка неравенства разных точек
}

TEST(PointTest2, InputOutput) {
    Point<double> p1(1.5, 2.5);
    std::stringstream ss;
    ss << p1;
    EXPECT_EQ(ss.str(), "(1.5, 2.5)");  // Проверка формата вывода
    
    // Создаем новый поток для тестирования ввода
    std::stringstream input_stream("1.5 2.5");
    Point<double> p2;
    input_stream >> p2;  // Используем оператор >> для Point
    
    EXPECT_EQ(p2.x, 1.5);
    EXPECT_EQ(p2.y, 2.5);
}

// Тест сравнения точек с плавающей точкой (с учетом погрешности)
TEST(PointTest3, FloatingPointComparison) {
    Point<double> p1(1.0000000001, 2.0000000001);
    Point<double> p2(1.0000000002, 2.0000000002);
    Point<double> p3(1.1, 2.1);
    
    EXPECT_TRUE(p1 == p2);  // Должны быть равны из-за погрешности 1e-9
    EXPECT_FALSE(p1 == p3); // Разные точки не должны быть равны
}

// Тест конструктора по умолчанию квадрата
TEST(SquareTest1, DefaultConstructor) {
    Square<double> square;
    auto center = square.geometricCenter();
    
    EXPECT_NEAR(center.x, 0.0, 1e-9);  // Центр должен быть в (0,0)
    EXPECT_NEAR(center.y, 0.0, 1e-9);
    EXPECT_NEAR(square.area(), 4.0, 1e-9);  // Площадь квадрата 2x2 = 4
}

// Тест вычисления площади квадрата
TEST(SquareTest2, AreaCalculation) {
    Point<double> p1(0, 0);
    Point<double> p2(2, 0);
    Point<double> p3(2, 2);
    Point<double> p4(0, 2);
    
    Square<double> square(p1, p2, p3, p4);
    EXPECT_NEAR(square.area(), 4.0, 1e-9);  // Площадь квадрата 2x2 = 4
}

// Тест вычисления геометрического центра квадрата
TEST(SquareTest3, GeometricCenter) {
    Point<double> p1(1, 1);
    Point<double> p2(3, 1);
    Point<double> p3(3, 3);
    Point<double> p4(1, 3);
    
    Square<double> square(p1, p2, p3, p4);
    auto center = square.geometricCenter();
    
    EXPECT_NEAR(center.x, 2.0, 1e-9);  // Центр должен быть в (2,2)
    EXPECT_NEAR(center.y, 2.0, 1e-9);
}

// Тест оператора сравнения для квадратов
TEST(SquareTest4, Equality) {
    Square<double> square1;
    Square<double> square2;
    
    // Вместо EXPECT_TRUE(square1 == square2);
    EXPECT_TRUE(square1.operator==(square2));  // Явный вызов оператора
    
    Point<double> p1(0, 0), p2(1, 0), p3(1, 1), p4(0, 1);
    Square<double> square3(p1, p2, p3, p4);
    
    // Вместо EXPECT_FALSE(square1 == square3);
    EXPECT_FALSE(square1.operator==(square3));  // Явный вызов оператора
}

// Тест вычисления площади прямоугольника
TEST(RectangleTest, AreaCalculation) {
    Point<double> p1(0, 0);
    Point<double> p2(4, 0);
    Point<double> p3(4, 2);
    Point<double> p4(0, 2);
    
    Rectangle<double> rectangle(p1, p2, p3, p4);
    EXPECT_NEAR(rectangle.area(), 8.0, 1e-9);  // Площадь прямоугольника 4x2 = 8
}

// Тест вычисления геометрического центра прямоугольника
TEST(RectangleTest1, GeometricCenter) {
    Point<double> p1(0, 0);
    Point<double> p2(6, 0);
    Point<double> p3(6, 4);
    Point<double> p4(0, 4);
    
    Rectangle<double> rectangle(p1, p2, p3, p4);
    auto center = rectangle.geometricCenter();
    
    EXPECT_NEAR(center.x, 3.0, 1e-9);  // Центр должен быть в (3,2)
    EXPECT_NEAR(center.y, 2.0, 1e-9);
}

// Тест вычисления площади трапеции
TEST(TrapezoidTest, AreaCalculation) {
    Point<double> p1(-2, 0);  // нижнее основание
    Point<double> p2(2, 0);   // нижнее основание
    Point<double> p3(1, 2);   // верхнее основание
    Point<double> p4(-1, 2);  // верхнее основание
    
    Trapezoid<double> trapezoid(p1, p2, p3, p4);
    // Площадь трапеции: (4 + 2) * 2 / 2 = 6
    EXPECT_NEAR(trapezoid.area(), 6.0, 1e-9);
}

// Тест вычисления геометрического центра трапеции
TEST(TrapezoidTest1, GeometricCenter) {
    Point<double> p1(-1.5, -1);
    Point<double> p2(1.5, -1);
    Point<double> p3(1, 1);
    Point<double> p4(-1, 1);
    
    Trapezoid<double> trapezoid(p1, p2, p3, p4);
    auto center = trapezoid.geometricCenter();
    
    EXPECT_NEAR(center.x, 0.0, 1e-9);  // Центр симметричной трапеции в (0,0)
    EXPECT_NEAR(center.y, 0.0, 1e-9);
}

// Тест базовых операций массива
TEST(ArrayTest, BasicOperations) {
    Array<int> arr(5, 10);  // Массив из 5 элементов со значением 10
    
    EXPECT_EQ(arr.size(), 5);    // Проверка размера
    EXPECT_EQ(arr[0], 10);       // Проверка значения первого элемента
    EXPECT_EQ(arr[4], 10);       // Проверка значения последнего элемента
    
    arr[2] = 20;                 // Изменение элемента
    EXPECT_EQ(arr[2], 20);       // Проверка изменения
}

// Тест изменения размера массива
TEST(ArrayTest1, Resize) {
    Array<int> arr(3, 5);
    arr.resize(5);  // Увеличение размера
    
    EXPECT_EQ(arr.size(), 5);
    EXPECT_EQ(arr[0], 5);  // Старые элементы сохраняются
    EXPECT_EQ(arr[1], 5);
    EXPECT_EQ(arr[2], 5);
    EXPECT_EQ(arr[3], 0);  // Новые элементы инициализируются по умолчанию
    EXPECT_EQ(arr[4], 0);
}

// Тест семантики копирования и перемещения для массива
TEST(ArrayTest2, CopyAndMove) {
    Array<int> arr1(3, 7);
    Array<int> arr2 = arr1;  // Копирование
    
    EXPECT_EQ(arr2.size(), 3);
    EXPECT_EQ(arr2[0], 7);
    
    Array<int> arr3 = std::move(arr1);  // Перемещение
    EXPECT_EQ(arr3.size(), 3);
    EXPECT_EQ(arr1.size(), 0);  // После перемещения размер должен быть 0
}

// Тест добавления и удаления фигур из массива
TEST(FigureArrayTest, AddAndRemoveFigures) {
    FigureArray<double> figureArray;
    
    auto square = new Square<double>();
    auto rectangle = new Rectangle<double>();
    
    figureArray.addFigure(square);
    figureArray.addFigure(rectangle);
    
    EXPECT_EQ(figureArray.size(), 2);  // Проверка количества фигур
    
    figureArray.removeFigure(0);       // Удаление первой фигуры
    EXPECT_EQ(figureArray.size(), 1);  // Проверка обновленного количества
}

// Тест вычисления общей площади всех фигур в массиве
TEST(FigureArrayTest1, TotalArea) {
    FigureArray<double> figureArray;
    
    Point<double> p1(0, 0), p2(2, 0), p3(2, 2), p4(0, 2);
    auto square = new Square<double>(p1, p2, p3, p4); // Площадь = 4
    
    Point<double> r1(0, 0), r2(3, 0), r3(3, 2), r4(0, 2);
    auto rectangle = new Rectangle<double>(r1, r2, r3, r4); // Площадь = 6
    
    figureArray.addFigure(square);
    figureArray.addFigure(rectangle);
    
    EXPECT_NEAR(figureArray.totalArea(), 10.0, 1e-9);  // 4 + 6 = 10
}

// Тест семантики копирования для FigureArray
TEST(FigureArrayTest2, CopySemantics) {
    FigureArray<double> original;
    auto square = new Square<double>();
    original.addFigure(square);
    
    FigureArray<double> copy = original;  // Копирование
    EXPECT_EQ(copy.size(), 1);
    
    // Проверяем, что это глубокое копирование
    copy.removeFigure(0);
    EXPECT_EQ(copy.size(), 0);
    EXPECT_EQ(original.size(), 1);  // Оригинал не должен измениться
}

// Тест операторов доступа к элементам массива фигур
TEST(FigureArrayTest3, AccessOperators) {
    FigureArray<double> figureArray;
    
    auto square = new Square<double>();
    figureArray.addFigure(square);
    
    EXPECT_NEAR(figureArray[0]->area(), 4.0, 1e-9);  // Доступ через оператор[]
    
    // Проверка константного доступа
    const FigureArray<double>& constArray = figureArray;
    EXPECT_NEAR(constArray[0]->area(), 4.0, 1e-9);
}

// Тест преобразования фигуры в double (площадь)
TEST(FigureTest, DoubleConversion) {
    Square<double> square;
    double area = static_cast<double>(square);  // Использует operator double()
    
    EXPECT_NEAR(area, 4.0, 1e-9);  // Площадь должна быть 4.0
}

// Тест ввода/вывода для фигур
TEST(FigureTest1, InputOutput) {
    Square<double> square;
    std::stringstream ss;
    
    // Тестируем вывод
    ss << square;
    std::string output = ss.str();
    EXPECT_TRUE(output.find("square:") != std::string::npos);  // Должен содержать тип фигуры
    
    // Тестируем ввод
    Square<double> square2;
    std::stringstream input("0 0 2 0 2 2 0 2");
    input >> square2;
    
    EXPECT_NEAR(square2.area(), 4.0, 1e-9);  // Проверяем корректность чтения
}

// Тест клонирования фигур
TEST(FigureTest2, Clone) {
    Square<double> original;
    auto cloned = original.clone();  // Создаем клон
    
    EXPECT_TRUE(original == *cloned);  // Содержимое должно быть одинаковым
    EXPECT_NE(&original, cloned);  // Но это разные объекты в памяти
    
    delete cloned;  // Не забываем освободить память
}


// Тест работы с разными типами фигур в одном массиве
TEST(FigureArrayTest4, MixedFigures) {
    FigureArray<double> figureArray;
    
    // Добавляем разные типы фигур
    auto square = new Square<double>();
    auto rectangle = new Rectangle<double>();
    auto trapezoid = new Trapezoid<double>();
    
    figureArray.addFigure(square);
    figureArray.addFigure(rectangle);
    figureArray.addFigure(trapezoid);
    
    EXPECT_EQ(figureArray.size(), 3);
    
    // Проверяем, что все фигуры корректно вычисляют площадь
    for (size_t i = 0; i < figureArray.size(); ++i) {
        EXPECT_GT(figureArray[i]->area(), 0);  // Площадь должна быть положительной
    }
}

// Тест обработки исключений при выходе за границы массива
TEST(ArrayTest3, OutOfRange) {
    Array<int> arr(3, 1);
    
    EXPECT_THROW(arr[5], std::out_of_range);   // Доступ за границами
    EXPECT_THROW(arr[10], std::out_of_range);  // Доступ далеко за границами
}

// Тест операций с пустым массивом фигур
TEST(FigureArrayTest5, EmptyArrayOperations) {
    FigureArray<double> emptyArray;
    
    EXPECT_EQ(emptyArray.size(), 0);
    EXPECT_NEAR(emptyArray.totalArea(), 0.0, 1e-9);  // Площадь пустого массива = 0
    
    // Удаление из пустого массива не должно вызывать ошибок
    EXPECT_NO_THROW(emptyArray.removeFigure(0));
}
