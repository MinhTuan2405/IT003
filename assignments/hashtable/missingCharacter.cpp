#include <bits/stdc++.h>
using namespace std;


char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') return ch + 32;
    return ch;
}

int totalMissingvalue (string str) {
    bool alphabet[26] {false};

    for (char ch : str) {
        if (ch >= 'a' && ch <= 'z') alphabet[ch - 'a'] = true;
    }

    int totalMissing = 0;
    for (bool i : alphabet) 
        if (!i) ++totalMissing;

    return totalMissing;
}

int main () {
    int n; cin >> n;
    string str = "";
    for (int i = 0; i < n; ++i) {
        char x; cin >> x;
        x = toLower (x);
        str += x;
    }

    cout << totalMissingvalue (str);

    return 0;
}
