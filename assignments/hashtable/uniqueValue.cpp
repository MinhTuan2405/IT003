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

const int MAX_UNIQUE = 2500;

int findIndex(int key[], int size, int x) {
    for (int i = 0; i < size; ++i)
        if (key[i] == x)
            return i;
    return -1;
}

void arrange(int a[], int left, int right) {
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

void uniqueElements (int a[50][50], int n, int m) {
    int key[MAX_UNIQUE] {0};
    int count[MAX_UNIQUE] {0};
    int size = 0; 

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int index = findIndex (key, size, a[i][j]);

            if (index != -1) {
                count[index]++;
            }else {
                if (size < MAX_UNIQUE) {
                key[size] = a[i][j];
                count[size] = 1;
                size++;
            }
            }
        }
    }

    bool flag = false;
    int *res = new int[size] {0};
    int idx = 0;
    for (int i = 0; i < size; ++i) {
        if (count[i] == 1) {
            res[idx++] = key[i];
        }
    }

    if (idx == 0) {
         cout << "No unique element in the matrix";
         return;
    }

    arrange (res, 0, idx -1);
    cout << "Unique elements in the matrix:\n";
    for (int i = 0; i < idx; ++i) {
        cout << res[i] << " ";
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



