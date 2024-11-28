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

