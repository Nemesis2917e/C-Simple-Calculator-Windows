#include <iostream>
using namespace std;

int main() {
    double rick, roll;
    char op;
    double gotYou;

    cout << "Enter first number: ";
    cin >> rick;

    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> roll;

    switch(op) {
        case '+':
            gotYou = rick + roll;
            cout << "Result: " << gotYou << endl;
            cin.ignore();
            cin.get();
            cin.get();
            cin.get();
            break;
        case '-':
            gotYou = rick - roll;
            cout << "Result: " << gotYou << endl;
            cin.ignore();
            cin.get();
            cin.get();
            cin.get();
            break;
        case '*':
            gotYou = rick * roll;
            cout << "Result: " << gotYou << endl;
            cin.ignore();
            cin.get();
            cin.get();
            cin.get();
            break;
        case '/':
            if(roll != 0) {
                gotYou = rick / roll;
                cout << "Result: " << gotYou << endl;
                cin.ignore();
                cin.get();
                cin.get();
                cin.get();
            } else {
                cout << "Error: Division by zero!" << endl;
                cin.ignore();
                cin.get();
                cin.get();
                cin.get();
            }
            break;
        default:
            cout << "Error: Invalid operator!" << endl;
            cin.ignore();
            cin.get();
            cin.get();
            cin.get();
            break;
    }

    return 0;
}
