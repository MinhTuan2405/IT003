#include <bits/stdc++.h>

using namespace std;

class graph {
    public:
        int v;
        int e;
        vector <vector <int>> list;
        vector <int> visted;

        graph ():
            v (0),
            list (vector <vector <int>> (0)),
            visted  (vector <int> (0))   {};

        void inputList (int v, int e) {
            this -> v = v;
            this -> e = e;
            list.resize (v);
            visted.assign (v, 0);
            for (int i = 0; i < e; ++i) {
                int u, w; cin >> u >> w;
                u -= 1;
                w -= 1;
                list[u].push_back (w);
                list[w].push_back (u);
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

        void reset_visited () {
            visted.assign (v, 0);
        }


        vector <int> victim_list (int victim) {
            reset_visited ();
            victim -= 1;
            dfs_non_recursive (victim);
            vector <int> l;
            for (int i = 0; i <  v; ++i) {
                if (visted[i]) l.push_back (i+1);
            }

            return l;
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
    int victim; cin >> victim;
    vector <int> victim_list = gr -> victim_list (victim);
    cout << victim_list.size () << '\n';
    for (auto k : victim_list) cout << k << " ";
    return 0;
}