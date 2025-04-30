#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int pages;

public:
    // Constructor
    Book(string t = "Untitled", string a = "Unknown", int p = 0) {
        title = t;
        author = a;
        pages = p;
    }

    // Destructor
    ~Book() {
        cout << "Destroying Book: " << title << endl;
    }

    // Display info
    void display() const {
        cout << "Title: " << title << ", Author: " << author << ", Pages: " << pages << endl;
    }
};

class BookShelf {
private:
    Book* books;
    int size;

public:
    // Constructor
    BookShelf(int s) {
        size = s;
        books = new Book[size];

        for (int i = 0; i < size; ++i) {
            string t, a;
            int p;

            cout << "Enter title of book " << i + 1 << ": ";
            getline(cin, t);
            cout << "Enter author of book " << i + 1 << ": ";
            getline(cin, a);
            cout << "Enter number of pages: ";
            cin >> p;
            cin.ignore();  // To consume leftover '\n'

            books[i] = Book(t, a, p);
        }
    }

    // Destructor
    ~BookShelf() {
        delete[] books;
        cout << "BookShelf destroyed and memory released." << endl;
    }

    // Display all books
    void displayBooks() const {
        for (int i = 0; i < size; ++i) {
            cout << "Book " << i + 1 << ": ";
            books[i].display();
        }
    }
};

int main() {
    int count;
    cout << "How many books do you want to add? ";
    cin >> count;
    cin.ignore(); // Clear input buffer

    BookShelf shelf(count);
    cout << "\nBooks on the shelf:\n";
    shelf.displayBooks();

    return 0;
}
// Advantages:
// - Organized structure: separating data (Book) and collection (BookShelf) improves readability and maintenance.
// - Dynamic memory allocation allows the program to handle any number of books at runtime.
// - Using functions like display() makes the code modular and reusable.

// Disadvantages:
// - Manual memory management using new/delete increases the risk of memory leaks if not handled properly.
// - Requires careful use of cin.ignore() to handle input correctly.
// - Without proper destructor, dynamically allocated memory will not be released automatically.
