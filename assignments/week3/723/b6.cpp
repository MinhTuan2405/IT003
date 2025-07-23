#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool check (string latex) {
    stack <char> s;

    for (char ch : latex) {
        if (ch == '{' || ch == '(' || ch == '[') s.push (ch);
        if (ch == '}' && s.top () == '{'
        || ch == ')' && s.top () == '('
        || ch == ']' && s.top () == '[') s.pop ();
    }

    return s.empty();
}

int main () {
    string latex;
    cin >> latex;
    if (check (latex)) cout << 1;
    else cout << 0;
    
    return 0;
}


#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool check(string latex) {
    stack<char> s;

    for (char ch : latex) {
        if (ch == '{' || ch == '(' || ch == '[') {
            s.push(ch);
        } else if (ch == '}' || ch == ')' || ch == ']') {
            if (s.empty()) return false; 
            char top = s.top();
            if ((ch == '}' && top == '{') ||
                (ch == ')' && top == '(') ||
                (ch == ']' && top == '[')) {
                s.pop();
            } else {
                return false; 
            }
        }
    }

    return s.empty();
}


int main () {
    string latex;
    cin >> latex;
    if (check (latex)) cout << 1;
    else cout << 0;
    
    return 0;
}