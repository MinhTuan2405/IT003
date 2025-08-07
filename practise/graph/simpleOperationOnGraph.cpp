// /*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
// define
// include
// using
// ###End banned keyword*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

//###INSERT CODE HERE -
class Graph {
public:
    int v, e;
    vector<vector<int>> graph;
    vector<string> index_to_name;
    map<string, int> name_to_index;

    Graph() {
        v = 0;
        e = 0;
    }

    void nhap(int numberOfVertex, int numberOfEdge) {
        v = numberOfVertex;
        e = numberOfEdge;
        index_to_name.resize(v);
        graph.assign(v, vector<int>(v, 0));

        for (int i = 0; i < v; ++i) {
            string name;
            cin >> name;
            name_to_index[name] = i;
            index_to_name[i] = name;
        }

        for (int i = 0; i < e; ++i) {
            string u, w;
            cin >> u >> w;
            int u1 = name_to_index[u];
            int u2 = name_to_index[w];
            graph[u1][u2] = 1;
        }
    }

    void myProcess(int n) {
        for (int i = 0; i < n; ++i) {
            int signal;
            cin >> signal;

            if (signal == 2) {
                string name;
                cin >> name;
                int idx = name_to_index[name];
                bool hasNeighbor = false;

                for (int k = 0; k < v; ++k) {
                    if (graph[idx][k]) {
                        cout << index_to_name[k] << " ";
                        hasNeighbor = true;
                    }
                }

                if (!hasNeighbor) cout << "NONE";
            } else if (signal == 1) {
                string u, w;
                cin >> u >> w;
                int u1 = name_to_index[u];
                int u2 = name_to_index[w];
                if (graph[u1][u2]) cout << "TRUE";
                else cout << "FALSE";
            }

            cout << "\n";
        }
    }
};


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Graph G;
    int v, e, n;
    std::cin >> v >> e >> n;
    G.nhap(v, e);
    G.myProcess(n);
    return 0;
}
