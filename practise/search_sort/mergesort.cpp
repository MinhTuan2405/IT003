/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>


//###INSERT CODE HERE -
void mergesort (int a[], int b[], int n, int m) {
    int i = 0;
    int j = 0;
    int* merge = new int [m+n];
    int current = 0;

    while (i < n || j < m) {
        if (j >= m || i < n && a[i] <= b[j]) {
            merge[current++] = a[i++];
        }else {
            merge[current++] = b[j++];
        }
    }

    for (int i = 0; i < current; ++i) {
        std::cout << merge[i] << " ";
    }

    delete[] merge;
    merge = NULL;
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    int testcase; std::cin >> testcase;

    for (int i = 0; i < testcase; ++i) {
        int  n, m; std::cin >> n >> m;
        int* a = new int [n];
        for (int j = 0; j < n; ++j) std::cin >> a[j];
        int* b = new int [m];
        for (int j = 0; j < m; ++j) std::cin >> b[j];

        mergesort (a, b, n, m);
        std::cout << '\n';

        delete[] a;
        delete[] b;
        a = nullptr;
        b = nullptr;
    }
    return 0;
}