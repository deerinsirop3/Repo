#include <iostream>
#include <vector>

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;

public:
    Matrix(int rows, int cols) : data(rows, std::vector<T>(cols)) {}

    T& operator()(int i, int j) {
        return data[i][j];
    }

    const T& operator()(int i, int j) const {
        return data[i][j];
    }

    int rows() const {
        return data.size();
    }

    int cols() const {
        return data[0].size();
    }
};

template<typename T>
class Vector {
private:
    std::vector<T> data;

public:
    Vector(int size) : data(size) {}

    T& operator[](int i) {
        return data[i];
    }

    const T& operator[](int i) const {
        return data[i];
    }

    int size() const {
        return data.size();
    }

    // Векторное произведение
    Vector<T> crossProduct(const Vector<T>& other) const {
        if (size() != 3 || other.size() != 3) {
            std::cerr << "Определено только для 3х мерных векторов" << std::endl;
            return Vector<T>(0);
        }

        Vector<T> result(3);
        result[0] = data[1] * other[2] - data[2] * other[1];
        result[1] = data[2] * other[0] - data[0] * other[2];
        result[2] = data[0] * other[1] - data[1] * other[0];
        return result;
    }

    // Скалярное произведение
    T dotProduct(const Vector<T>& other) const {
        if (size() != other.size()) {
            std::cerr << " Для скалярного произведения требуются векторы одинаковой длины." << std::endl;
            return T(); // Default value for type T
        }

        T result = 0;
        for (int i = 0; i < size(); ++i) {
            result += data[i] * other[i];
        }
        return result;
    }
};

template<typename T>
int findSecondMaxIndex(T* arr, int size) {
    if (size < 2) {
        std::cerr << "Array size must be at least 2." << std::endl;
        return -1;
    }

    int maxIndex = 0;
    int secondMaxIndex = -1;

    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[maxIndex]) {
            secondMaxIndex = maxIndex;
            maxIndex = i;
        }
        else if (secondMaxIndex == -1 || arr[i] > arr[secondMaxIndex]) {
            secondMaxIndex = i;
        }
    }

    return secondMaxIndex;
}

int main() {
    setlocale(LC_ALL, "RU");
    // Пример использования шаблона функции для поиска второго максимума в массиве
    int intArr[] = { 3, 1, 4, 5, 2 };
    std::cout << "Index of the second maximum in int array: " << findSecondMaxIndex(intArr, 5) << std::endl;

    float floatArr[] = { 3.5, 1.2, 4.7, 5.9, 2.3 };
    std::cout << "Index of the second maximum in float array: " << findSecondMaxIndex(floatArr, 5) << std::endl;

    double doubleArr[] = { 3.5, 1.2, 4.7, 5.9, 2.3 };
    std::cout << "Index of the second maximum in double array: " << findSecondMaxIndex(doubleArr, 5) << std::endl;

    char charArr[] = { 'a', 'b', 'c', 'd', 'e' };
    std::cout << "Index of the second maximum in char array: " << findSecondMaxIndex(charArr, 5) << std::endl;

    // Пример использования шаблона класса Matrix
    Matrix<int> intMatrix(3, 3);
    intMatrix(0, 0) = 1;
    intMatrix(0, 1) = 2;
    std::cout << "Element at (0, 0): " << intMatrix(0, 0) << std::endl;

    Matrix<float> floatMatrix(2, 2);
    floatMatrix(0, 0) = 1.5;
    floatMatrix(0, 1) = 2.3;
    std::cout << "Element at (0, 1): " << floatMatrix(0, 1) << std::endl;

    // Пример использования шаблона класса Vector
    Vector<int> intVector(3);
    intVector[0] = 1;
    intVector[1] = 2;
    intVector[2] = 3;

    Vector<int> intVector2(3);
    intVector2[0] = 4;
    intVector2[1] = 5;
    intVector2[2] = 6;

    std::cout << "Векторное произведение";
    Vector<int> cross = intVector.crossProduct(intVector2);
    for (int i = 0; i < cross.size(); ++i) {
        std::cout << cross[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Скалярное произведение " << intVector.dotProduct(intVector2) << std::endl;

    return 0;
}
