// Develop a Basic Library Management System with CRUD Operations
// Build a simple command-line based library management system that allows users to manage books using basic CRUD (Create, Read, Update, Delete) operations directly within the application.A library has multiple books and each book has a title, author, and ISBN number. The library wants to keep track of the books that are currently available and the books that have been borrowed by the members. Design a program using OOPs and class and object to implement this scenario.
#include<iostream>
#include<string>
using namespace std;
int n;
class Book {
    string title, author;
    int isbn;
    bool status;
    public:
        void get() {
            cout << "Enter Title : ";
            cin.ignore();
            getline(cin,title);
            cout << "Enter Author : ";
            cin.ignore();
            getline(cin,author);
            cout << "Enter ISBN : ";
            cin >> isbn;
            status = true;
        }
        void display() {
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "ISBN: " << isbn << endl;
            cout << "Status : " << (status ? "Available" : "Borrowed") << endl;
        }
        void update() {
            status = (status ? false : true);
        }
        bool available() {
            return status;
        }
        int bookid() {
            return isbn;
        }
};
class Library: public Book {
    Book B[100];
    public:
        Library(int n) {
            for (int i = 0; i < n; i++) {
                cout << endl << "Book " << i + 1 << " Details : " << endl;
                B[i].get();
            }
        }
        void addBook() {            
            cout << endl << "Enter Book Details : " << endl;
            B[n].get();
            cout << endl << "Book Added Successfully" << endl;
            B[n].display();
            n++;
        }
        void removeBook() {
            int num;
            cout << endl << "Enter Book ISBN Number to Remove : ";
            cin >> num;
            for (int i = 0; i < n; i++) {
                if (B[i].bookid() == num) {   
                    B[i].display(); 
                    cout << endl << "Book Removed Successfully" << endl;                  
                    for (int j = i; j < n; j++) {
                        B[j] = B[j + 1];
                    }
                    break;
                }
            }
            n--;
        }
        void displayAll() {
            for (int i = 0; i < n; i++) {
                cout << endl << "Book " << i + 1 << " Details : " << endl;
                B[i].display();
            }
            cout << endl << "Total Books : " << n << endl;
        }
        void displayAvailable() {
            int cnt=0;
            for (int i = 0; i < n; i++) {
                if (B[i].available()) {
                    cout << endl << "Book " << i + 1 << " Details : " << endl;
                    B[i].display();
                    cnt++;
                }
            }
            cout << endl << "Total Available Books : " << cnt << endl;
        }
        void displayBorrowed() {
            int cnt=0;
            for (int i = 0; i < n; i++) {
                if (!B[i].available()) {
                    cout << endl << "Book " << i + 1 << " Details : " << endl;
                    B[i].display();
                    cnt++;
                }
            }
            cout << endl << "Total Borrowed Books : " << cnt << endl;
        }
        void borrowBook() {
            int num;
            cout << endl << "Enter Book Number to Borrow : ";
            cin >> num;
            for (int i = 0; i < n; i++) {
                if (B[i].bookid() == num) { 
                    if (B[i].available()) {
                        B[i].update();
                        cout << endl << "Book Borrowed" << endl;
                    } else {
                        cout << endl << "Book Already Borrowed" << endl;
                    }
                    cout << endl;
                    B[i].display();
                    break;
                }
                if (i == n - 1) {
                    cout << endl << "Book Not Found" << endl;
                }
            }
        }
        void returnBook() {
            int num;
            cout << endl << "Enter Book Number to Return : ";
            cin >> num;
            for (int i = 0; i < n; i++) {
                if (B[i].bookid() == num) { 
                    if (!B[i].available()) {
                        B[i].update();
                        cout << endl << "Book Returned" << endl;
                    } else {
                        cout << endl << "Book Already Available" << endl;
                    }
                    cout << endl;
                    B[i].display();
                    break;
                }
                if (i == n - 1) {
                    cout << endl << "Book Not Found" << endl;
                }
            }
        }
};
main() {
    int opt=0;
    cout << "Enter Number of Books : ";
    cin >> n;
    Library lib(n);
    cout << endl << "-------------------------" << endl;
    cout << endl << "Menu Option : " << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Remove Book" << endl;
    cout << "3. Display All Books" << endl;
    cout << "4. Display Available Books" << endl;
    cout << "5. Display Borrowed Books" << endl;
    cout << "6. Borrow Book" << endl;
    cout << "7. Return Book" << endl;
    cout << "8. Exit" << endl;
    do {
        cout << endl << "-------------------------" << endl;
        cout << endl << "Select Option Number : ";
        cin >> opt;
        switch(opt) {
            case 1:
                lib.addBook();
                break;
            case 2:
                lib.removeBook();
                break;
            case 3:
                lib.displayAll();
                break;
            case 4:
                lib.displayAvailable();
                break;
            case 5:
                lib.displayBorrowed();
                break;
            case 6:
                lib.borrowBook();
                break;
            case 7:
                lib.returnBook();
                break;
            case 8:
                break;
            default:
                cout << endl << "Invalid Option" << endl;
        }
    } while (opt != 8);
    cout << endl << "Exit Successfully" << endl;
}