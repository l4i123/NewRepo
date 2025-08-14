#include <iostream>
#include <string>
using namespace std;

class Reader {
private:
    string name;
    string id;

public:
    Reader(string n, string id) : name(n), id(id) {}

    // Function to display reader info
    void displayReaderInfo() const {
        cout << "Reader Name: " << name << ", ID: " << id << endl;
    }
};

class Library : public Reader {
private:
    string bookName;
    bool isBorrowed;

public:
    // Constructor for Library
    Library(string readerName, string readerId, string bookName, bool status)
        : Reader(readerName, readerId), bookName(bookName), isBorrowed(status) {}

    void borrowBook() {
        if (!isBorrowed) {
            isBorrowed = true;
            cout << "The book '" << bookName << "' has been borrowed." << endl;
        } else {
            cout << "The book '" << bookName << "' is already borrowed." << endl;
        }
    }

    bool isBookBorrowed() const {
        return isBorrowed;
    }

    void displayBookInfo() const {
        cout << "Book Name: " << bookName << ", Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
    }

    string getBookName() const {
        return bookName;
    }

    bool getStatus() const {
        return isBorrowed;
    }
};

int main() {
    // Defining an array of Library objects
    Library books[] = {
        Library("Alice", "1", "The Great Gatsby", false),
        Library("Bob", "2", "1984", true),
        Library("Charlie", "3", "To Kill a Mockingbird", false),
        Library("Diana", "4", "Moby Dick", true)
    };

    int size = sizeof(books) / sizeof(books[0]);

    // Display books with status 'Available'
    cout << "Books with status 'Available':\n";
    for (int i = 0; i < size; ++i) {
        if (!books[i].getStatus()) {
            books[i].displayBookInfo();
        }
    }

    return 0;
}
