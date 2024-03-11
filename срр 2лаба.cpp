#include <iostream>
using namespace std;

void calculateSumWithPointers(int n, int* sum) {
    *sum = 0;
    for (int i = 20; i <= (2 * n - 1); ++i) {
        *sum += i;
    }
}
int calculateSumWithExternalVariable(int n) {
    int sum = 0;
    for (int i = 20; i <= (2 * n - 1); ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    setlocale(LC_ALL, "ukr");
    int n;
    cout << "Введіть натуральне число n: ";
    cin >> n;

    int sumWithPointers;
    calculateSumWithPointers(n, &sumWithPointers);
    cout << "Сума послідовності чисел за допомогою параметрів-вказівників: " << sumWithPointers << endl;
    int sumWithExternalVariable = calculateSumWithExternalVariable(n);
    cout << "Сума послідовності чисел за допомогою зовнішньої змінної: " << sumWithExternalVariable << endl;

    return 0;
}
