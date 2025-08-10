/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
using namespace std;


//###INSERT CODE HERE -
void inputMatrix (int a[50][50], int &n, int &m) {
    for (int i = 0; i < 50; ++i)
        for (int j = 0; j < 50; ++j) a[i][j] = 0;
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            int x; cin >> x;
            a[i][j] = x;
        }
}

void outputMatrix (int a[50][50], int n, int m) {
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}

int main()
{
    int m,n,a[50][50];
    inputMatrix(a,n,m);
    cout<<"Matrix:\n";
    outputMatrix(a,n,m);
    uniqueElements(a,n,m);
    return 0;
}



