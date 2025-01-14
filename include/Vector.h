#pragma once

#include <limits>
#include <cmath>
#include <vector>
#include <string>
#include <stdexcept>

namespace MyMath {

template <typename T>
class Vector {
    private:
        std::vector<T> data;
        size_t size;

    public:
        Vector()
            : size(0) {}

        Vector(size_t size)
            : size(size) {
                data.resize(size);
        }

        Vector(const std::vector<T>& vec) 
            : data(vec) {
                size = vec.size();
        }

        Vector(const Vector<T>& other) 
             {
                size = other.getSize();
                data.resize(size);
                for (int i = 0; i < size; i++) {
                    data[i] = other[i];
                }
            }

        size_t getSize() const {
            return size;
        }

        T& operator[](int i) {
            return data[i];
        }

        const T& operator[](int i) const {
            return data[i];
        }

        bool operator==(const Vector<T>& other) const {
            if (size != other.getSize()) {
                return false;
            }

            for (int i = 0; i < size; i++) {
                if (data[i] != other[i]) {
                    return false;
                }
            }

            return true;
        }

        Vector<T> operator+(const Vector<T>& other) const {
            if (size != other.getSize()) {
                throw std::invalid_argument("Vectors are of size "
                + std::to_string(data.size()) + " and " + std::to_string(other.getSize()) 
                + ", must have the same size");
            }
            Vector<T> result(data.size());
            for (int i = 0; i < size; i++) {
                result[i] = data[i] + other[i];
            }
            return result;
        }

        Vector<T> operator-(const Vector<T>& other) const {
            if (size != other.getSize()) {
                throw std::invalid_argument("Vectors are of size "
                + std::to_string(data.size()) + " and " + std::to_string(other.getSize()) 
                + ", must have the same size");
            }
            Vector<T> result = Vector<T>(data);
            for (int i = 0; i < size; i++) {
                result[i] -= other[i];
            }
            return result;
        }

        friend Vector<T> operator*(const T scalar, const Vector<T>& v){
            Vector<T> result(v.getSize());
            for (int i = 0; i < v.getSize(); i++) {   
                result[i] = v[i] * scalar;
            }
            return result;
        }

        Vector<T> operator*(const T scalar) const {
            Vector<T> result(size);
            for (int i = 0; i < size; i++) {
                result[i] = data[i] * scalar;
            }
            return result;
        }

        Vector<T> operator/(const T scalar) const {
            if (scalar == 0) {
                throw std::invalid_argument("Division by zero");
            }
            Vector<T> result(size);
            for (int i = 0; i < size; i++) {
                result[i] = data[i] / scalar;
            }
            return result;
        }

        Vector<T> operator+=(const Vector<T>& other) {
            if (size != other.getSize()) {
                throw std::invalid_argument("Vectors are of size "
                + std::to_string(data.size()) + " and " + std::to_string(other.getSize()) 
                + ", must have the same size");
            }
            for (int i = 0; i < size; i++) {
                data[i] += other[i];
            }
            return *this;
        }

        Vector<T> operator-=(const Vector<T>& other) {
            if (size != other.getSize()) {
                throw std::invalid_argument("Vectors are of size "
                + std::to_string(data.size()) + " and " + std::to_string(other.getSize()) 
                + ", must have the same size");
            }
            for (int i = 0; i < size; i++) {
                data[i] -= other[i];
            }
            return *this;
        }

        Vector<T> operator*=(const T scalar) {
            for (int i = 0; i < size; i++) {
                data[i] *= scalar;
            }
            return *this;
        }

        Vector<T> operator/=(const T scalar) {
            for (int i = 0; i < size; i++) {
                data[i] /= scalar;
            }
            return *this;
        }

        double norm(int p=2) const { //todo output should be double or float depending on T
            double sum = 0;
            for (int i = 0; i < data.size(); i++) {
                sum += std::pow(std::abs(data[i]), p);
            }
            return std::pow(sum, 1.0/p);
        }

        T max() const {
            T result = std::numeric_limits<T>::min();
            for (int i = 0; i < size; i++) {
                if (data[i] > result) {
                    result = data[i];
                }
            }
            return result;
        }

        T min() const {
            T result = std::numeric_limits<T>::max();
            for (int i = 0; i < size; i++) {
                if (data[i] < result) {
                    result = data[i];
                }
            }
            return result;
        }

};

template <typename T>
T dot(const Vector<T>& v0, const Vector<T>& v1) {
    if (v0.getSize() != v1.getSize()) {
        throw std::invalid_argument("Vectors are of size "
        + std::to_string(v0.getSize()) + " and " + std::to_string(v1.getSize()) 
        + ", must have the same size");
    }
    T result = 0;
    for (int i = 0; i < v0.getSize(); i++) {
        result += v0[i] * v1[i];
    }
    return result;
}

}; // namespace MyMath

