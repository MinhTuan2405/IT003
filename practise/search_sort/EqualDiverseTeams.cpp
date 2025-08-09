/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
#include <vector>
using namespace std;

//###INSERT CODE HERE -
void can_divide (vector <int> classroom, int k) {

}

int main () {
    int testcase; cin >> testcase;

    for (int i = 0; i < testcase; ++i) {
        int n, k; cin >> n >> k;
        vector <int> classroom  (n, 0);
        for (int i = 0; i < n; ++i) cin >> classroom[i];

        can_divide (classroom, k);
    }
}