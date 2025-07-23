#include <iostream>
#include <stack>
#include <queue>
#include <vector>


using namespace std;

int totalPair (int n, vector <int> w) {
    if (n==1) return 0;
    int res = 0;
    stack <pair<int, int>> s;   // h, c

    for (int i = 0; i < w.size (); ++i) {
        int cnt = 1;
        
    }

}

int main () {
    int n;
    cin >> n;
    vector <int> wait;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        wait.push_back (x);
    }

    cout << totalPair (n, wait);
    return 0;
}