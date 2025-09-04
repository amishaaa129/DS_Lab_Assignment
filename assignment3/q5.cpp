#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix(string expr) {
    stack<int> s;
    for (char ch : expr) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': {
                    int result = 1;
                    for (int i = 0; i < val2; i++) result *= val1;
                    s.push(result);
                    break;
                }
            }
        }
    }
    return s.top();
}
int main() {
    string expr;
    cout << "Enter postfix expression: ";
    cin >> expr;
    cout << "Result: " << evaluatePostfix(expr) << endl;
    return 0;
}
