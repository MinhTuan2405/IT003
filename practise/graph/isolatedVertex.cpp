#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    vector<vector<int>> list;
    int v, e;

    Graph() {
        v = e = 0;
    }

    void inputMatrix() {
        cin >> v >> e;
        list.resize(v);
        for (int i = 0; i < e; ++i) {
            int u, w;
            cin >> u >> w;
            u; w;
            list[u].push_back(w);
        }
    }

    int numberOfIsolatedVertices() {
        vector<bool> hasIncEdge(v, false);

        for (int u = 0; u < v; ++u) {
            for (int w : list[u]) {
                hasIncEdge[w] = true;
            }
        }

        int isolated = 0;
        for (int i = 0; i < v; ++i) {
            if (list[i].empty() && !hasIncEdge[i]) {
                ++isolated;
            }
        }
        return isolated;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);

    Graph graph;
    graph.inputMatrix();
    cout << graph.numberOfIsolatedVertices() << '\n';

    return 0;
}
