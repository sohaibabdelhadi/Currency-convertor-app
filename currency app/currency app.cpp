

#include <iostream>
#include<fstream>
#include<sstream>
using namespace std;
//here display the list of currencies 
void displayMenu() {
    cout << "SAR-- > Saudi Arabia Riyal" << endl;
    cout << "KWD-- > Kuwaiti Dinar" << endl;
    cout << "QAR-- > Qatar Riyal" << endl;
    cout << "AED-- > United Arab Emirates Dirham" << endl;
    cout << "BHD-- > Bahraini Dinar" << endl;
    cout << "OMR-- > Omani Rial" << endl;        
}

//as user might enter captial or small letter this function makes the input of currency always capital
void captilizeCurrency(string &currency) {
    int length = currency.length();
    for(int i=0;i<length;i++){
        if (islower(currency[i])) {
            currency[i]=toupper(currency[i]);
        }
    }
}
//check if currencies are in list or check their spellings 
bool checkCurrencyInThelist(string currency) {
    captilizeCurrency(currency);
    if (currency == "SAR" || currency == "KWD" || currency == "QAR" || currency == "AED" || currency == "BHD" || currency == "OMR")
        return true;
    else {
        system("cls");
        cout << "your entry is not in the list please enter again onr of currencies in the list!"<<endl;
        displayMenu();
        cout << "===================================================================================" << endl;
        return false;
    }
}

//this function takes currency to be converted and to which is it going to be converted and the amount of money will be converted 
void changeMoney(string FromCurrency, string ToCurrency, double amount) {
    string line; // a string to store only one line from the file
    ifstream myfile;
    double number1, number2; // two varibals to store currency value will be changed and the crossponding value 
    string s1, s2; //string sring to store name of currencies 
    myfile.open("exchangeRate.txt");
    while (getline(myfile,line)){ // loop keeps iterating line by line until the end of the file; 
        stringstream ss(line); 
        ss >> number1 >> s1 >> number2 >> s2;
       
        if (s1 == FromCurrency && s2 == ToCurrency) {
            cout << amount << " " << s1 << " is " << amount * number2 << " " << s2 << endl;
            break;
        }
        if (s2 == FromCurrency && s1 == ToCurrency) {
            cout << amount <<" "<<s2 << " is " << amount / number2 <<" "<<s1;
            break;
        }
    }
}
void askUser() {
    string currency;
    string fromCurrency;
    string toCurrency;
    double amountOfmoney;
    cout << "What is the currency you have?: ";
    cin >> currency;
    cout << endl;
    if (checkCurrencyInThelist(currency)) {
        captilizeCurrency(currency);
        fromCurrency = currency;
        cout << "What is the currency you want to exchange it for?: ";
        cin >> currency;
        cout << endl;
        if (checkCurrencyInThelist(currency)) {
            captilizeCurrency(currency);
            toCurrency = currency;
            cout << "How much money you want to exchange?: ";
            cin >> amountOfmoney;
            cout << endl;
            changeMoney(fromCurrency, toCurrency,amountOfmoney);
        }
        else {
            askUser();
        }
    }
    else {
        askUser();
    }
    

}
void runApp() {
    displayMenu();
    cout << endl;
    askUser();
}
int main()
{
    runApp();
}


