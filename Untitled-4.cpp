#include <iostream>
#include <string>
using namespace std;

int main() {
    int age;
    string name;

    // Ask for user's age
    cout << "Enter your age: ";
    cin >> age;

    // Important! This clears the leftover '\n' from the input buffer
    // Without this, getline() below will read an empty string
    cin.ignore();

    // Ask for full name using getline
    cout << "Enter your full name: ";
    getline(cin, name);

    // Show the result
    cout << "\n--- Result ---\n";
    cout << "Age: " << age << endl;
    cout << "Name: " << name << endl;

    return 0;
}

