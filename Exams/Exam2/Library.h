#include <iostream>
#include <string>
using namespace std;
class Library : public  Reader{
    private:
    string bookName;
    bool isBorrowed;

    public:

    void borrowBook() {
        Library(string readerName, string readerId, string bookName, bool status) : Readder(readerName, readerId ), bookName(bookName), isBorrowed(status){}
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
