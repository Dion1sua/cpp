#include <iostream>
using namespace std;

template <typename T>
T calculateSum(T n) {
    T sum = 0;
    for (T i = 20; i <= (2 * n - 1); ++i) {
        sum += i;
    }
    return sum;
}
int main() {    
    setlocale(LC_ALL, "ukr");
    int n;
    cout << "Введіть натуральне число n: ";
    cin >> n;
    int result = calculateSum(n);
    cout << "Сума послідовності чисел: " << result << std::endl;

    return 0;
}
