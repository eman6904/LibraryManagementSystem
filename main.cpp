#include <iostream>
#include "header.h"
using namespace std;

int main()
{

    while(true)
    {
        userInterface();
        cout<<"Enter Command Number: ";
        int command_num;
        cin>>command_num;cout<<"\n";
        switch(command_num)
        {
        case 1:
        {
            addBook();
            break;
        }
        case 2:
        {
            editBook();
            break;
        }
        case 3:
        {
            searchBook();
            break;
        }
        case 4:
        {
            deleteBook();
            break;
        }
        case 5:
        {
            borrowBook();
            break;
        }
        case 6:
        {
            restoreBook();
            break;
        }
        case 7:
        {
            displayBooks();
            break;
        }
        case 8:
        {
            cout<<"Total books number is "<<countBooks().first<<".\n\n";
            break;
        }
        case 9:
        {
             cout<<"Unique books number is "<<countBooks().second<<".\n\n";
            break;
        }
        case 10:
        {
             cout<<"Empty shelfs number is "<<mxCapacity - countBooks().second<<".\n\n";
            break;
        }
        default:{
            cout<<"Invalid command\n";
        }
        }
        cout<<"\n";
    }

    return 0;
}
