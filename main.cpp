#include <iostream>
#include <iomanip>
using namespace std;

//For Designs
void header(string txt);
void m(int margin);

//Menu list
int menu1();
int menu2();

//Function Overloading
int option(string option1,string option2);
int option(string option1,string option2, string option3);


int main(){
    int choice = 1;

    choice = menu1();
    if(choice == 1){
        choice = menu2();
    }else{
        //I forgot how to turn it back
    }


    return 0;
}

void header(string txt){
    cout << "======================================================" << endl;
    cout << "=" << setw(26 + txt.length()/2) << txt << setw(27 - txt.length()/2) << "=" << endl;
    cout << "======================================================" << endl;
}

int option(string option1,string option2){
    int x;
    cout << setw(20) << "[1] " << option1 << endl;
    cout << setw(20) << "[2] " << option2 << endl;
    m(1);
    cout << "Your Input: ";
        cin >> x;
    return x;
}
int option(string option1,string option2, string option3){
    int x;
    cout << setw(20) << "[1] " << option1 << endl;
    cout << setw(20) << "[2] " << option2 << endl;
    cout << setw(20) << "[3] " << option3 << endl;
    m(1);
    cout << "Your Input: ";
        cin >> x;
    return x;
}

void m(int margin){
    for(int x = 0 ; x < margin; x++){
        cout << endl;
    }
}

int menu1(){
    int x;
    header("Selling Price Calculator");
    m(1);
    x = option("Start Inputting Data","End Program");
    return x;
}
int menu2(){
    int x;
    system("clear");
    header("Selling Price Calculator");
    option("New Business","Existing Business","Back");
    return x;
}
