
#include <iostream>    // Підключення бібліотеки введення/виведення
#include <vector>      // Підключення бібліотеки векторів
#include <stdexcept>   // Підключення бібліотеки для виключень

using namespace std;  // Використання простору імен std

class IntArray {  // Оголошення класу IntArray
private:
    vector<int> array;  // Вектор для зберігання масиву цілих чисел
    int lowerBound;     // Нижня межа масиву
    int upperBound;     // Верхня межа масиву

public:
    // Конструктор класу для ініціалізації масиву з заданими межами
    IntArray(int lower, int upper) : lowerBound(lower), upperBound(upper) {
        if (lower > upper) {  // Перевірка на коректність меж
            throw invalid_argument("Нижня межа не може бути більшою за верхню");
        }
        array.resize(upper - lower + 1);  // Зміна розміру вектору
    }

    // Перевантажений оператор [] для доступу до елементів масиву
    int& operator[](int index) {
        if (index < lowerBound || index > upperBound) {  // Перевірка на коректність індексу
            throw out_of_range("Індекс за межами діапазону");
        }
        return array[index - lowerBound];  // Повернення посилання на елемент
    }

    // Перевантажений оператор + для додавання масивів
    IntArray operator+(const IntArray& other) const {
        if (lowerBound != other.lowerBound || upperBound != other.upperBound) {  // Перевірка на коректність меж
            throw invalid_argument("Масиви мають мати однакові межі");
        }
        IntArray result(lowerBound, upperBound);  // Створення об'єкту для результату
        for (int i = lowerBound; i <= upperBound; ++i) {
            result[i] = array[i - lowerBound] + other.array[i - lowerBound];  // Додавання елементів масивів
        }
        return result;  // Повернення результату
    }

    // Перевантажений оператор - для віднімання масивів
    IntArray operator-(const IntArray& other) const {
        if (lowerBound != other.lowerBound || upperBound != other.upperBound) {  // Перевірка на коректність меж
            throw invalid_argument("Масиви мають мати однакові межі");
        }
        IntArray result(lowerBound, upperBound);  // Створення об'єкту для результату
        for (int i = lowerBound; i <= upperBound; ++i) {
            result[i] = array[i - lowerBound] - other.array[i - lowerBound];  // Віднімання елементів масивів
        }
        return result;  // Повернення результату
    }

    // Перевантажений оператор * для множення масиву на скаляр
    IntArray operator*(int scalar) const {
        IntArray result(lowerBound, upperBound);  // Створення об'єкту для результату
        for (int i = lowerBound; i <= upperBound; ++i) {
            result[i] = array[i - lowerBound] * scalar;  // Множення кожного елементу на скаляр
        }
        return result;  // Повернення результату
    }

    // Перевантажений оператор / для ділення масиву на скаляр
    IntArray operator/(int scalar) const {
        if (scalar == 0) {  // Перевірка на ділення на нуль
            throw invalid_argument("Ділення на нуль");
        }
        IntArray result(lowerBound, upperBound);  // Створення об'єкту для результату
        for (int i = lowerBound; i <= upperBound; ++i) {
            result[i] = array[i - lowerBound] / scalar;  // Ділення кожного елементу на скаляр
        }
        return result;  // Повернення результату
    }

    // Метод для виводу елемента масиву за індексом
    void printElement(int index) const {
        if (index < lowerBound || index > upperBound) {  // Перевірка на коректність індексу
            throw out_of_range("Індекс за межами діапазону");
        }
        cout << "Елемент з індексом " << index << ": " << array[index - lowerBound] << endl;  // Вивід елемента
    }

    // Метод для виводу всього масиву
    void printArray() const {
        cout << "Елементи масиву:" << endl;
        for (int i = lowerBound; i <= upperBound; ++i) {
            cout << array[i - lowerBound] << " ";  // Вивід кожного елемента
        }
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ukr");
    try {
        IntArray arr1(-1, 2);  // Створення об'єкту масиву arr1
        arr1[-1] = 1;          // Присвоєння значень елементам масиву
        arr1[0] = 2;
        arr1[1] = 3;
        arr1[2] = 4;

        IntArray arr2(-1, 2);  // Створення об'єкту масиву arr2
        arr2[-1] = 2;          // Присвоєння значень елементам масиву
        arr2[0] = 4;
        arr2[1] = 6;
        arr2[2] = 8;

        IntArray sum = arr1 + arr2;       // Додавання масивів
        sum.printArray();                 // Вивід результату

        IntArray difference = arr1 - arr2; // Віднімання масивів
        difference.printArray();           // Вивід результату

        IntArray scaled = arr1 * 2;    // Множення масиву на скаляр
        scaled.printArray();           // Вивід результату

        IntArray quotient = arr1 / 2;  // Ділення масиву на скаляр
        quotient.printArray();         // Вивід результату

        arr1.printElement(0);  // Вивід елемента масиву за індексом
        arr1.printArray();     // Вивід всього масиву
    }
    catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;  // Вивід повідомлення про помилку
    }

    return 0;  // Повернення значення 0, що вказує на успішне завершення програми
}
