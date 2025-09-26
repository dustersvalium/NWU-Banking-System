#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <cmath>
using namespace std;

struct Contact {
    string name;
    string phoneNum;
};

bool isBool(int password){

    if (password <= 1) return false;
    if (password == 2) return true;
    if (password % 2 == 0) return false;

    for (int i = 3; i <= sqrt(password); i += 2) {
        if (password % i == 0) return false;
    }

    return true;
}

bool validatePassword(int password){

    cout<<"Enter your 4-digit prime number password (1009, 2063,3911, etc.):  ";
    cin>>password;

    if(!isBool(password)){
        cout<<"Incorrect password. Please try again: ";
        cin>>password;
    }
    else{
        cout<<"Password accepted!";
    }
    return true;
}

void displayMenu(){
    cout<<"Contact Management System\n"
        <<"1. Add Contact\n"
        <<"2.View all contact\n"
        <<"3. Delete contact by name\n"
        <<"4. Save to Simcard\n"
        <<"5. Load from Simcard\n"
        <<"6. Logout\n";
}

void addContacts(Contact contacts [], int &size){
    //Contact contacts[size];
    cout<<"Enter contact name: ";
    cin.ignore();
    getline(cin,contacts[size].name);

    cout<<"Enter contact number: ";
    cin>>contacts[size].phoneNum;
    size++;

}

void viewContacts(Contact contacts [], int size){
    cout<<"ALL CONTACTS\n";
    for(int i = 0; i<size; i++){
        cout<<"Contact #"<<(i+1)<<"-  Name: "<<contacts[i].name<<", Number: "<< contacts[i].phoneNum<<endl;
    }
}

void deleteContact(Contact contacts [], int &size){
    int delNum;
    cout<<"Select the contact you want to delete: ";
    cin>>delNum;
    for(int i = delNum-1; i<size; i++ ){
        contacts[i] = contacts[i+1];
    }
    size--;
}

void loadSimCard(Contact contacts [], int size){
    ofstream file("Contacts.dat", ios::binary);
    for(int i = 0; i<size; i++){
        file.write(reinterpret_cast<char*>(contacts), sizeof(Contact)* size);
    }
    file.close();
    cout<<"Contacts saved to file\n";

}

int main(){

    Contact contact1 ={"Jan Smit", "0639499751" };
    Contact contact2 = {"Pieter Pan", "0583585928"};
    Contact contact3 = {"Theresa Papa", "0385957489"};
    /*Variables*/
    int password;
    int choice;
    int size = 3;
    const int contMax = 100;
    Contact contacts [contMax] = {contact1, contact2, contact3};


    validatePassword(password);
    do{
        displayMenu();
        cout<<"Enter your choice: ";
        cin>> choice;

        switch(choice){
            case 1: addContacts(contacts, size); cout<<"Contact successfully added\n"; break;

            case 2: viewContacts(contacts, size); break;

            case 3: deleteContact(contacts, size); cout<<"Contact sucessfully deleted\n"; viewContacts(contacts, size); break;

            case 4: loadSimCard(contacts, size); break;

            case 5: /*load from simcard*/

            case 6: break;

            default: cout<< "Invalid choice. Insert a number between 1 & 6"; cin>>choice;
        }



    }while(choice != 6);

    return 0;
}