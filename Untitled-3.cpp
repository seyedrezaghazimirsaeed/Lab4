#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string model;
    int year;
    float price;

public:
    // Constructor
    Car(string m = "", int y = 0, float p = 0.0) {
        model = m;
        year = y;
        price = p;
    }

    // Destructor
    ~Car() {
        cout << "Car destroyed: " << model << endl;
    }

    // Display car info
    void display() const {
        cout << "Model: " << model << ", Year: " << year << ", Price: " << price << " EUR" << endl;
    }
};

class CarCollection {
private:
    Car* cars;
    int size;

public:
    // Constructor
    CarCollection() {
        cout << "How many cars do you want to enter? ";
        cin >> size;
        cin.ignore(); // Clear newline

        cars = new Car[size];

        for (int i = 0; i < size; ++i) {
            string model;
            int year;
            float price;

            cout << "\nEnter model of car " << i + 1 << ": ";
            getline(cin, model);

            cout << "Enter year: ";
            cin >> year;

            cout << "Enter price (EUR): ";
            cin >> price;
            cin.ignore(); // Clear newline

            cars[i] = Car(model, year, price);
        }
    }

    // Destructor
    ~CarCollection() {
        delete[] cars;
        cout << "CarCollection destroyed and memory released." << endl;
    }

    // Display all cars
    void displayCars() const {
        cout << "\nList of all cars:\n";
        for (int i = 0; i < size; ++i) {
            cout << "Car " << i + 1 << ": ";
            cars[i].display();
        }
    }
};

int main() {
    CarCollection collection;
    collection.displayCars();

    return 0;
}
