#pragma once

namespace MyMath {

template <typename T>
class Vector {
    private:
        std::vector<T> data;

    public:
        Vector(size_t size) {
            data.resize(size);
        }

        Vector(const std::vector<T>& vec) 
            : data(vec) {}

        Vector(const Vector<T>& other) 
            : data(other.data) {}

        size_t size() const {
            return data.size();
        }

        T operator[](int i) const {
            return data[i];
        }

        bool operator==(const Vector<T>& other) const {
            if (data.size() != other.size()) {
                return false;
            }

            for (int i = 0; i < data.size(); i++) {
                if (data[i] != other[i]) {
                    return false;
                }
            }

            return true;
        }

        Vector<T> operator+(const Vector<T>& other) const {
            if (data.size() != other.size()) {
                throw std::invalid_argument("Vectors are of size "
                + std::to_string(data.size()) + " and " + std::to_string(other.size()) 
                + ", must have the same size");
            }
            Vector<T> result(data.size());
            for (int i = 0; i < data.size(); i++) {
                result.data[i] = data[i] + other[i];
            }
            return result;
        }

        Vector<T> operator-(const Vector<T>& other) const {
            if (data.size() != other.size()) {
                throw std::invalid_argument("Vectors are of size "
                + std::to_string(data.size()) + " and " + std::to_string(other.size()) 
                + ", must have the same size");
            }
            Vector<T> result(data.size());
            for (int i = 0; i < data.size(); i++) {
                result.data[i] = data[i] - other[i];
            }
            return result;
        }

        friend Vector<T> operator*(const T scalar, const Vector<T>& v){
            Vector<T> result(v.size());
            for (int i = 0; i < v.size(); i++) {   
                result.data[i] = v[i] * scalar;
            }
            return result;
        }

        Vector<T> operator*(const T scalar) const {
            Vector<T> result(data.size());
            for (int i = 0; i < data.size(); i++) {
                result.data[i] = data[i] * scalar;
            }
            return result;
        }

        Vector<T> operator/(const T scalar) const {
            if (scalar == 0) {
                throw std::invalid_argument("Division by zero");
            }
            Vector<T> result(data.size());
            for (int i = 0; i < data.size(); i++) {
                result.data[i] = data[i] / scalar;
            }
            return result;
        }

};
}; // namespace MyMath

