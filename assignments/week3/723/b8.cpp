#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

bool isnumber (char ch) {
    if (int (ch) >= 0 && int (ch) <= 9) return true;
    return false;
}

bool isOperator(const string& token) {
    return token == "+" || token == "-" || token == "x" || token == ":";
}
 
void compute (string postfix) {
    queue <char> q;
    stack <char> s;

    for (char curr : postfix) {
        if (isnumber (curr)) {
            q.push (curr);
        }
    }

}

int main () {
    string postfix;
    cin >> postfix;

}