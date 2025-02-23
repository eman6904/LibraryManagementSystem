
#include <iostream>
#include "header.h"
using namespace std;

book myLibrary[mxCapacity];

void userInterface()
{

    string welcomeMsg = " Welcome In My First Project ^^ ";
    char arr[6][102];
    int pos = 0;
    for(int i=0; i<=5; i++)
    {
        for(int j=0; j<=100; j++)
        {

            if(i==0||j==0||i==5||j==100)
            {
                arr[i][j]='&';

            }
            else if(i==2&&j>=33&&pos<welcomeMsg.size())
            {
                arr[i][j]=welcomeMsg[pos];
                pos++;
            }
            else
            {
                arr[i][j]=' ';

            }
        }

    }

    for(int i=0; i<=5; i++)
    {

        for(int j=0; j<=100; j++)
        {

            cout<<arr[i][j];
        }
        cout<<"\n";
    }
    string libraryCommands[] =
    {
        "Add Book", "Edit Book",
        "Search Book","Delete Book",
        "Borrow Book","Restore Book",
        "Display Books","Total Books Count",
        "Unique Books Count","Empty Shelfs"
    };

    for(int i=0; i<=9; i++)
    {

        for(int j=0; j<=100; j++)
        {

            if(j==0)
            {
                cout<<"& "<<i+1<<") "<<libraryCommands[i];
                if(i==9)
                    j+=(5+libraryCommands[i].size());
                else
                    j+=(4+libraryCommands[i].size());
            }
            else if(j==100)
                cout<<"&";
            else
                cout<<" ";
        }
        cout<<"\n";
    }
}
bool checkBookId(int &id)
{

    while((id>=mxCapacity||id<0)||myLibrary[id].bookId == -1)
    {

        if(id>=mxCapacity||id<0)
            cout<<"this book's shelf doesn't exist!\n";
        else
            cout<<"There is no book!\n";
        cout<<"1) Try again.\n2) Cancel.\n\n";
        cout<<"Enter number of your answer: ";
        int ans;
        cin>>ans;
        cout<<"\n";
        if(ans==1)
        {
            cout<<"Enter the book's shelf number: ";
            cin>>id;
            cout<<"\n";
            id--;
        }
        else
            return 0;
    }
    return 1;
}

bool checkBookName(int &id,string name)
{

    bool notFound = true;
    while(notFound)
    {

        for(const auto& book:myLibrary)
        {

            if(book.bookName==name)
            {

                notFound = false;
                id = book.bookId;
            }
            if(!notFound)
                break;
        }
        if(notFound)
        {

            cout<<"This boook is not found!\n";
            cout<<"1) Try again.\n2) Cancel.\n\n";
            cout<<"Enter number of your answer: ";
            int ans;
            cin>>ans;
            cout<<"\n";
            if(ans==1)
            {

                cout<<"Enter book name: ";
                cin.ignore();
                getline(cin,name);
                cout<<"\n";
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}
pair<int,int> isLibraryFull()
{

    int bookId = -1;
    for(const auto& book:myLibrary)
    {

        if(book.bookId==-1)
            return {0,bookId+1};

        bookId = book.bookId;
    }
    return {1,-1};
}

void bookDetails(int id)
{

    cout<<"1) Book's shelf number = "<<myLibrary[id].bookId+1<<"\n";
    cout<<"2) Book name = "<<myLibrary[id].bookName<<"\n";
    cout<<"3) Book price = "<<myLibrary[id].bookPrice<<" L.E\n";
    cout<<"4) Book author name = "<<myLibrary[id].authorName<<"\n";
    cout<<"5) Book total copies = "<<myLibrary[id].totalCopies<<"\n";
    cout<<"6) Book borrowed copies = "<<myLibrary[id].borrowedCopies<<"\n\n";
}
void addBook()
{
    string bookName,authorName;
    double bookPrice;
    int copies_number;
    cin.ignore();
    cout<<"Enter book name: ";
    getline(cin,bookName);

    cout<<"Enter book author name: ";
    getline(cin,authorName);

    cout<<"Enter book price: ";
    cin>>bookPrice;

    cout<<"Enter number of copies: ";
    cin>>copies_number;

    pair<int,int>res = isLibraryFull();
    int book_id = res.second;
    if(res.first == 0)
    {
        for(const auto &book:myLibrary){

            if(book.bookName ==  bookName&& book.authorName == authorName&&book.bookPrice == bookPrice)
            {
                book_id = book.bookId;
                break;
            }
        }
        myLibrary[book_id].authorName = authorName;
        myLibrary[book_id].bookName = bookName;
        myLibrary[book_id].bookPrice = bookPrice;
        myLibrary[book_id].bookId = res.second;
        myLibrary[book_id].totalCopies+=copies_number;
        cout<<"\n"<<bookName<<" book is entered successfully at shelf "
            <<book_id+1<<" of your Library.\n and currently, existing total copies is "<<myLibrary[book_id].totalCopies<<".\n\n";
    }
    else
    {
        cout<<"/nSorry,but library is full\n";
    }
}

void displayBooks()
{

    cout<<"\n";
    for(const auto& book:myLibrary)
    {

        if(book.bookId == -1)
            cout<<"Empty Place\n\n";
        else
        {
            bookDetails(book.bookId);
        }
    }
}

void editBook()
{

    string bookName,authorName;
    double bookPrice;
    bool editNow = false;
    int id;
    string name;
    cout<<"To edit book , you must enter book's shelf number or book name.\nWhat do you want to use?\n";
    cout<<"1) Book's shelf number.\n2) Book name.\n\n";
    cout<<"Enter number of your answer: ";
    int ans;
    cin>>ans;
    cout<<"\n";
    if(ans==1)
    {
        cout<<"Enter the book's shelf number: ";
        cin>>id;
        cout<<"\n";
        id--;
        editNow = checkBookId(id);
    }
    else
    {
        cout<<"Enter book name: ";
        cin.ignore();
        getline(cin,bookName);
        cout<<"\n";
        editNow = checkBookName(id,name);
    }

    if(editNow)
    {
        cout<<"Details of book that you want to edit:\n";
        bookDetails(id);
        cout<<"Are you sure, you want to edit "<<myLibrary[id].bookName<<" book ?\n";
        cout<<"1) Edit\n2) Cancel\n\n";
        int myAns;
        cout<<"Enter number of your answer: ";
        cin>>myAns;
        cout<<"\n";
        switch(myAns)
        {
        case 2:
        {
            break;
        }
        case 1:
        {
            while(true)
            {
                cout<<"What do you want to edit?\n";
                cout<<"1) Book name\n2) Book price\n3) Author name\n4) Cancel\n\n";
                cout<<"Enter number of your answer: ";
                int ans;
                cin>>ans;
                cout<<"\n";
                cin.ignore();
                if(ans==1)
                {
                    cout<<"Enter new book name: ";
                    getline(cin,bookName);
                    cout<<"\n";
                    myLibrary[id].bookName = bookName;
                    cout<<"\nNow book name is "<<myLibrary[id].bookName<<"\n\n";
                }
                else if(ans==2)
                {
                    cout<<"Enter new book price: ";
                    cin>>bookPrice;
                    cout<<"\n";
                    myLibrary[id].bookPrice = bookPrice;
                    cout<<"\nNow book price is "<<myLibrary[id].bookPrice<<" L.E\n\n";
                }
                else if(ans==3)
                {
                    cout<<"Enter new author name: ";
                    getline(cin,authorName);
                    cout<<"\n";
                    myLibrary[id].authorName = authorName;
                    cout<<"\nNow auther name is "<<myLibrary[id].authorName<<"\n\n";

                }
                else
                {
                    break;
                }
            }
            cout<<"\n"<<myLibrary[id].bookName<<" book is edited successfully\n\n";

            break;
        }
        }
    }


}
void searchBook()
{

    string name;
    int id;
    cout<<"Enter book name: ";
    cin.ignore();
    getline(cin,name);
    cout<<"\n";
    if(checkBookName(id,name))
    {
        bookDetails(id);
    }
    else
    {
        cout<<"This book is not found !\n\n";
    }

}
void deleteBook(){

    string name;
    int id;
    cout<<"Enter book name: ";
    cin>>name;cout<<"\n";
    if(checkBookName(id,name)){

        name = myLibrary[id].bookName;
        myLibrary[id].authorName = "";
        myLibrary[id].bookName = "";
        myLibrary[id].bookPrice = 0.0;
        myLibrary[id].bookId = 0;
        myLibrary[id].totalCopies = 0;
        myLibrary[id].borrowedCopies = 0;

        cout<<name<<" book is deleted successfully!\n\n";
    }


}
void borrowBook(){

    int id;
    cout<<"Enter book name: ";
    string name; cin>>name;cout<<"\n";
    if(checkBookName(id,name)){

        cout<<"The borrowing process was successful. Currently, borrowed copies of this book is "
        <<++myLibrary[id].borrowedCopies<<".\nand Existing total copies is "<<--myLibrary[id].totalCopies<<"\n\n";
    }
}
void restoreBook(){

    string name;
    cout<<"Enter book name: ";
    cin>>name;cout<<"\n";
    for(const auto& book:myLibrary){

        if(book.bookName == name)
           {
                cout<<name<<" book has been successfully returned. Currently, borrowed copies of this book is "
                  <<--myLibrary[book.bookId].borrowedCopies<<".\nand total copies is "<<++myLibrary[book.bookId].totalCopies<<"\n\n";
           }
    }

}
pair<int,int>countBooks(){

    int total_books = 0,unique_books = 0;
    for(const auto &book:myLibrary){

        total_books+=book.totalCopies;
        unique_books+=(book.bookId!=-1);
    }
    return {total_books,unique_books};
}
