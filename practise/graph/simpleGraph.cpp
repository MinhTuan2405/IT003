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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
	int v, e, n; //v: số đỉnh, e: số cạnh, n: số thao tác
	cin >> v >> e >> n;

	bool **G; // ma trận toàn số 0, 1 nên kiểu bool hay int đều được
	G=new bool*[v];

    for (int i = 0; i < v; ++i) {
        G[i] = new bool[v] {false};
    }

    inputGraph (G, e);

    // for (int i = 0; i < v; ++i) {
    //     for (int j = 0; j < v; ++j) {
    //         cout << G[i][j] <<  " ";
    //     }
    //     cout << endl;
    // }

    process (G, v, n);
    return 0;



//###INSERT CODE HERE -
}

void inputGraph(bool* a[], int e) {
    for (int i = 0; i < e; ++i) {
        int u, v; cin >> u >> v;
        a[u-1][v-1] = 1;
    }
}

void process(bool* a[], int v, int n) {
    for (int i = 0; i < n; ++i) {
        int signal; cin >> signal;

        if (signal == 2) {
            int neighbor; cin >> neighbor;
            bool hasANeighbor = false;
            for (int k = 0; k < v; ++k) {
                if (a[neighbor-1][k]) {
                    cout << k + 1 << " ";
                    hasANeighbor = true;
                }

            }
            if (!hasANeighbor) cout << "NONE";
            cout << '\n';
        }else if (signal == 1) {
            int u, i; cin >> u >> i;
            if (a[u-1][i-1]) cout << "TRUE\n";
            else cout << "FALSE\n";
        }
    }
}

