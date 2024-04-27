#include <iostream>
#include <string>

using namespace std;

class BankAccount {
protected:
    string surname;
    string name;
    string lastTransactionDate;
    double depositAmount;

public:
    BankAccount(const string& surname, const string& name, const string& lastTransactionDate, double depositAmount)
        : surname(surname), name(name), lastTransactionDate(lastTransactionDate), depositAmount(depositAmount) {}

    void displayInfo() {
        cout << "Surname: " << surname << endl;
        cout << "Name: " << name << endl;
        cout << "Last Transaction Date: " << lastTransactionDate << endl;
        cout << "Deposit Amount: " << depositAmount << endl;
    }

    void addRecord(const string& newSurname, const string& newName, const string& newLastTransactionDate, double newDepositAmount) {
        surname = newSurname;
        name = newName;
        lastTransactionDate = newLastTransactionDate;
        depositAmount = newDepositAmount;
    }

    void deleteRecord() {
        surname = "";
        name = "";
        lastTransactionDate = "";
        depositAmount = 0.0;
    }
};

class SpecializedBankAccount : public BankAccount {
private:
    int specializedField1;
    int specializedField2;

public:
    SpecializedBankAccount(const string& surname, const string& name, const string& lastTransactionDate, double depositAmount, int field1, int field2)
        : BankAccount(surname, name, lastTransactionDate, depositAmount), specializedField1(field1), specializedField2(field2) {}

    void displayInfo() {
        BankAccount::displayInfo();
        cout << "Specialized Field 1: " << specializedField1 << endl;
        cout << "Specialized Field 2: " << specializedField2 << endl;
    }
};
int main() {
    // Створення об'єкта класу BankAccount
    BankAccount account1("Doe", "John", "2024-04-27", 1000.0);

    // Виведення інформації про рахунок
    cout << "Account 1 Info:" << endl;
    account1.displayInfo();
    cout << endl;

    // Додавання нового запису
    account1.addRecord("Doe", "Jane", "2024-04-28", 2000.0);

    // Виведення оновленої інформації про рахунок
    cout << "Updated Account 1 Info:" << endl;
    account1.displayInfo();
    cout << endl;

    // Видалення запису
    account1.deleteRecord();

    // Виведення після видалення
    cout << "Deleted Account 1 Info:" << endl;
    account1.displayInfo();
    cout << endl;

    // Створення об'єкта класу SpecializedBankAccount
    SpecializedBankAccount specializedAccount("Smith", "Alice", "2024-04-29", 3000.0, 10, 20);

    // Виведення інформації про спеціалізований рахунок
    cout << "Specialized Account Info:" << endl;
    specializedAccount.displayInfo();
    cout << endl;

    return 0;
}
