/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<iostream>
#include<vector>
using namespace std;

//###INSERT CODE HERE -
void inputGraph (vector <vector <int>> &graph, int v, int e) {
    graph.resize(v, std::vector<int>(v, 0));

    for (int i = 0; i < e; ++i) {
        int u, v; cin >> u >> v;
        graph[u-1][v-1] = 1;
    }
}

void print (vector <vector <int>> graph) {
    for (auto r : graph) {
        for (auto i : r) 
            cout << i << " ";
        cout << endl;
    }
}

void process(vector <vector <int>> a, int v, int n) {
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


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
	int v, e, n;
	cin >> v >> e >> n; //v: số đỉnh, e: số cạnh, n: số thao tác
	vector<vector<int> > G;

	inputGraph(G,v,e);
    print (G);
    process(G,v,n);

	return 0;
}
