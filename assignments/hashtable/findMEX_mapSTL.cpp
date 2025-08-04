/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
vector
###End banned keyword*/


#include<map>
#include<iostream>
using namespace std;

int main()
{

//###INSERT CODE HERE -
    int n; cin >> n;
    map <int, int> mp;

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        mp[x] += 1;
    }

    int missing = 0;
    while (mp[missing]) missing++;
    cout << missing;
    return 0;

}

