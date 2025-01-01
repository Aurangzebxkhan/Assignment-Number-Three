#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Structure to store book details
struct Book {
    int bookID;
    string title;
    string author;
    int quantity;
};

// Function prototypes
void loadInventory(vector<Book>& books, const string& filename);
void saveInventory(const vector<Book>& books, const string& filename);
void addBook(vector<Book>& books);
void searchBook(const vector<Book>& books);
void displayBooks(const vector<Book>& books);

int main() {
    vector<Book> books;
    const string filename = "library_inventory.txt";

    // Load inventory from file
    loadInventory(books, filename);

    int choice;
    do {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add a new book" << endl;
        cout << "2. Search for a book" << endl;
        cout << "3. Display all books" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(books);
                break;
            case 2:
                searchBook(books);
                break;
            case 3:
                displayBooks(books);
                break;
            case 4:
                saveInventory(books, filename);
                cout << "Exiting... Inventory saved." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

void loadInventory(vector<Book>& books, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "No existing inventory found. Starting fresh." << endl;
        return;
    }

    Book book;
    while (file >> book.bookID) {
        file.ignore(); // Skip newline
        getline(file, book.title);
        getline(file, book.author);
        file >> book.quantity;
        books.push_back(book);
    }
    file.close();
}

void saveInventory(const vector<Book>& books, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error saving inventory." << endl;
        return;
    }

    for (const auto& book : books) {
        file << book.bookID << endl;
        file << book.title << endl;
        file << book.author << endl;
        file << book.quantity << endl;
    }
    file.close();
}

void addBook(vector<Book>& books) {
    Book newBook;
    cout << "Enter Book ID: ";
    cin >> newBook.bookID;
    cin.ignore(); // Ignore newline
    cout << "Enter Title: ";
    getline(cin, newBook.title);
    cout << "Enter Author: ";
    getline(cin, newBook.author);
    cout << "Enter Quantity: ";
    cin >> newBook.quantity;

    books.push_back(newBook);
    cout << "Book added successfully!" << endl;
}

void searchBook(const vector<Book>& books) {
    int option;
    cout << "Search by: 1. Book ID 2. Title: ";
    cin >> option;
    cin.ignore(); // Ignore newline

    if (option == 1) {
        int id;
        cout << "Enter Book ID: ";
        cin >> id;

        for (const auto& book : books) {
            if (book.bookID == id) {
                cout << "\nBook Found:\n";
                cout << "ID: " << book.bookID << endl;
                cout << "Title: " << book.title << endl;
                cout << "Author: " << book.author << endl;
                cout << "Quantity: " << book.quantity << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    } else if (option == 2) {
        string title;
        cout << "Enter Title: ";
        getline(cin, title);

        for (const auto& book : books) {
            if (book.title == title) {
                cout << "\nBook Found:\n";
                cout << "ID: " << book.bookID << endl;
                cout << "Title: " << book.title << endl;
                cout << "Author: " << book.author << endl;
                cout << "Quantity: " << book.quantity << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    } else {
        cout << "Invalid option." << endl;
    }
}

void displayBooks(const vector<Book>& books) {
    if (books.empty()) {
        cout << "No books in inventory." << endl;
        return;
    }

    cout << left << setw(10) << "Book ID" << setw(30) << "Title" << setw(20) << "Author" << setw(10) << "Quantity" << endl;
    cout << string(70, '-') << endl;
    for (const auto& book : books) {
        cout << left << setw(10) << book.bookID << setw(30) << book.title << setw(20) << book.author << setw(10) << book.quantity << endl;
    }
}