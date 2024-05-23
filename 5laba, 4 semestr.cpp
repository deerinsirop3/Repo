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

class Matrix {
private:

public:
    vector<vector<int>> data;
    Matrix(const vector<vector<int>>& _data) : data(_data) {}

    void print() const {
        for (const auto& row : data) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    vector<vector<int>> getData() const {
        return data;
    }

    friend ostream& operator<<(ostream& os, const Matrix& matrix);
    friend istream& operator>>(istream& is, Matrix& matrix);
};

ostream& operator<<(ostream& os, const Matrix& matrix) {
    for (const auto& row : matrix.data) {
        for (int val : row) {
            os.write(reinterpret_cast<const char*>(&val), sizeof(int));
        }
    }
    return os;
}

istream& operator>>(istream& is, Matrix& matrix) {
    for (auto& row : matrix.data) {
        for (int& val : row) {
            is.read(reinterpret_cast<char*>(&val), sizeof(int));
        }
    }
    return is;
}

void writeMatrixToFile(const string& filename, const Matrix& matrix) {
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    file << matrix;

    file.close();
}

Matrix readMatrixFromFile(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return Matrix({}); // Возвращаем пустую матрицу в случае ошибки
    }

    Matrix matrix({}); // Создаем пустую матрицу

    for (auto& row : matrix.data) {
        vector<int> temp(matrix.data[0].size());
        file.read(reinterpret_cast<char*>(temp.data()), temp.size() * sizeof(int));
        row = temp;
    }

    file.close();
    return matrix;
}

//int main() {
//    setlocale(LC_ALL, "RU");
//    // Создаем матрицу для записи в файл
//    Matrix matrix_to_write({ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} });
//
//    // Записываем матрицу в бинарный файл
//    writeMatrixToFile("matrix.txt", matrix_to_write);
//
//    // Считываем матрицу из бинарного файла
//    Matrix matrix_from_binary_file = readMatrixFromFile("matrix.txt");
//
//    // Выводим считанную матрицу
//    cout << "Матрица из бинарного файла:" << endl;
//    matrix_from_binary_file.print();
//
//    return 0;
//}
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
