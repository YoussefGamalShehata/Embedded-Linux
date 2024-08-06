#include <iostream>
#include <cmath>

using namespace std;

class Calculator {
private:
    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b == 0) {
            cerr << "Error: Division by zero!" << endl;
            return NAN;
        }
        return a / b;
    }

    double power(double a, double b) {
        return pow(a, b);
    }

    double squareRoot(double a) {
        if (a < 0) {
            cerr << "Error: Cannot take square root of a negative number!" << endl;
            return NAN;
        }
        return sqrt(a);
    }

public:
    void calculate() {
        double num1, num2;
        char operation;
        bool keepGoing = true;

        while (keepGoing) {
            cout << "Enter first number (or 'Q' to quit): ";
            if (!(cin >> num1)) {
                cin.clear(); // clear the error flag
                string input;
                cin >> input;
                if (input == "Q" || input == "q") {
                    keepGoing = false;
                    continue;
                } else {
                    cout << "Invalid input. Please enter a number or 'Q' to quit." << endl;
                    continue;
                }
            }

            cout << "Enter an operator (+, -, *, /, ^, S for sqrt): ";
            cin >> operation;

            switch (operation) {
                case '+':
                    cout << "Enter second number: ";
                    cin >> num2;
                    cout << "Result: " << add(num1, num2) << endl;
                    break;
                case '-':
                    cout << "Enter second number: ";
                    cin >> num2;
                    cout << "Result: " << subtract(num1, num2) << endl;
                    break;
                case '*':
                    cout << "Enter second number: ";
                    cin >> num2;
                    cout << "Result: " << multiply(num1, num2) << endl;
                    break;
                case '/':
                    cout << "Enter second number: ";
                    cin >> num2;
                    cout << "Result: " << divide(num1, num2) << endl;
                    break;
                case '^':
                    cout << "Enter second number: ";
                    cin >> num2;
                    cout << "Result: " << power(num1, num2) << endl;
                    break;
                case 'S':
                    cout << "Square root of " << num1 << " is " << squareRoot(num1) << endl;
                    break;
                default:
                    cout << "Error: Invalid operator!" << endl;
                    break;
            }
        }
    }
};

int main() {
    Calculator calc;
    calc.calculate();
    return 0;
}