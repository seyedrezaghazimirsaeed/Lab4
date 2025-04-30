#include <iostream>
#include <string>
using namespace std;

// Base class
class Car {
protected:
    string model;
    int year;
    float price;

public:
    Car() {
        model = "";
        year = 0;
        price = 0.0;
    }

    virtual ~Car() {
        cout << "Destroying Car: " << model << endl;
    }

    void inputBasic() {
        cout << "Enter model: ";
        getline(cin, model);
        cout << "Enter year: ";
        cin >> year;
        cout << "Enter price: ";
        cin >> price;
        cin.ignore(); // Clear newline
    }

    void displayBasic() const {
        cout << "Model: " << model << ", Year: " << year << ", Price: " << price << " EUR" << endl;
    }
};

// Derived class - Electric
class ElectricCar : public Car {
private:
    float batterySize;

public:
    void input() {
        inputBasic();
        cout << "Enter battery size (kWh): ";
        cin >> batterySize;
        cin.ignore();
    }

    void display() const {
        displayBasic();
        cout << "Battery Size: " << batterySize << " kWh" << endl;
    }
};

// Derived class - Gas
class GasCar : public Car {
private:
    float fuelCapacity;

public:
    void input() {
        inputBasic();
        cout << "Enter fuel capacity (liters): ";
        cin >> fuelCapacity;
        cin.ignore();
    }

    void display() const {
        displayBasic();
        cout << "Fuel Capacity: " << fuelCapacity << " liters" << endl;
    }
};

// Derived class - Hybrid
class HybridCar : public Car {
private:
    float batterySize;
    float fuelCapacity;

public:
    void input() {
        inputBasic();
        cout << "Enter battery size (kWh): ";
        cin >> batterySize;
        cout << "Enter fuel capacity (liters): ";
        cin >> fuelCapacity;
        cin.ignore();
    }

    void display() const {
        displayBasic();
        cout << "Battery Size: " << batterySize << " kWh, Fuel Capacity: " << fuelCapacity << " liters" << endl;
    }
};

int main() {
    int n;
    cout << "How many cars do you want to enter? ";
    cin >> n;
    cin.ignore();

    Car** cars = new Car*[n];
    int* types = new int[n]; // 1: Electric, 2: Gas, 3: Hybrid

    for (int i = 0; i < n; ++i) {
        int type;
        cout << "\nEnter type for car " << i + 1 << " (1 = Electric, 2 = Gas, 3 = Hybrid): ";
        cin >> type;
        cin.ignore();

        types[i] = type;

        if (type == 1) {
            ElectricCar* e = new ElectricCar();
            e->input();
            cars[i] = e;
        } else if (type == 2) {
            GasCar* g = new GasCar();
            g->input();
            cars[i] = g;
        } else if (type == 3) {
            HybridCar* h = new HybridCar();
            h->input();
            cars[i] = h;
        } else {
            cout << "Invalid type. Skipping this car." << endl;
            cars[i] = nullptr;
        }
    }

    // Display all cars
    cout << "\n--- Car Details ---\n";
    for (int i = 0; i < n; ++i) {
        if (cars[i] != nullptr) {
            cout << "Car " << i + 1 << ":\n";
            if (types[i] == 1)
                static_cast<ElectricCar*>(cars[i])->display();
            else if (types[i] == 2)
                static_cast<GasCar*>(cars[i])->display();
            else if (types[i] == 3)
                static_cast<HybridCar*>(cars[i])->display();
            cout << endl;
        }
    }

    // Clean up
    for (int i = 0; i < n; ++i) {
        delete cars[i];
    }
    delete[] cars;
    delete[] types;

    cout << "\nAll memory released. Program finished.\n";
    return 0;
}
