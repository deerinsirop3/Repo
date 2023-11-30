#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <random>
#include <ctime>
#include <Windows.h>

const std::string nameList[] = {

     "Саша", "Паша", "Даша", "Коля", "Оля",
    "Юра", "Семен", "Артем", "Петя", "Лена",
    "Харитон","Артемий","Елисей","Александр",
    "Дмитрий","Виктор","Изяслав","Ярослав","Ростислав","Фадей","Богдан","Сергей",
    "Пахом","Вадим","Макар","Марк","Митофан","Остап","Потап","Прохор","Радислав",
    "Андрей","Артем","Олег","Валерий","Виталий","Владимир","Влас",
    "Вячеслав","Геннадий","Георгий","Герман","Глеб","Григорий","Давид","Данила","Дементий",
    "Дмитрий","Денис","Евгений","Евдоким","Егор","Евстафий",
    "Елисей","Емельян","Игорь","Игнатий","Захар","Измаил","Илья","Иннокентий","Иосиф","Карл","Кирилл",
    "Константин","Ян","Якуб","Юрий","Фома","Тимофей","Тимур","Тимур","Тихон","Ульян","Федор",
    "Платон","Андрей",
    "Ксения","Диана","Алиса","Виктория","Василиса","Илья","Степан","Евгений","Кирилл","Максим",
    "Вероника","Артемий","София","Тимур","Полина","Максим","Кирилл","Даниил","Илья","Алина","Евгения",
    "Лидия","Артём","Даниил","Артём","Захар","Арина","Семён","Алиса","Даниил","Алиса","Анастасия","Екатерина",
    "Герман","Елизавета","Вероника","Дмитрий","София","Платон","Никита","Елизавета","София","Василиса","Мария",
    "Георгий","Александр","Фёдор","Василиса","Николай","Алиса","Михаил","Анна","Маргарита","Захар","София","Мирон",
    "Алина","Виктория","Артём","Василиса","Полина","Анастасия","Максим","Тимофей","Екатерина","Кирилл","Арсений","Ксения","Богдан",
    "Милана","Алиса","Мария","Ксения","Василиса","Милана","Владислава","Александр","Валерия","Роман","Максим","Тимофей",
    "Владислав","Матвей","Дарья","Даниил","Ксения","Алёна","Алиса","Сергей","Алиса","Иван","Владимир","Тимофей","Михаил",
    "Диана","Александр","Арсений","София"
};

void demoOutput();
void randomOutput();
void inputOutput();
void rangePrint();
void iterationPrint();
void forLoopPrint();
void analyseGrades();
void printAvgGrade();
void printMedian();
double getMedianFromEvenVector(std::vector<int> input);
void printMode();
void cocktailSort(std::vector<int>& input);


std::vector<std::string> names = {};
std::vector<int> bals = {};

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");        // Изменение кодировки программы
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);              // Изменение кодировки консоли
    char* input = new char;

    while (true) {
        system("cls");
        printf("Выберите способ вывода данных:\n\n"
            "1. Демонстрационный анализ на предустановленных значениях.\n"
            "2. Анализ на случайных значениях\n"
            "3. Ввод и анализ значений\n\n"
            "Введите выбор и нажмите Enter: ");
        std::cin >> *input;                     // Принимаем выбор пользователя и записываем в переменную input

        if (!isdigit(*input)) continue;         // Если пользователь ввел что-то не то - запрашиваем повторно
        if (0 < ((int)*input - 48) < 4) break;  // Иначе - выходим из цикла ввода
    }

    int choice = (int)*input - 48;

    switch (choice) {
    case 1:
        demoOutput();
        break;
    case 2:
        randomOutput();
        break;
    case 3:
        inputOutput();
        break;
    }
    system("pause");        //ждём нажатия клавиши для завершения программы
}

void demoOutput() {
    names = { "Владислав", "Андрей", "Георгий", "София", "Александр", "Дмитрий", "Светлана", "Николай", "Мохаммед", "Алоис" }; // Предустановленные имена
    bals = { 38,83,41,48,32,50,26,52,50,65 }; // Предустановленные оценки

    rangePrint();     //range-based for-loop
    analyseGrades();
}

void randomOutput() {
    std::cout << "Введите размер выборки: ";
    int setSize = 1;
    std::cin >> setSize;

    for (int i = 0; i < setSize; i++) {
        names.push_back(nameList[rand() % nameList->size()]);
        bals.push_back(rand() % 101);             // Генерируем случайную оценку от 0 до 100
    }

    rangePrint();     //range-based for-loop
    analyseGrades();
}

void inputOutput() {

    printf("Введите значения в консоль.\n");
    printf("Вводить в формате [имя оценка], без квадратных скобок. Введите [0 0] без скобок для начала анализа.\n");

    std::string name;
    int grade;

    while (true) {
        std::cin >> name >> grade;
        if (name == "0" && grade == 0) break;
        names.push_back(name);
        bals.push_back(grade);
    }

    if (names.size() == 0 || bals.size() == 0) {
        printf("Не было введено значений, программа завершает работу...");
        return;
    }

    rangePrint();
    analyseGrades();
}

void rangePrint() { //range-based for-loop

    std::map<std::string, int> buffer;

    std::transform(names.begin(), names.end(), bals.begin(), std::inserter(buffer, buffer.end()), [](std::string a, int b) {
        return std::make_pair(a, b);
        });

    for (auto& [a, b] : buffer) std::cout << a << ' ' << b << '\n';
    std::cout << '\n';
}

void iterationPrint() {
    for (auto [n, g] = std::tuple{ names.begin(), bals.begin() }; n != names.end() && g != bals.end(); n++, g++)
        std::cout << *n << ' ' << *g << '\n';
    std::cout << '\n';
}

void forLoopPrint() {
    for (int i = 0; i < (((names.size()) < (bals.size())) ? (names.size()) : (bals.size())); i++)
        std::cout << names[i] << ' ' << bals[i] << '\n';
    std::cout << '\n';
}

void analyseGrades() {
    printAvgGrade();
    printMedian();
    printMode();
}

void printAvgGrade() {
    double avg = 0.0;
    for (auto i : bals) avg += (double)i;
    avg /= bals.size();
    std::cout << "Среднее значение оценок: " << avg << '\n';
}

void printMedian() {
    std::vector<int> sortedGrades = bals;
    cocktailSort(sortedGrades);

    double median = (sortedGrades.size() % 2 == 0) ?
        ((double)sortedGrades.at(sortedGrades.size() / 2) + (double)sortedGrades.at(sortedGrades.size() / 2 - 1)) / 2 :
        sortedGrades.at(std::floor(sortedGrades.size() / 2));
    std::cout << "Медиана: " << median << '\n';
}

void printMode() {
    std::unordered_map<int, int> gradesHashmap;
    for (auto i : bals) gradesHashmap[i] += 1;

    int maxFreq = 0;                             // Максимальная частота оценки
    for (auto& [a, b] : gradesHashmap)
        if (b > maxFreq)
            maxFreq = b;

    std::vector<int> freqGrades;                 //мода
    for (auto& [a, b] : gradesHashmap)
        if (b == maxFreq)
            freqGrades.push_back(a);

    std::cout << "Моды: ";
    for (auto i : freqGrades)
        std::cout << i << ' ';
    std::cout << '\n';
    std::cout << "Ученики, оценка которых соответствует моде (модам):\n";
    for (int i = 0; i < names.size(); i++) {
        if (std::find(freqGrades.begin(), freqGrades.end(), bals.at(i)) != freqGrades.end()) {
            std::cout << names.at(i) << ' ' << bals.at(i) << '\n';
        }
    }
}

//cocktail shaker sort

void cocktailSort(std::vector<int>& input)
{
    // флаг перестановки двух элементов
    bool swapped = true;
    // счетчик начальной позиции
    int start = 0;
    // счетчик конечной позиции
    int end = input.size() - 1;

    // цикл работает, пока мы можем переставлять элементы в векторе
    while (swapped) {
        // сбрасываем флаг при начале цикла, так как он может быть true после предыдущей итерации
        swapped = false;

        // проходим циклом слева направо, как в пузырьковой сортировке
        for (int i = start; i < end; ++i) {
            // если текущий элемент больше следующего
            if (input[i] > input[i + 1]) {
                // переставляем элементы
                std::swap(input[i], input[i + 1]);
                // и поднимаем флаг
                swapped = true;
            }
        }
        // если ни один элемент не был переставлен - вектор отсортирован
        if (!swapped)
            // без комментариев
            break;
        // иначе сбрасываем флаг и переходим к следующему этапу
        swapped = false;
        // сдвигаем указатель конца на один влево, так как самый правый элемент уже на месте
        --end;
        // ещё одна пузырьковая сортировка, но уже справа налево
        for (int i = end - 1; i >= start; --i) {
            // если текущий элемент больше следующего
            if (input[i] > input[i + 1]) {
                // переставляем элементы
                std::swap(input[i], input[i + 1]);
                // и поднимаем флаг
                swapped = true;
            }
        }
        // сдвигаем указатель начала на один вправо, так как самый левый элемент уже на месте
        ++start;
    }
}