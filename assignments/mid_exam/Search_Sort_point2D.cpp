#include <bits/stdc++.h>

using namespace std;
void arrange(vector<pair<int, int>> &a, int left, int right) {
    if (left >= right) return;

    pair<int, int> pivot = a[right];
    int i = left - 1;

    for (int j = left; j < right; ++j) {
        if (a[j].first < pivot.first || 
            (a[j].first == pivot.first && a[j].second > pivot.second)) {
            swap(a[++i], a[j]);
        }
    }

    swap(a[++i], a[right]); 

    arrange(a, left, i - 1);
    arrange(a, i + 1, right);
}

int main () {
    int n; cin >> n;
    vector <pair<int, int>> a;
    for (int i= 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        a.push_back ({x, y});
    }
    
    arrange (a, 0, a.size () -1);
    
    for (pair <int, int> i : a) {
        cout << i.first << " " << i.second << '\n';
    }
}