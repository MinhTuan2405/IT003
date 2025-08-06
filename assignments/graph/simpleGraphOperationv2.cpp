
#include <bits/stdc++.h>
using namespace std;

//###INSERT CODE HERE -
class Graph {
public:
    map <string, set <string>> graph;


    Graph() {}

    void nhap(int numberOfEdge) {
        for (int i = 0; i < numberOfEdge; ++i) {
            string u, w;
            cin >> u >> w;
            graph[u].insert (w);
        }
    }

    void myProcess(int n) {
        for (int i = 0; i < n; ++i) {
            int signal;
            cin >> signal;

            if (signal == 2) {
                string name;
                cin >> name;
                cout << graph[name].size ();
            } else if (signal == 1) {
                string u, w;
                cin >> u >> w;
                if (graph[u].find (w) != graph[u].end ()) cout << "TRUE";
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
    int e, n;
    cin >> e >> n;
    G.nhap(e);
    G.myProcess(n);
    return 0;
}
