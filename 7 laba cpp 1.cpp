#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric> // Додаємо цей заголовок для std::accumulate

using namespace std;

template<typename T>
class ArrayContainer {
private:
    vector<T> data;

public:
    ArrayContainer(const vector<T>& input) : data(input) {}

    T minAbsElement() {
        if (data.empty()) throw runtime_error("Array is empty.");
        return *min_element(data.begin(), data.end(), [](T a, T b) {
            return abs(a) < abs(b);
            });
    }

    T sumAfterFirstZero() {
        auto it = find(data.begin(), data.end(), 0);
        if (it == data.end() || it + 1 == data.end()) return 0;
        return accumulate(it + 1, data.end(), 0, [](T sum, T val) {
            return sum + abs(val);
            });
    }

    void transformArray() {
        vector<T> evenPos, oddPos;
        for (size_t i = 0; i < data.size(); ++i) {
            if (i % 2 == 0) {
                evenPos.push_back(data[i]);
            }
            else {
                oddPos.push_back(data[i]);
            }
        }
        copy(evenPos.begin(), evenPos.end(), data.begin());
        copy(oddPos.begin(), oddPos.end(), data.begin() + evenPos.size());
    }

    void printArray() const {
        for (const auto& elem : data) {
            cout << elem << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> vec = { 3, -7, 0, 4, 6, -1, 0, 5, -9 };
    ArrayContainer<int> container(vec);

    try {
        cout << "Min abs element: " << container.minAbsElement() << endl;
        cout << "Sum after first zero: " << container.sumAfterFirstZero() << endl;

        container.transformArray();
        cout << "Transformed array: ";
        container.printArray();
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
