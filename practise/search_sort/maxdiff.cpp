#include <bits/stdc++.h>
using namespace std;

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    int testcase; cin >> testcase;
    for (int i = 0; i < testcase; ++i) {
        int n; cin >> n;
        vector <int> a (n); for (auto &el : a) cin >> el;

        sort (a.begin(), a.end ());
        if (a.size () <= 1) cout << 0;
        else if (a.size () >= 2 && a.size () <= 3) cout << a[a.size () - 1] - a[0];
        else {
            cout << a[a.size () - 1] - a[0] + a[a.size () -2] - a[1];
        }
        cout << endl;
    } 

    return 0;
}