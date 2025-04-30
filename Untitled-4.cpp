#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int age;

    cout << "Enter your age: ";
    cin >> age;

    // Uncomment the line below to see the correct behavior
    // cin.ignore();

    cout << "Enter your full name: ";
    getline(cin, name);

    cout << "\n--- Result ---\n";
    cout << "Age: " << age << endl;
    cout << "Name: " << name << endl;

    return 0;
}
