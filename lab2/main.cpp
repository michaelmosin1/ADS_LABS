#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cmath>
#include <sstream>

using namespace std;

bool isValidExpression(const string& expr) {
    int balance = 0;
    if (expr.empty() || expr.back() != '=') {
        return false;
    }
    for (char c : expr) {
        if (c == '(') balance++;
        if (c == ')') balance--;
        if (balance < 0) return false;
    }
    
    return balance == 0;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw runtime_error("Division by zero");
            return a / b;
        default: throw runtime_error("Unknown operator");
    }
}

string infixToPostfix(const string& expr) {
    stack<char> operators;
    stringstream output;

    for (size_t i = 0; i < expr.length(); ++i) {
        char c = expr[i];
        if (isspace(c)) continue;
        if (isdigit(c) || (c == '.' && i + 1 < expr.length() && isdigit(expr[i + 1]))) {
            while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.')) {
                output << expr[i++];
            }
            output << ' ';
            --i;
        }
        else if (c == '(') {
            operators.push(c);
        }
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                output << operators.top() << ' ';
                operators.pop();
            }
            if (!operators.empty()) operators.pop();  // Убираем '(' из стека
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                output << operators.top() << ' ';
                operators.pop();
            }
            operators.push(c);
        }
    }
    while (!operators.empty()) {
        output << operators.top() << ' ';
        operators.pop();
    }
    return output.str();
}

double evaluatePostfix(const string& expr) {
    stack<double> values;
    stringstream ss(expr);
    string token;
    while (ss >> token) {
        if (isdigit(token[0])) {
            values.push(stod(token));
        } else {
            double b = values.top(); values.pop();
            double a = values.top(); values.pop();
            values.push(applyOperation(a, b, token[0]));
        }
    }
    return values.top();
}

int main() {
    string expr;
    cout << "Введите выражение: ";
    cin >> expr;
    if (!isValidExpression(expr)) {
        cout << "Ошибка: некорректное выражение или отсутствует символ '=' в конце." << endl;
        return 1;
    }
    expr.pop_back();
    try {
        double result = evaluatePostfix(infixToPostfix(expr));
        cout << "Результат: " << result << endl;
    } catch (const runtime_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    return 0;
}
