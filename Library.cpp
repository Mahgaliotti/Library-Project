#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;
 
public:
    void setBookDetails(string t, string a, string i, bool avail) {
        title = t;
        author = a;
        isbn = i;
        available = avail;
    }

    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Availability: " << (available ? "Available" : "Borrowed") << endl;
        cout << "---------------------------" << endl;
    }

    bool borrowBook() {
        if (available) {
            available = false;
            return true;
        }
        return false;
    }

    void returnBook() {
        available = true;
    }

    string getISBN() {
        return isbn;
    }

    bool isAvailable() {
        return available;
    }
};

int main() {
    Book library[5];

    // Initializing books available in the system
    library[0].setBookDetails("Freakonomics", "Steven D. Levitt & Stephen J. Dubner", "006073132X", true);
    library[1].setBookDetails("The Drunkard's Walk", "Leonard Mlodinow", "8535916814", true);
    library[2].setBookDetails("The Wealth of Nations", "Adam Smith", "8572329226", true);
    library[3].setBookDetails("Crash: A Brief History of the Economy", "Alexandre Versignassi", "8577020487", false); // already borrowed
    library[4].setBookDetails("Capital in the Twenty-First Century", "Thomas Piketty", "853591126X", true);

    string inputISBN;
    cout << "=== Alex's Library ===" << endl;

    while (true) {
        cout << "\nAvailable books:\n";
        for (int i = 0; i < 5; i++) {
            library[i].displayBookDetails();
        }

        cout << "Enter the ISBN of the book you want to borrow (or 0 to exit): ";
        getline(cin, inputISBN);

        if (inputISBN == "0") {
            cout << "System closed. See you next time!" << endl;
            break;
        }

        bool found = false;
        for (int i = 0; i < 5; i++) {
            if (library[i].getISBN() == inputISBN) {
                found = true;
                if (library[i].isAvailable()) {
                    library[i].borrowBook();
                    cout << "Book borrowed successfully! :)" << endl;
                }
                else {
                    cout << "This book is already borrowed. :(" << endl;
                }
                break;
            }
        }

        if (!found) {
            cout << "Oh no. Book with ISBN " << inputISBN << " not found." << endl;
        }
    }

    return 0;
}
