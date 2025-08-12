#include <bits/stdc++.h>

using namespace std;

class graph {
    public:
        int e;
        map <string, vector <string>> mp;

        graph (): e (0) {};

        void input (int e) {
            e = e;
            for (int i = 0; i < e; ++i) {
                string u, w; cin >> u >> w;
                mp[u].push_back(w);
            }
        }

        void process (int n) {
            for (int i = 0; i < n; ++i) {
                int cmd; cin >> cmd;
                if (cmd == 1) {
                    string u, w; cin >> u >> w;
                    bool find = false;
                    for (auto key : mp[u]) if (key == w) find = true;

                    if (find) cout << "TRUE"; 
                    else cout << "FALSE";
                }
                else if (cmd == 2) {
                    string u; cin >> u;
                    cout << mp[u].size();
                }
                cout << '\n';
            }
        }
};

int main () {
    int e, n; cin >> e >> n;
    graph* gr = new graph ();
    gr -> input (e);
    gr -> process (n);
    return 0;
}