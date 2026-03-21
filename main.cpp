#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;

const int MAX_BUSINESSES = 10;
const int MAX_INGREDIENTS = 20;

// Global arrays
string businessNames[MAX_BUSINESSES][MAX_INGREDIENTS];
double businessUnitCost[MAX_BUSINESSES][MAX_INGREDIENTS];
double businessQuantity[MAX_BUSINESSES][MAX_INGREDIENTS];
double businessYield[MAX_BUSINESSES];
int businessIngredientCount[MAX_BUSINESSES];
int totalBusinesses = 0;

// Template functions
template <typename T>
T calcTotalCost(T costs[], int size) {
    T total = 0.0;
    for (int i = 0; i < size; i++) {
        total += costs[i];
    }
    return total;
}

template <typename T>
T calcCostPerUnit(T totalCost, T yield) {
    return totalCost / yield;
}

template <typename T>
T calcSellingPrice(T costPerUnit, T profitPercent) {
    return costPerUnit / (1.0 - (profitPercent / 100.0));
}

template <typename T>
T calcProfit(T revenue, T totalCost) {
    return revenue - totalCost;
}

// Function prototypes
void header(string txt);
void m(int margin);
int menu1();
int menu2();
int option(string option1,string option2);
int option(string option1,string option2, string option3);

int main(){
    int choice = 1;

    choice = menu1();
    if(choice == 1){
        menu2();
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
    system("cls||clear");
    header("Selling Price Calculator");
    m(1);
    x = option("Start Inputting Data","End Program");
    return x;
}

int menu2(){
    int choice;
    system("cls||clear");
    header("Selling Price Calculator");
    m(1);

    choice = option("New Business","Existing Business","Back");

    if(choice == 1){  // NEW BUSINESS
        if(totalBusinesses < MAX_BUSINESSES){
            system("cls||clear");
            header("Selling Price Calculator");
            string productName;
            cout << "Product name: ";
            cin.ignore();
            getline(cin, productName);

            int numIngredients;
            cout << "Number of ingredients: ";
            cin >> numIngredients;

            if(numIngredients <= MAX_INGREDIENTS){
                for(int i = 0; i < numIngredients; i++){
                    cout << "\nIngredient " << i+1 << ":" << endl;
                    cout << "Name: ";
                    cin.ignore();
                    getline(cin, businessNames[totalBusinesses][i]);
                    cout << "Cost per unit (PHP): ";
                    cin >> businessUnitCost[totalBusinesses][i];
                    cout << "Quantity used: ";
                    cin >> businessQuantity[totalBusinesses][i];
                }

                businessIngredientCount[totalBusinesses] = numIngredients;

                cout << "\nProduction yield (how many products made): ";
                cin >> businessYield[totalBusinesses];

                double ingredientCosts[MAX_INGREDIENTS];
                for(int i = 0; i < numIngredients; i++){
                    ingredientCosts[i] = businessUnitCost[totalBusinesses][i] * businessQuantity[totalBusinesses][i];
                }

                double totalCost = calcTotalCost(ingredientCosts, numIngredients);
                double costPerUnit = calcCostPerUnit(totalCost, businessYield[totalBusinesses]);

                double profitPercent;
                cout << "Desired profit (%): ";
                cin >> profitPercent;

                double sellingPrice = calcSellingPrice(costPerUnit, profitPercent);

                cout << "\n=== RESULTS ===" << endl;
                cout << "Total ingredient cost: PHP " << fixed << setprecision(2) << totalCost << endl;
                cout << "Yield: " << businessYield[totalBusinesses] << " units" << endl;
                cout << "Cost per unit: PHP " << fixed << setprecision(2) << costPerUnit << endl;
                cout << "Selling price per unit: PHP " << fixed << setprecision(2) << sellingPrice << endl;

                totalBusinesses++;
                cout << "\nBusiness saved!" << endl;
            }
        }

    } else if(choice == 2){  // EXISTING BUSINESS
        if(totalBusinesses == 0){
            cout << "\nNo businesses saved!" << endl;
        } else {
            cout << "\nSaved Businesses:" << endl;
            for(int i = 0; i < totalBusinesses; i++){
                cout << "[" << i+1 << "] " << businessNames[i][0] << endl;
            }

            int busChoice;
            cout << "Select: ";
            cin >> busChoice;

            if(busChoice > 0 && busChoice <= totalBusinesses){
                int busIndex = busChoice - 1;
                int numIng = businessIngredientCount[busIndex];

                double ingredientCosts[MAX_INGREDIENTS];
                for(int i = 0; i < numIng; i++){
                    ingredientCosts[i] = businessUnitCost[busIndex][i] * businessQuantity[busIndex][i];
                }
                double totalProductionCost = calcTotalCost(ingredientCosts, numIng);

                double actualSellPrice, unitsSold;
                cout << "\nActual sales:" << endl;
                cout << "Selling price per unit (PHP): ";
                cin >> actualSellPrice;
                cout << "Units sold: ";
                cin >> unitsSold;

                double revenue = actualSellPrice * unitsSold;
                double profitEarned = calcProfit(revenue, totalProductionCost);

                cout << "\n=== PROFIT REPORT ===" << endl;
                cout << "Total production cost: PHP " << fixed << setprecision(2) << totalProductionCost << endl;
                cout << "Revenue: PHP " << fixed << setprecision(2) << revenue << endl;

                if(profitEarned >= 0){
                    cout << "Profit earned: PHP " << fixed << setprecision(2) << profitEarned << endl;
                } else {
                    cout << "Loss: PHP " << fixed << setprecision(2) << profitEarned << endl;
                }
            }
        }
    }

    m(1);
    cout << "Press Enter...";
    cin.ignore();
    cin.get();
    return 0;
}
