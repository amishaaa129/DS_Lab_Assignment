#include <iostream>
#include <stack> 
using namespace std;

int main() {
    string input, reversed;
    stack<char> s;

    cout << "Enter a string to reverse: ";
    getline(cin, input); 
    for (char ch : input) {
        s.push(ch);
    }

    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }
    cout << "Reversed string: " << reversed << endl;

    return 0;
}
