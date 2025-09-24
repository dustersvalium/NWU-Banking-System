#include <iostream>
#include <string>
#include <array>
using namespace std;


void displayMenu(){
    cout<<"Menu\n"
        "1. Display all books\n"
        <<"2. Add a book\n"
        <<"3. Borrow a book\n"
        <<"4. Return a book\n"
        <<"5. Delete a book\n"
        <<"6. Exit\n";
}

void displayBooks(string books[], const int SIZE){
    for(int i = 0; i<SIZE; i++){
        cout<<(i+1)<<". "<<books[i]<<endl;
    }
}

void borrowBook(string books[], char status[], int size){
    int bookNum;
    int SIZE = 10;
    displayBooks(books, SIZE);
    cout<<"Enter the number of the book to borrow (1-10): ";
    cin>>bookNum;

    if(bookNum < 10 && bookNum >0){
        if(bookNum == true){
            cout<<books[bookNum]<<" has been successfully borrowed \n";
            for(int i = 0; i<SIZE; i++){
                cout<<(i+1)<<". "<< books[i+1]<<"[ "<< status[size-1]<<" ]"<< endl;
            }
        }
        else{
            for(int i = 0; i<SIZE; i++){
                cout<<(i+1)<<". "<< books[i+1]<<"[ "<< status[size]<<" ]"<< endl;
            }
        }
        
    }
    else{
        cout<<"Invalid number. Please try again (1-10): ";
        cin>> bookNum;
    }
}

void deleteBook(string books[], char status[], int size){
    int bookNum;
    displayBooks(books, size);
    cout<<"Enter the number of the book you want to borrow: ";
    cin>>bookNum;

    for(int i = bookNum-1; i< size; i++){
        books[i] = books[i+1];
    }
    size--;
    cout<<books[bookNum]<<" successfully deleted. \n";

}






int main(){

    cout<<"Library book manager\n";

    //displayMenu();

    /*Variables*/
    int choice;
    const int SIZE = 10;
    const int size = 2;
    char status [size] = {'A', 'B'};
    string books [SIZE] = {"The Hobbit", "Dune","1984", "Alvin & the chipmunks", "Ted", "Taxi driver"};

    do{

        displayMenu();
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice){
            case 1:
                displayBooks(books, SIZE);
                break;

            case 2:
                /*add book function*/
                break;

            case 3:
            borrowBook(books, status, size);
            break;

            case 4:
            /*Return a book function*/
            break;

            case 5:
            deleteBook(books, status, size);
            break;

            default:
            cout<<"Incorrect choice. Please try again.";
            break;
        }
        
            

    }while(choice != 4);

    return 0;
}

/*int bookNum;
    displayBooks(books, size);
    cout<<"Enter the number of the book you want to borrow: ";
    cin>>bookNum;

    for(int i = bookNum-1; i< size; i++){
        books[i] = books[i+1];
    }
    size--;*/