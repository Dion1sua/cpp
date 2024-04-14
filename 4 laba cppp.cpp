#include <iostream>
#include <string>

using namespace std;

class Transport {
protected:
    string fuelType;

public:
    Transport(string fuelType) : fuelType(fuelType) {}

    void accelerate() {
        cout << "Transport is accelerating." << endl;
    }

    void brake() {
        cout << "Transport is braking." << endl;
    }
};

class Bus : public Transport {
private:
    int capacity;
    int year;
    string manufacturer;

public:
    Bus(string fuelType, int capacity, int year, string manufacturer)
        : Transport(fuelType), capacity(capacity), year(year), manufacturer(manufacturer) {}

    void setManufacturer(string manuf) {
        manufacturer = manuf;
    }

    string getManufacturer() const {
        return manufacturer;
    }

    int getCapacity() const {
        return capacity;
    }

    void setCapacity(int cap) {
        capacity = cap;
    }

    int getYear() const {
        return year;
    }

    void setYear(int yr) {
        year = yr;
    }

    void displayInfo() const {
        cout << "Bus information:" << endl;
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Year: " << year << endl;
        cout << "Manufacturer: " << manufacturer << endl;
    }
};

int main() {
    string fuelType, manufacturer;
    int capacity, year;

    cout << "Enter the fuel type: ";
    cin >> fuelType;

    cout << "Enter the capacity: ";
    cin >> capacity;

    cout << "Enter the year: ";
    cin >> year;

    cout << "Enter the manufacturer: ";
    cin >> manufacturer;

    Bus myBus(fuelType, capacity, year, manufacturer);

    myBus.accelerate();
    myBus.brake();

    myBus.displayInfo();

    return 0;
}
