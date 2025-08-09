/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
multiset
map
unordered_map
###End banned keyword*/

#include <iostream>
#include <vector>
using namespace std;


//###INSERT CODE HERE -

int main () {

    int n; 
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int maxVal = n + 5; // kích thước đủ để chứa tất cả giá trị có thể xuất hiện
    vector<bool> appear(maxVal, false);
    int curMin = 0;

    for (int i = 0; i < n; ++i) {
        if (v[i] < maxVal) {
            appear[v[i]] = true; // Đánh dấu đã gặp số này
        }
        while (curMin < maxVal && appear[curMin]) {
            curMin++;
        }
        cout << curMin << " ";
    }

    return 0;
}