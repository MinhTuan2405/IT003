/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<iostream>
#include<vector>
using namespace std;

//###INSERT CODE HERE -
void inputGraph (vector <vector <int>> &a, int v, int e) {
    a.assign (v, vector <int> (v, 0));
    
    for (int i = 0; i < e; ++i) {
        int u, w; cin >> u >> w;
        a[u-1][w-1] = 1;
    }

}

void process (vector <vector <int>> &a, int v, int n) {
    for (int i = 0; i < n; ++i) {
        int command; cin >> command;

        if (command == 1) {
            int u, w; cin >> u >> w;
            if (a[u-1][w-1]) cout << "TRUE";
            else cout << "FALSE";

            cout << '\n';
        }

        else if (command == 2) {
            int u; cin >> u;
            bool find = false;
            for (int i = 0; i < v; ++i) {
                if (a[u-1][i] == 1) {
                    find = true;
                    cout << i + 1 << " ";
                }
            }
            if (!find) cout << "NONE";  
            cout << '\n';
        } 
    }
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);

	int v, e, n;
	cin >> v >> e >> n; //v: số đỉnh, e: số cạnh, n: số thao tác
	vector<vector<int> > G;

	inputGraph(G,v,e);
    process(G,v,n);

	return 0;
}
