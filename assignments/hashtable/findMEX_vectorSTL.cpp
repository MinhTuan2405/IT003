/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
map
set
###End banned keyword*/


#include<vector>
#include<iostream>
using namespace std;

int main()
{

//###INSERT CODE HERE -
    int n; cin >> n;
    vector <int> vi;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        vi.push_back (x);
    }

    /*
    chỗ này giới hạn số phần tử của counting array lại, bởi vì missing value không bao giờ vượt quá số
    lượng phần tử của mảng gốc ban đầu được, nếu mảng gốc ban đầu là một dãy cấp số cộng có khoảng cách là 1 thì 
    missing là size của mảng gốc + 1;
     */

    vector<int> vii(n + 1, 0);  

    for (int i : vi) {
        if (i >= 0 && i <= n) {
            vii[i] += 1;
        }
    }

    int missing = 0;
    while (vii[missing])  ++missing;

    cout << missing;

    return 0;

}



