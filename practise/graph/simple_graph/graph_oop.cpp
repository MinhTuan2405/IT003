/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

//###INSERT CODE HERE -
class Graph {
    public:
        int v, e;
        map<string, vector<string>> graph;
        vector<string> label;
        map<string, int> pos; // ánh xạ tên -> chỉ số

        Graph() {
            v = 0;
            e = 0;
        }

        void nhap(int nv, int ne) {
            v = nv; e = ne;
            for (int i = 0; i < v; ++i) {
                string x; 
                cin >> x;
                label.push_back(x);
                pos[x] = i; // lưu vị trí
            }

            for (int i = 0; i < e; ++i) {
                string u, w; 
                cin >> u >> w;
                graph[u].push_back(w);
            }
        }

        bool has_relationship(string u, string w) {
            for (auto &value : graph[u])
                if (w == value) return true;
            return false;
        }

        void myProcess(int n) {
            for (int i = 0; i < n; ++i) {
                int command; 
                cin >> command;

                if (command == 1) {
                    string u, w; 
                    cin >> u >> w;
                    if (has_relationship(u, w)) cout << "TRUE";
                    else cout << "FALSE";
                }
                else if (command == 2) {
                    string u; 
                    cin >> u;

                    vector<int> mark(v, 0);
                    for (auto &w : graph[u]) {
                        mark[pos[w]] = 1; // O(1)
                    }

                    bool found = false;
                    for (int idx = 0; idx < v; ++idx) {
                        if (mark[idx]) {
                            cout << label[idx] << " ";
                            found = true;
                        }
                    }

                    if (!found) cout << "NONE";
                }
                cout << '\n';
            }
        }
};


int main()
{
    Graph G;
    int v, e, n; cin >> v >> e >> n;
    G.nhap(v, e);
    G.myProcess(n);
    return 0;
}

