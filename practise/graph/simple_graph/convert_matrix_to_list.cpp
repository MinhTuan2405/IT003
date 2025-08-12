#include <bits/stdc++.h>

using namespace std;

class graph {
    public:
        int v;
        vector <vector <int>> matrix;
        vector <vector <int>> list;

        graph ():
            v (0),
            matrix (vector <vector <int>> (0)),
            list (vector <vector <int>> (0))    {};

        void input (int v) {
            this -> v = v;
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

        void print_list () {
            for (auto i : matrix) {
                for (auto j : i) cout << j << " ";
                cout << '\n';
            }
            for (int i = 0; i < list.size (); ++i) {
                if (list[i].size () == 0) continue;

                cout << i + 1 << "->";
                for (auto edge : list[i]) cout << edge + 1 << " ";
                cout << '\n';
            }
        }
};

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);

    int v; cin >> v;
    graph* gr = new graph ();
    gr -> input (v);
    gr -> print_list ();
    return 0;
}