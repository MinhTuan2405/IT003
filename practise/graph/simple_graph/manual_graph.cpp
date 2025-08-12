/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<iostream>
using namespace std;

void inputGraph(bool*[], int);
void process(bool*[], int, int);



int main()
{
	int v, e, n; //v: số đỉnh, e: số cạnh, n: số thao tác
	cin >> v >> e >> n;

	bool **G; // ma trận toàn số 0, 1 nên kiểu bool hay int đều được
	G=new bool*[v];

    for (int i = 0; i < v; ++i) G[i] = new bool[v] {false};
    inputGraph (G, e);
    process (G, v, n);

    return 0;

//###INSERT CODE HERE -
}

void inputGraph (bool *a[], int n) {
    for (int i = 0; i < n; ++i) {
        int u, v; cin >> u >> v;
        a[u-1][v-1] = true;
    }
}

void process (bool *a[], int v, int n) {
    for (int i = 0; i < n; ++i) {
        int command; cin >> command;

        if (command == 1) {
            int u, v; cin >> u >> v;
            if (a[u-1][v-1]) cout << "TRUE";
            else cout << "FALSE";

            cout << '\n';
        }

        else if (command == 2) {
            int u; cin >> u;
            bool find = false;
            for (int i = 0; i < v; ++i) {
                if (a[u-1][i] == true) {
                    find = true;
                    cout << i + 1 << " ";
                }
            }
            if (!find) cout << "NONE";  
            cout << '\n';
        } 
    }
}