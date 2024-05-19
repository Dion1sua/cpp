#include <iostream>
#include <deque>
#include <string>
using namespace std;

class Garage {
private:
    deque<string> parkingLine;

public:
    void arrive(const string& car) {
        parkingLine.push_back(car);
        cout << "Car " << car << " has arrived." << endl;
    }

    void depart(const string& car) {
        deque<string> tempLine;
        bool found = false;

        while (!parkingLine.empty()) {
            if (parkingLine.front() == car) {
                found = true;
                parkingLine.pop_front();
                cout << "Car " << car << " has departed." << endl;
                break;
            }
            else {
                tempLine.push_back(parkingLine.front());
                parkingLine.pop_front();
            }
        }

        while (!tempLine.empty()) {
            parkingLine.push_front(tempLine.back());
            tempLine.pop_back();
        }

        if (!found) {
            cout << "Car " << car << " is not in the garage." << endl;
        }
    }

    void checkCar(const string& car) {
        for (const auto& parkedCar : parkingLine) {
            if (parkedCar == car) {
                cout << "Car " << car << " is in the garage." << endl;
                return;
            }
        }
        cout << "Car " << car << " is not in the garage." << endl;
    }

    void display() {
        cout << "Current state of the garage: ";
        for (const auto& car : parkingLine) {
            cout << car << " ";
        }
        cout << endl;
    }
};

int main() {
    Garage garage;
    garage.arrive("Car1");
    garage.arrive("Car2");
    garage.arrive("Car3");
    garage.display();

    garage.depart("Car2");
    garage.display();

    garage.checkCar("Car1");
    garage.checkCar("Car2");
    garage.checkCar("Car3");

    return 0;
}
