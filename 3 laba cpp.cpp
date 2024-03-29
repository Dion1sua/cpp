
#include <iostream>    // ϳ��������� �������� ��������/���������
#include <vector>      // ϳ��������� �������� �������
#include <stdexcept>   // ϳ��������� �������� ��� ���������

using namespace std;  // ������������ �������� ���� std

class IntArray {  // ���������� ����� IntArray
private:
    vector<int> array;  // ������ ��� ��������� ������ ����� �����
    int lowerBound;     // ����� ���� ������
    int upperBound;     // ������ ���� ������

public:
    // ����������� ����� ��� ������������ ������ � �������� ������
    IntArray(int lower, int upper) : lowerBound(lower), upperBound(upper) {
        if (lower > upper) {  // �������� �� ����������� ���
            throw invalid_argument("����� ���� �� ���� ���� ������ �� ������");
        }
        array.resize(upper - lower + 1);  // ���� ������ �������
    }

    // �������������� �������� [] ��� ������� �� �������� ������
    int& operator[](int index) {
        if (index < lowerBound || index > upperBound) {  // �������� �� ����������� �������
            throw out_of_range("������ �� ������ ��������");
        }
        return array[index - lowerBound];  // ���������� ��������� �� �������
    }

    // �������������� �������� + ��� ��������� ������
    IntArray operator+(const IntArray& other) const {
        if (lowerBound != other.lowerBound || upperBound != other.upperBound) {  // �������� �� ����������� ���
            throw invalid_argument("������ ����� ���� ������� ���");
        }
        IntArray result(lowerBound, upperBound);  // ��������� ��'���� ��� ����������
        for (int i = lowerBound; i <= upperBound; ++i) {
            result[i] = array[i - lowerBound] + other.array[i - lowerBound];  // ��������� �������� ������
        }
        return result;  // ���������� ����������
    }

    // �������������� �������� - ��� ��������� ������
    IntArray operator-(const IntArray& other) const {
        if (lowerBound != other.lowerBound || upperBound != other.upperBound) {  // �������� �� ����������� ���
            throw invalid_argument("������ ����� ���� ������� ���");
        }
        IntArray result(lowerBound, upperBound);  // ��������� ��'���� ��� ����������
        for (int i = lowerBound; i <= upperBound; ++i) {
            result[i] = array[i - lowerBound] - other.array[i - lowerBound];  // ³�������� �������� ������
        }
        return result;  // ���������� ����������
    }

    // �������������� �������� * ��� �������� ������ �� ������
    IntArray operator*(int scalar) const {
        IntArray result(lowerBound, upperBound);  // ��������� ��'���� ��� ����������
        for (int i = lowerBound; i <= upperBound; ++i) {
            result[i] = array[i - lowerBound] * scalar;  // �������� ������� �������� �� ������
        }
        return result;  // ���������� ����������
    }

    // �������������� �������� / ��� ������ ������ �� ������
    IntArray operator/(int scalar) const {
        if (scalar == 0) {  // �������� �� ������ �� ����
            throw invalid_argument("ĳ����� �� ����");
        }
        IntArray result(lowerBound, upperBound);  // ��������� ��'���� ��� ����������
        for (int i = lowerBound; i <= upperBound; ++i) {
            result[i] = array[i - lowerBound] / scalar;  // ĳ����� ������� �������� �� ������
        }
        return result;  // ���������� ����������
    }

    // ����� ��� ������ �������� ������ �� ��������
    void printElement(int index) const {
        if (index < lowerBound || index > upperBound) {  // �������� �� ����������� �������
            throw out_of_range("������ �� ������ ��������");
        }
        cout << "������� � �������� " << index << ": " << array[index - lowerBound] << endl;  // ���� ��������
    }

    // ����� ��� ������ ������ ������
    void printArray() const {
        cout << "�������� ������:" << endl;
        for (int i = lowerBound; i <= upperBound; ++i) {
            cout << array[i - lowerBound] << " ";  // ���� ������� ��������
        }
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ukr");
    try {
        IntArray arr1(-1, 2);  // ��������� ��'���� ������ arr1
        arr1[-1] = 1;          // ��������� ������� ��������� ������
        arr1[0] = 2;
        arr1[1] = 3;
        arr1[2] = 4;

        IntArray arr2(-1, 2);  // ��������� ��'���� ������ arr2
        arr2[-1] = 2;          // ��������� ������� ��������� ������
        arr2[0] = 4;
        arr2[1] = 6;
        arr2[2] = 8;

        IntArray sum = arr1 + arr2;       // ��������� ������
        sum.printArray();                 // ���� ����������

        IntArray difference = arr1 - arr2; // ³�������� ������
        difference.printArray();           // ���� ����������

        IntArray scaled = arr1 * 2;    // �������� ������ �� ������
        scaled.printArray();           // ���� ����������

        IntArray quotient = arr1 / 2;  // ĳ����� ������ �� ������
        quotient.printArray();         // ���� ����������

        arr1.printElement(0);  // ���� �������� ������ �� ��������
        arr1.printArray();     // ���� ������ ������
    }
    catch (const exception& e) {
        cerr << "�������: " << e.what() << endl;  // ���� ����������� ��� �������
    }

    return 0;  // ���������� �������� 0, �� ����� �� ������ ���������� ��������
}
