#include <iostream>
using namespace std;
struct book{
    int bookId = -1;
    string bookName = "";
    string authorName = "";
    double bookPrice = 0.0;
    int totalCopies = 0;
    int borrowedCopies = 0;

};
 const int mxCapacity = 20;

extern book myLibrary[mxCapacity];

void userInterface();

void addBook();

void editBook();

void searchBook();

void deleteBook();

void borrowBook();

void displayBooks();

void restoreBook();

pair<int,int> countBooks();

void bookDetails(int id);

bool checkBookId(int &id);

bool checkBookName(int &id,string name);

pair<int,int> isLibraryFull();


