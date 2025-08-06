#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
        vector <vector <int>> matrix;
        vector <vector <int>> list;

        int v;
        Graph () {
            matrix.resize (0);
            list.resize (0);
            v = 0;
        }

        void print (bool isList = true) {
            if (isList) {
                int idx = 1;
                for (auto row : list) {
                    vector <int> l;
                    l.resize (0);
                    for (auto i : row) l.push_back (i);

                    if (l.size () == 0) {
                        idx++;
                        continue;
                    }
                    cout << idx++ << "->";
                    for (auto value : l) cout << value + 1 << " ";
                    cout << '\n';
                }
            }else {
                for (auto row : matrix) {
                    for (auto i : row) cout << i << " ";
                    cout << endl;
                }
            }
        }

        void inputMatrix () {
            cin >> v;
            matrix.assign (v, vector <int> (v, 0));
            list.resize (v);
            for (int i = 0; i < v; ++i) {
                for (int j = 0; j < v; ++j) {
                    int x; cin >> x;
                    matrix[i][j] = x;
                    if (x == 1) list[i].push_back (j);
                }
            }
        }   
};

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    Graph graph;
    graph.inputMatrix ();
    graph.print ();

    return 0;
}