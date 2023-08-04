#include <iostream>
using namespace std;

float operate(float x, float y, char op) {
    switch (op) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return y != 0 ? x / y : 0.0;
        default: return 0.0;
    }
}

int main() {
    cout << "Select operation: +, -, *, /" << endl;

    char choice;
    cin >> choice;

    float num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    cout <<"The answer will be:"<< num1 << " " << choice << " " << num2 << " = " << operate(num1, num2, choice) << endl;

    return 0;
}
