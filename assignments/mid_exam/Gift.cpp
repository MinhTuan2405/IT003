/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
#include <vector>
using namespace std;

//###INSERT CODE HERE -
int max (int a, int b) {
    if (a < b) return b;
    return a;
}

void arrange(vector<int> &a, int left, int right) {
    if (left >= right) return;

    int pivot = a[right];
    int i = left - 1;

    for (int j = left; j < right; ++j) {
        if (a[j] < pivot) {
            swap(a[++i], a[j]);
        }
    }

    swap(a[++i], a[right]);
    arrange(a, left, i - 1);
    arrange(a, i + 1, right);
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    arrange(a, 0, a.size () -1);
    int i = 0, j = n - 1;
    int res = -1;
    while (i < j) {
        int sum = a[i] + a[j];
        if (sum > x)
            --j;
        else {
            res = max(res, sum);
            ++i;
        }
    }
    cout << res << endl;
    return 0;
}

