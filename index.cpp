#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Manages book-related operations
class BookManager {
    vector<string> books;
public:
    void addBook(const string& book) {
        books.push_back(book);
        cout << "Book \"" << book << "\" added to the library.\n";
    }

    void displayBooks() {
        cout << "Books in Library:\n";
        for (const string& book : books) {
            cout << "- " << book << endl;
        }
    }
};

// Validates user input
class InputValidator {
public:
    bool validateBookName(const string& bookName) {
        if (bookName.empty()) {
            cout << "Error: Book name cannot be empty.\n";
            return false;
        }
        return true;
    }
};

// Handles notifications
class NotificationSender {
public:
    void sendNotification(const string& message) {
        cout << "Notification: " << message << endl;
    }
};

// Base class for searching books
class BookSearch {
public:
    virtual void searchBook(const string& bookName, const vector<string>& books) = 0; // Pure virtual function
};

// Derived class for exact match search
class ExactMatchSearch : public BookSearch {
public:
    void searchBook(const string& bookName, const vector<string>& books) override {
        for (const string& book : books) {
            if (book == bookName) {
                cout << "Book \"" << bookName << "\" found in the library.\n";
                return;
            }
        }
        cout << "Book \"" << bookName << "\" not found.\n";
    }
};

// Derived class for partial match search
class PartialMatchSearch : public BookSearch {
public:
    void searchBook(const string& bookName, const vector<string>& books) override {
        for (const string& book : books) {
            if (book.find(bookName) != string::npos) {
                cout << "Book \"" << book << "\" matches the search.\n";
                return;
            }
        }
        cout << "No books matching \"" << bookName << "\" found.\n";
    }
};

void performSearch(BookSearch* searchStrategy, const string& bookName, const vector<string>& books) {
    searchStrategy->searchBook(bookName, books);
}

int main() {
    BookManager bookManager;
    InputValidator validator;
    NotificationSender notifier;

    // Adding books
    string book1 = "C++ Programming";
    string book2 = "Design Patterns in C++";
    string book3 = "SOLID Principles";
    
    if (validator.validateBookName(book1)) bookManager.addBook(book1);
    if (validator.validateBookName(book2)) bookManager.addBook(book2);
    if (validator.validateBookName(book3)) bookManager.addBook(book3);

    bookManager.displayBooks();

    // Notifications
    notifier.sendNotification("A new book has been added to the library!");

    // Searching for books (OCP and LSP demonstration)
    vector<string> books = {book1, book2, book3};

    ExactMatchSearch exactSearch;
    PartialMatchSearch partialSearch;

    cout << "\n--- Exact Search ---\n";
    performSearch(&exactSearch, "C++ Programming", books);

    cout << "\n--- Partial Search ---\n";
    performSearch(&partialSearch, "Design", books);

    return 0;
}
