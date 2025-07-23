#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

bool ismathematical (char ch) {
    if (int (ch) >= 65 && int (ch) <= 90) return true;
    return false;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; 
}

string convert (string infix) {
    queue <char> q;
    stack <char> s;

    for (int i = 0; i < infix.length (); ++i) {
        char curr = infix[i];

        if (ismathematical (curr)) {
            q.push (curr);
        }else if (curr == '(') {
            s.push (curr);
        }else if (curr == ')') {
            while (!s.empty () && s.top () != '(') {
                q.push (s.top ());
                s.pop ();
            }

            if (!s.empty ()) s.pop ();
        }else {
            while (!s.empty() && precedence(curr) <= precedence(s.top())) {
                q.push(s.top());
                s.pop();
            }
            s.push(curr); 
        }
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    string postfix;
    while (!q.empty()) {
        postfix += (q.front());
        postfix += " ";
        q.pop();
    }

    return postfix;
}


int main () {
    string infix; 
    cin >> infix;

    string res = convert (infix);
    cout << res;
    return 0;
}