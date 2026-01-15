#include "Vector.h"
#include <sstream>
#include <iomanip>
#include <iostream>
#include <cmath>

Vector::Vector() : x(0.0), y(0.0), z(0.0) {}
Vector::Vector(double x, double y, double z) : x(x), y(y), z(z) {}

double Vector::getX() const {return x;}

double Vector::getY() const {
    return y;
}

double Vector::getZ() const {
    return z;
}

void Vector::setX(double newX) {
    x = newX;
}

void Vector::setY(double newY) {
    y = newY;
}

void Vector::setZ(double newZ) {
    z = newZ;
}

void Vector::setAll(double newX, double newY, double newZ) {
    x = newX;
    y = newY;
    z = newZ;
}

double Vector::getMagnitude() const {
    return sqrt(x * x + y * y + z * z);
}

std::string Vector::toString() const {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(3);
    stream << "Vector(" << x << ", " << y << ", " << z << ")";
    return stream.str();
}

Vector Vector::add(const Vector& other) const {
    return Vector(x + other.x, y + other.y, z + other.z);
}

Vector Vector::subtract(const Vector& other) const {
    return Vector(x - other.x, y - other.y, z - other.z);
}

double Vector::dotProduct(const Vector& other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector Vector::crossProduct(const Vector& other) const {
    double newX = y * other.z - z * other.y;
    double newY = z * other.x - x * other.z;
    double newZ = x * other.y - y * other.x;
    return Vector(newX, newY, newZ);
}

Vector Vector::multiplyByScalar(double scalar) const {
    return Vector(x * scalar, y * scalar, z * scalar);
}

Vector Vector::normalize() const {
    double magnitude = getMagnitude();
    if (magnitude == 0.0) {
        return Vector(0, 0, 0);
    }
    return Vector(x / magnitude, y / magnitude, z / magnitude);
}

Vector Vector::operator+(const Vector& other) const {
    return this->add(other);
}

Vector Vector::operator-(const Vector& other) const {
    return this->subtract(other);
}

double Vector::operator*(const Vector& other) const {
    return this->dotProduct(other);
}

Vector Vector::operator*(double scalar) const {
    return this->multiplyByScalar(scalar);
}

bool Vector::equals(const Vector& other, double epsilon) const {
    return (fabs(x - other.x) < epsilon &&
        fabs(y - other.y) < epsilon &&
        fabs(z - other.z) < epsilon);
}

void printVectorInfo(const Vector& vec, const std::string& name) {
    std::cout << name << ":" << std::endl;
    std::cout << "  Координаты: (" << vec.getX() << ", "
        << vec.getY() << ", " << vec.getZ() << ")" << std::endl;
    std::cout << "  Длина вектора: " << vec.getMagnitude() << std::endl;
    std::cout << "  Строковое представление: " << vec.toString() << std::endl;
    std::cout << std::endl;
}

void testVectorOperations() {
    std::cout << "=== ТЕСТИРОВАНИЕ ОСНОВНЫХ ОПЕРАЦИЙ ===" << std::endl;

    Vector v1(1, 2, 3);
    Vector v2(4, 5, 6);

    Vector sum = v1.add(v2);
    std::cout << "Сложение: " << v1.toString() << " + "
        << v2.toString() << " = " << sum.toString() << std::endl;

    Vector diff = v1.subtract(v2);
    std::cout << "Вычитание: " << v1.toString() << " - "
        << v2.toString() << " = " << diff.toString() << std::endl;

    double dot = v1.dotProduct(v2);
    std::cout << "Скалярное произведение: " << v1.toString() << " * "
        << v2.toString() << " = " << dot << std::endl;

    Vector cross = v1.crossProduct(v2);
    std::cout << "Векторное произведение: " << v1.toString() << " x "
        << v2.toString() << " = " << cross.toString() << std::endl;

    Vector scaled = v1.multiplyByScalar(2.5);
    std::cout << "Умножение на скаляр: " << v1.toString() << " * 2.5 = "
        << scaled.toString() << std::endl;

    Vector normalized = v1.normalize();
    std::cout << "Нормированный вектор: " << v1.toString() << " -> "
        << normalized.toString() << std::endl;
    std::cout << "Длина нормированного вектора: " << normalized.getMagnitude()
        << std::endl;

    std::cout << std::endl;
}

void testOperators() {
    std::cout << "=== ТЕСТИРОВАНИЕ ОПЕРАТОРОВ ===" << std::endl;

    Vector a(1, 2, 3);
    Vector b(4, 5, 6);

    std::cout << "Оператор +: " << a.toString() << " + "
        << b.toString() << " = " << (a + b).toString() << std::endl;

    std::cout << "Оператор -: " << a.toString() << " - "
        << b.toString() << " = " << (a - b).toString() << std::endl;

    std::cout << "Оператор * (скалярное): " << a.toString() << " * "
        << b.toString() << " = " << (a * b) << std::endl;

    std::cout << "Оператор * (на скаляр): " << a.toString() << " * 3 = "
        << (a * 3).toString() << std::endl;

    std::cout << std::endl;
}

int main() {
    std::cout << "=== ТЕСТИРОВАНИЕ КЛАССА VECTOR ===" << std::endl << std::endl;
    std::cout << "=== КОНСТРУКТОРЫ ===" << std::endl;

    Vector v0;
    printVectorInfo(v0, "v0 (конструктор по умолчанию)");
    Vector v1(3, 4, 0);
    printVectorInfo(v1, "v1 (3, 4, 0)");
    Vector v2(1, 2, 2);
    printVectorInfo(v2, "v2 (1, 2, 2)");


    std::cout << "=== ГЕТТЕРЫ И СЕТТЕРЫ ===" << std::endl;

    std::cout << "v1.getX() = " << v1.getX() << std::endl;
    std::cout << "v1.getY() = " << v1.getY() << std::endl;
    std::cout << "v1.getZ() = " << v1.getZ() << std::endl;
    std::cout << std::endl;
    std::cout << "Изменяем v2 через сеттеры:" << std::endl;
    v2.setX(10);
    v2.setY(20);
    v2.setZ(30);
    printVectorInfo(v2, "v2 после setX, setY, setZ");
    v2.setAll(5, 12, 0);
    printVectorInfo(v2, "v2 после setAll(5, 12, 0)");

    std::cout << "=== ДЛИНА ВЕКТОРА ===" << std::endl;

    std::cout << "v1 = " << v1.toString() << std::endl;
    std::cout << "Ожидаемая длина v1: 5.0 (так как 3^2 + 4^2 = 25)" << std::endl;
    std::cout << "Реальная длина v1: " << v1.getMagnitude() << std::endl;
    std::cout << "\nv2 = " << v2.toString() << std::endl;
    std::cout << "Ожидаемая длина v2: 13.0 (так как 5^2 + 12^2 = 169)" << std::endl;
    std::cout << "Реальная длина v2: " << v2.getMagnitude() << std::endl;
    Vector v3(1, 2, 2);
    std::cout << "\nv3 = " << v3.toString() << std::endl;
    std::cout << "Ожидаемая длина v3: 3.0 (так как 1^2 + 2^2 + 2^2 = 9)" << std::endl;
    std::cout << "Реальная длина v3: " << v3.getMagnitude() << std::endl;
    std::cout << std::endl;

    testVectorOperations();
    testOperators();

    std::cout << "=== ДОПОЛНИТЕЛЬНЫЕ ТЕСТЫ ===" << std::endl;

    Vector zero;
    std::cout << "Нулевой вектор: " << zero.toString() << std::endl;
    std::cout << "Длина нулевого вектора: " << zero.getMagnitude() << std::endl;
    Vector unitX(1, 0, 0);
    Vector unitY(0, 1, 0);
    Vector unitZ(0, 0, 1);
    std::cout << "\nЕдиничные векторы:" << std::endl;
    std::cout << "unitX: " << unitX.toString()
        << ", длина: " << unitX.getMagnitude() << std::endl;
    std::cout << "unitY: " << unitY.toString()
        << ", длина: " << unitY.getMagnitude() << std::endl;
    std::cout << "unitZ: " << unitZ.toString()
        << ", длина: " << unitZ.getMagnitude() << std::endl;
    std::cout << "\nПроверка ортогональности (скалярное произведение = 0):" << std::endl;
    std::cout << "unitX * unitY = " << unitX.dotProduct(unitY) << std::endl;
    std::cout << "unitY * unitZ = " << unitY.dotProduct(unitZ) << std::endl;
    std::cout << "unitZ * unitX = " << unitZ.dotProduct(unitX) << std::endl;

    std::cout << "\n=== ТЕСТИРОВАНИЕ ЗАВЕРШЕНО ===" << std::endl;
    return 0;
}