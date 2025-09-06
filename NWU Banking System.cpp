
#include <iostream>
using namespace std;

void menu(){
    cout<<"***************Menu***************\n";
    cout<<"a. Deposit"<<endl
        <<"b. Withdrawal"<<endl
        <<"c. Balance inquiry"<< endl
        <<"d. Exit"<< endl;
}

float addToBalance(float balance, float deposit){
    return balance + deposit;

    //return availableBalance;
}

float subtractFromBalance(float balance, float withdraw){
    return balance - withdraw;
    //return availableBalance;
}

int sumPassword(int password){
    //int arr[7];
    int sum = 0;
    while (password > 0) {
        sum += password % 10; // Add the last digit to the sum
        password /= 10;       // Remove the last digit
    }
    return sum;
}
int main(){

    /*Variable initialisations*/
    int password;
    float balance = 1000.50;
    float deposit = 0;
    float withdraw;
    char menu_items;
    //int sum_password = password%7;

    cout<<"Welcome to the NWU Banking System\n\n";
    cout<<"Please enter your password: ";
    cin>> password;

    do {

       

        if(sumPassword(password)%7 == 0){
        menu();
        cout<<"Enter your choice: ";
        cin>>menu_items;
        switch (menu_items)
        {
        case 'a':
            cout<<"Enter the amount to deposit: \n";
            cin>> deposit;
            balance = addToBalance(balance, deposit);
            cout<<"Deposit successful. Current balance = "<< balance << endl;
            break;

        case 'b':
            cout<<"Enter the amount you want to withdraw: ";
            cin>> withdraw;
            balance = subtractFromBalance(balance, withdraw);
            cout<<"Withdrawal successfull. Current balance = "<< balance<< endl;
            break;
        
        case 'c':
            cout<<"Current balance = "<< balance<< endl;
            break;

        case 'd':
            cout<<"Thank you fo using the NWU Banking System. Exiting....";
            break;
        default:
            cout<<"Invalid input"<<endl;
            break;
        }
        

        }
        else{
            cerr<<"Error: incorrect password. Please try again. \n";
            cout<<"Please enter your password: ";
            cin>>password;
        }
    }while(menu_items != 'd');

    
    return 0;
}