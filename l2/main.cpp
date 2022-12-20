#include <iostream>
#include <string>
#include <stack>

using namespace std;

int priority(char op) {                                   //опрелеление приоритета операции
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int calculation(int a, int b, char op) {
    switch (op) {                                          //выполнение арифметических операций
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                cout << "Can't be divided by zero" << endl;      // проверка на "дурака"
                exit(0);
            }
            return a / b;
    }
}

int evaluate(string tokens) {                             // проверка скобок
    int bracketsCount = 0;
    bool bracketsEmpty = false;
    int i;

    stack<int> values;

    stack<char> oprs;

    for (i = 0; i < tokens.length(); i++) {

        if (tokens[i] == ' ')
            continue;

        else if (tokens[i] == '(') {
            bracketsCount++;
            oprs.push(tokens[i]);
        } else if (isdigit(tokens[i])) {
            int val = 0;

            while (i < tokens.length() &&
                   isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }

            values.push(val);
            i--;
        } else if (tokens[i] == ')') {
            bracketsCount--;
            while (!oprs.empty() && oprs.top() != '(') {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = oprs.top();
                oprs.pop();

                values.push(calculation(val1, val2, op));
            }

            if (!oprs.empty())
                oprs.pop();
        } else {
            while (!oprs.empty() && priority(oprs.top())
                                   >= priority(tokens[i])) {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = oprs.top();
                oprs.pop();

                values.push(calculation(val1, val2, op));
            }

            oprs.push(tokens[i]);
        }
    }

    if(bracketsCount!=0){
        cout << "Check the brackets" << endl;
        exit(0);
    }

    while (!oprs.empty()) {
        int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = oprs.top();
        oprs.pop();

        values.push(calculation(val1, val2, op));
    }

    return values.top();
}

int main() {
    string buff;
    cout << "Please enter expression: \"" << endl;
    getline(cin, buff);
    cout << evaluate(buff) << endl;
    return 0;
}
