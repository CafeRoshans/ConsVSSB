#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <string>

class Vector {
private:
    double x;
    double y;
    double z;

public:
    Vector();
    Vector(double x, double y, double z);

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double newX);
    void setY(double newY);
    void setZ(double newZ);
    void setAll(double newX, double newY, double newZ);

    double getMagnitude() const;

    std::string toString() const;

    Vector add(const Vector& other) const;
    Vector subtract(const Vector& other) const;
    double dotProduct(const Vector& other) const;
    Vector crossProduct(const Vector& other) const;
    Vector multiplyByScalar(double scalar) const;
    Vector normalize() const;

    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    double operator*(const Vector& other) const;
    Vector operator*(double scalar) const;

    bool equals(const Vector& other, double epsilon = 1e-6) const;
};

#endif