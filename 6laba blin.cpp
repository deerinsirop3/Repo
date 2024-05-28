

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>


std::vector<int> readVectorFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<int> vct;
    int num;

    while (file >> num) {
        vct.push_back(num);
    }

    file.close();
    return vct;
}



void reverseVector(std::vector<int>& vec) {
    std::reverse(vec.begin(), vec.end());
}


int findMinElement(const std::vector<int>& vec) {
    auto minElement = std::min_element(vec.begin(), vec.end());
    return *minElement;
}


bool isEven(int num) {
    return num % 2 == 0;
}

void removeEvenNumbers(std::vector<int>& vec) {
    vec.erase(std::remove_if(vec.begin(), vec.end(), isEven), vec.end());
}


void sortVector(std::vector<int>& vec, bool ascending = true) {
    if (ascending) {
        std::sort(vec.begin(), vec.end());
    }
    else {
        std::sort(vec.begin(), vec.end(), std::greater<int>()/* функция, выполняющая операцию больше, следовательно, если false, то вектор будет реверсироваться*/);
    }
}


void insertElement(std::vector<int>& vec, int element) {
    auto it = std::lower_bound(vec.begin(), vec.end(), element);
    vec.insert(it, element); //lower bound return first element which is ? value. If not, return end().
}


int findElementIndex(const std::vector<int>& vec, int element) {
    auto it = std::find(vec.begin(), vec.end(), element);
    if (it != vec.end()) {
        return std::distance(vec.begin(), it); // Возвращает индекс элемента
    }
    else {
        return -1; // Если элемент не найден
    }
}


void removeDuplicates(std::vector<int>& vec) {
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}


int main() {

    setlocale(LC_ALL, "RU");

    std::vector<int> myVector = readVectorFromFile("vector_base.txt");

    // Проверим, успешно ли считали вектор из файла
    std::cout << "№1. Считанный вектор из файла: ";
    for (int num : myVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    myVector = { 1, 2, 3, 4, 5 };

    std::cout << "\n№2. Исходный вектор: ";
    for (int num : myVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    reverseVector(myVector);

    std::cout << "Реверсированный вектор: ";
    for (int num : myVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    myVector = { 5, 2, 8, 1, 9 };

    std::cout << "\n№3. Исходный вектор: ";
    for (int num : myVector) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    int minElement = findMinElement(myVector);

    std::cout << "Минимальный элемент: " << minElement << std::endl;

    myVector = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    std::cout << "\n№4. Исходный вектор: ";
    for (int num : myVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    removeEvenNumbers(myVector);

    std::cout << "Вектор после удаления четных чисел: ";
    for (int num : myVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    myVector = { 9, 2, 5, 1, 7 };

    std::cout << "\n№5. Исходный вектор: ";
    for (int num : myVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Сортировка по возрастанию
    sortVector(myVector);
    std::cout << "Вектор после сортировки по возрастанию: ";
    for (int num : myVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Сортировка по убыванию
    sortVector(myVector, false);
    std::cout << "Вектор после сортировки по убыванию: ";
    for (int num : myVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    myVector = { 1, 3, 5, 7, 9 };

    std::cout << "\n№6. Исходный вектор: ";
    for (int num : myVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int elementToInsert = 4;

    // Вставляем элемент
    insertElement(myVector, elementToInsert);

    std::cout << "Вектор после вставки элемента " << elementToInsert << ": ";
    for (int num : myVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    myVector = { 1, 3, 5, 7, 9 };

    std::cout << "\n№7. Исходный вектор: ";
    for (int num : myVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int elementToFind = 5;
    int index = findElementIndex(myVector, elementToFind);

    if (index != -1) {
        std::cout << "Индекс элемента " << elementToFind << " в векторе: " << index << std::endl;
    }
    else {
        std::cout << "Элемент " << elementToFind << " не найден в векторе." << std::endl;
    }


    myVector = { 1, 2, 2, 3, 4, 4, 5, 5, 5 };

    std::cout << "\n№8. Исходный вектор: ";
    for (int num : myVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Удаляем дубликаты
    removeDuplicates(myVector);

    std::cout << "Вектор после удаления дубликатов: ";
    for (int num : myVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

