#include <bits/stdc++.h>

using namespace std;

class graph {
    public:
        int v;
        int e;
        vector <vector <int>> matrix;
        vector <vector <int>> list;
        vector <int> visted;

        graph ():
            v (0),
            matrix (vector <vector <int>> (0)),
            list (vector <vector <int>> (0)),
            visted  (vector <int> (0))   {};

        void inputMatrix (int v, int e) {
            this -> v = v;
            this -> e = e;
            matrix.assign (v, vector <int> (v, 0));
            list.resize (v);
            visted.assign (v, 0);
            for (int i = 0; i < v; ++i) {
                for (int j = 0; j < v; ++j) {
                    int x; cin >> x;
                    matrix[i][j] = x;
                    if (x == 1) list[i].push_back (j);
                }
            }   
        }

        void inputList (int v, int e) {
            this -> v = v;
            this -> e = e;
            matrix.assign (v, vector <int> (v, 0));
            list.resize (v);
            visted.assign (v, 0);
            for (int i = 0; i < e; ++i) {
                int u, w; cin >> u >> w;
                matrix[u][w] = 1;
                matrix[w][u] = 1;
                list[u].push_back (w);
                list[w].push_back (u);
            }   
        }

        void dfs (int start) {
            visted[start] = 1;
            for (auto neigbors : list[start]) {
                if (!visted[neigbors]) {
                    visted[neigbors] = 1;
                    dfs (neigbors);
                }
            }
        }

        void dfs_non_recursive (int start) {
            stack <int> bucket;
            bucket.push (start);
            visted[start] = 1;
            while (!bucket.empty ()) {
                int top = bucket.top ();
                bucket.pop ();
                for (auto neigbors : list[top]) {
                    if (!visted[neigbors]) {
                        visted[neigbors] = 1;
                        bucket.push (neigbors);
                    }
                }
            }
        }

        void bfs(int start) {
            queue<int> q;
            visted[start] = 1;
            q.push(start);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (auto neighbor : list[u]) {
                    if (!visted[neighbor]) {
                        visted[neighbor] = 1;
                        q.push(neighbor);
                    }
                }
            }
        }


        int count_components () {
            int count = 0;
            for (int i = 0; i < v; ++i) {
                if (!visted[i]) {
                    count += 1;
                    dfs (i);
                }
            }
            return count;
        }

        int isolated_edges () {
            int count = 0;
            for (auto row : list) if (row.size () == 0) count += 1;
        
            return count;
        }

        void reset_visited () {
            visted.assign (v, 0);
        }


        vector <int> destination (int from = 0) {
            reset_visited ();

            bfs (from);

            vector <int> destis;
            for (int i = 0; i < v; ++i) 
                if (visted[i] && i != from) 
                    destis.push_back (i);

            return destis;
        }

        vector <string> destination_status (int from = 0) {
            reset_visited ();
            bfs (from);

            vector <string> status (v, "KHONG");
            status[from] = "NONE";
            for (int i = 0; i < v; ++i) {
                if (visted[i] && i != from) {
                    status[i] = "CO";
                }
            }

            return status;
        }

        void print (bool print_matrix= false) {
            if (print_matrix) {
                for (auto i : matrix) {
                    for (auto j : i) cout << j << " ";
                    cout << '\n';
                }
            }
            else {
                for (int i = 0; i < list.size (); ++i) {
                    if (list[i].size () == 0) continue;

                    cout << i << "->";
                    for (auto edge : list[i]) cout << edge << " ";
                    cout << '\n';
                }
            }
        }
};

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);

    int v, e; cin >> v >> e;
    graph* gr = new graph ();
    gr -> inputList (v, e);
    // gr -> print (true);
    // gr -> print ();
    // cout << gr->isolated_edges();

    vector <string> destinations = gr -> destination_status ();
    for (auto i : destinations) if (i != "NONE") cout << i << '\n';
    return 0;
}