#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

//int countWordOccurrences(const string& filename, const string& word) {
//    ifstream file(filename);
//    if (!file.is_open()) {
//        cerr << "Ошибка открытия файла!" << endl;
//        return -1;
//    }
//
//    string line;
//    int count = 0;
//    while (getline(file, line)) {
//        size_t pos = line.find(word);
//        while (pos != string::npos) {
//            count++;
//            pos = line.find(word, pos + 1);
//        }
//    }
//
//    file.close();
//    return count;
//}
//
//int main() {
//    setlocale(LC_ALL, "RU");
//    string filename = "text.txt";
//    string word = "example";
//
//    int occurrences = countWordOccurrences(filename, word);
//    if (occurrences == -1) {
//        return 1;
//    }
//
//    cout << "Слово \"" << word << "\" встречается " << occurrences << " раз в файле." << endl;
//
//    return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

// Класс, представляющий матрицу
class Matrix {
private:
    std::vector<std::vector<int>> data; // Двумерный вектор для хранения данных матрицы
public:
    // Конструктор для инициализации матрицы
    Matrix(const std::vector<std::vector<int>>& d) : data(d) {}

    // Метод для вывода матрицы на экран
    void print() const {
        for (const auto& row : data) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }

    // Метод для записи матрицы в текстовый файл
    void writeToFile(const std::string& filename) const {
        std::ofstream file(filename); // Открытие файла для записи
        if (file.is_open()) { // Проверка успешности открытия файла
            for (const auto& row : data) { // Перебор строк матрицы
                for (int val : row) { // Перебор элементов строки
                    file << val << " "; // Запись элемента в файл с пробелом
                }
                file << std::endl; // Запись символа новой строки
            }
            file.close(); // Закрытие файла
            std::cout << "Матрица успешно записана в файл " << filename << std::endl;
        }
        else {
            std::cerr << "Ошибка при открытии файла " << filename << std::endl;
        }
    }

    // Метод для чтения матрицы из текстового файла
    static Matrix readFromFile(const std::string& filename) {
        std::ifstream file(filename); // Открытие файла для чтения
        if (file.is_open()) { // Проверка успешности открытия файла
            std::vector<std::vector<int>> matrixData; // Вектор для хранения данных матрицы
            std::string line; // Строка для считывания строк из файла
            while (std::getline(file, line)) { // Чтение строк из файла
                std::vector<int> row; // Вектор для хранения элементов строки
                std::istringstream iss(line); // Поток для разбора строки на числа
                int val; // Переменная для хранения считанного числа
                while (iss >> val) { // Считывание чисел из строки
                    row.push_back(val); // Добавление числа в строку
                }
                matrixData.push_back(row); // Добавление строки в матрицу
            }
            file.close(); // Закрытие файла
            std::cout << "Матрица успешно считана из файла " << filename << std::endl;
            return Matrix(matrixData); // Возвращение созданной матрицы
        }
        else {
            std::cerr << "Ошибка при открытии файла " << filename << std::endl;
            return Matrix({}); // Возвращение пустой матрицы в случае ошибки
        }
    }

    // Метод для записи матрицы в бинарный файл
    void writeToBinaryFile(const std::string& filename) const {
        std::ofstream file(filename, std::ios::binary); // Открытие файла для записи в бинарном режиме
        if (file.is_open()) { // Проверка успешности открытия файла
            for (const auto& row : data) { // Перебор строк матрицы
                file.write(reinterpret_cast<const char*>(row.data()), row.size() * sizeof(int)); // Запись строки в файл
            }
            file.close(); // Закрытие файла
            std::cout << "Матрица успешно записана в бинарный файл " << filename << std::endl;
        }
        else {
            std::cerr << "Ошибка при открытии бинарного файла " << filename << std::endl;
        }
    }

    // Метод для чтения матрицы из бинарного файла
    static Matrix readFromBinaryFile(const std::string& filename, int rows, int cols) {
        std::ifstream file(filename, std::ios::binary); // Открытие файла для чтения в бинарном режиме
        if (file.is_open()) { // Проверка успешности открытия файла
            std::vector<std::vector<int>> matrixData; // Вектор для хранения данных матрицы
            for (int i = 0; i < rows; ++i) { // Чтение строк матрицы
                std::vector<int> row(cols); // Создание вектора для строки
                file.read(reinterpret_cast<char*>(row.data()), cols * sizeof(int)); // Чтение строки из файла
                matrixData.push_back(row); // Добавление строки в матрицу
            }
            file.close(); // Закрытие файла
            std::cout << "Матрица успешно считана из бинарного файла " << filename << std::endl;
            return Matrix(matrixData); // Возвращение созданной матрицы
        }
        else {
            std::cerr << "Ошибка при открытии бинарного файла " << filename << std::endl;
            return Matrix({}); // Возвращение пустой матрицы в случае ошибки
        }
    }
};

//int main() {
//    // Исходные данные матрицы
//    std::vector<std::vector<int>> matrixData = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
//    Matrix matrix(matrixData); // Создание объекта матрицы
//
//    // Запись и чтение из текстового файла
//    matrix.writeToFile("matrix.txt"); // Запись матрицы в текстовый файл
//    Matrix matrixFromFile = Matrix::readFromFile("matrix.txt"); // Чтение матрицы из текстового файла
//    std::cout << "Матрица из файла:" << std::endl;
//    matrixFromFile.print(); // Вывод матрицы из файла на экран
//
//    // Запись и чтение из бинарного файла
//    matrix.writeToBinaryFile("matrix.bin"); // Запись матрицы в бинарный файл
//    Matrix matrixFromBinaryFile = Matrix::readFromBinaryFile("matrix.bin", 3, 3); // Чтение матрицы из бинарного файла
//    std::cout << "Матрица из бинарного файла:" << std::endl;
//    matrixFromBinaryFile.print(); // Вывод матрицы из бинарного файла на экран
//
//    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

struct Book {
    string id;
    string author;
    string title;
    int pages;

    Book(const string& _id, const string& _author, const string& _title, int _pages) : id(_id), author(_author), title(_title), pages(_pages) {}
};

void addBook(const string& filename, const Book& book) {
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    file << book.id << " " << book.author << " " << book.title << " " << book.pages << endl;
    cout << "Книга добавлена!" << endl;

    file.close();
}

void viewAllBooks(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    cout << "Все книги:" << endl;
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void deleteBook(const string& filename, const string& id) {
    ifstream file(filename);
    if (!file) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    vector<string> lines;
    string line;
    bool found = false;
    while (getline(file, line)) {
        string temp_id;
        istringstream iss(line);
        iss >> temp_id;
        if (temp_id != id) {
            lines.push_back(line);
        }
        else {
            found = true;
        }
    }

    file.close();

    if (!found) {
        cerr << "Книга с указанным ID не найдена!" << endl;
        return;
    }

    ofstream outFile(filename);
    for (const string& l : lines) {
        outFile << l << endl;
    }
    cout << "Книга удалена!" << endl;
    outFile.close();
}

void searchBook(const string& filename, const string& query) {
    ifstream file(filename);
    if (!file) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    cout << "Поиск книги по запросу '" << query << "':" << endl;
    string line;
    bool found = false;
    while (getline(file, line)) {
        if (line.find(query) != string::npos) {
            cout << line << endl;
            found = true;
        }
    }

    file.close();

    if (!found) {
        cerr << "Книга не найдена!" << endl;
    }
}

void editBook(const string& filename, const string& id, const Book& newBook) {
    ifstream file(filename);
    if (!file) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    vector<string> lines;
    string line;
    bool found = false;
    while (getline(file, line)) {
        string temp_id;
        istringstream iss(line);
        iss >> temp_id;
        if (temp_id == id) {
            ostringstream oss;
            oss << newBook.id << " " << newBook.author << " " << newBook.title << " " << newBook.pages;
            lines.push_back(oss.str());
            found = true;
        }
        else {
            lines.push_back(line);
        }
    }

    file.close();

    if (!found) {
        cerr << "Книга с указанным ID не найдена!" << endl;
        return;
    }

    ofstream outFile(filename);
    for (const string& l : lines) {
        outFile << l << endl;
    }
    cout << "Книга отредактирована!" << endl;
    outFile.close();
}

int main() {
    setlocale(LC_ALL, "RU");
    const string filename = "books_catalog.txt";

    // Добавление новой книги
    Book newBook("0003", "J.R.R. Tolkien", "The Hobbit", 310);
    addBook(filename, newBook);

    // Просмотр всех книг
    viewAllBooks(filename);
    cout << endl;

    // Удаление книги по ID
    deleteBook(filename, "0002");

    // Просмотр всех книг после удаления
    viewAllBooks(filename);
    cout << endl;

    // Поиск книги по запросу
    searchBook(filename, "Tolkien");
    cout << endl;

    // Редактирование книги по ID
    Book updatedBook("0003", "J.R.R. Tolkien", "The Lord of the Rings", 1178);
    editBook(filename, "0003", updatedBook);

    // Просмотр всех книг после редактирования
    viewAllBooks(filename);

    return 0;
}
