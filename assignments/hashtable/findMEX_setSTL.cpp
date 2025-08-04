/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
map
vector
###End banned keyword*/


#include<set>
#include<iostream>
using namespace std;

int main()
{
    set<int> b;
    //###INSERT CODE HERE -
    int n; cin >> n; 
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        b.insert (x);
    }

    int missing = 0;
    for (auto i : b){
        if (i != missing) {
            break;
        }
        ++missing;
    }
    cout << missing; 
    return 0;

}



