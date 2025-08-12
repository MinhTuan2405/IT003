#include <bits/stdc++.h>
using namespace std;

/*
    Class Graph - C++11 compatible
    Lưu đồ thị bằng danh sách kề (adjacency list) dạng:
        adj[u] = vector<pair<int,int>> {đỉnh kề, trọng số}
    Hỗ trợ:
        1. BFS shortest distance (unweighted)
        2. Dijkstra shortest distance (weighted)
        3. BFS shortest path (in ra đường đi ngắn nhất, unweighted)
        4. Dijkstra shortest path (in ra đường đi ngắn nhất, weighted)
*/
class Graph {
public:
    int v, e; // số đỉnh, số cạnh
    vector<vector<pair<int,int>>> adj; // {đỉnh kề, trọng số}
    vector<int> visited;

    Graph(int v=0, int e=0) : v(v), e(e), adj(v), visited(v,0) {}

    // Nhập đồ thị
    void inputList(int v, int e, bool weighted=false) {
        this->v = v;
        this->e = e;
        adj.assign(v, vector<pair<int,int>>());
        visited.assign(v, 0);

        for (int i = 0; i < e; i++) {
            if (!weighted) {
                int u, w;
                cin >> u >> w;
                int weight = 1; // mặc định không trọng số
                adj[u].push_back(make_pair(w, weight));
                adj[w].push_back(make_pair(u, weight));
            } else {
                int u, w, weight;
                cin >> u >> w >> weight;
                adj[u].push_back(make_pair(w, weight));
                adj[w].push_back(make_pair(u, weight));
            }
        }
    }

    void reset_visited() {
        fill(visited.begin(), visited.end(), 0);
    }

    // 1. BFS shortest distance (unweighted)
    vector<int> bfs_shortest(int start) {
        vector<int> dist(v, INT_MAX);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (size_t i = 0; i < adj[u].size(); i++) {
                int nb = adj[u][i].first;
                // int w = adj[u][i].second; // không dùng vì unweighted
                if (dist[nb] == INT_MAX) {
                    dist[nb] = dist[u] + 1;
                    q.push(nb);
                }
            }
        }
        return dist;
    }

    // 2. Dijkstra shortest distance (weighted)
    vector<int> dijkstra_shortest(int start) {
        vector<int> dist(v, INT_MAX);
        dist[start] = 0;

        typedef pair<int,int> pii; // {khoảng cách, đỉnh}
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push(make_pair(0, start));

        while (!pq.empty()) {
            int du = pq.top().first;
            int u  = pq.top().second;
            pq.pop();

            if (du > dist[u]) continue;

            for (size_t i = 0; i < adj[u].size(); i++) {
                int nb = adj[u][i].first;
                int w  = adj[u][i].second;
                if (dist[nb] > dist[u] + w) {
                    dist[nb] = dist[u] + w;
                    pq.push(make_pair(dist[nb], nb));
                }
            }
        }
        return dist;
    }

    // 3. BFS shortest path (unweighted)
    vector<int> bfs_path(int start, int target) {
        vector<int> dist(v, INT_MAX), parent(v, -1);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (size_t i = 0; i < adj[u].size(); i++) {
                int nb = adj[u][i].first;
                if (dist[nb] == INT_MAX) {
                    dist[nb] = dist[u] + 1;
                    parent[nb] = u;
                    q.push(nb);
                }
            }
        }

        if (dist[target] == INT_MAX) return vector<int>();

        vector<int> path;
        for (int cur = target; cur != -1; cur = parent[cur])
            path.push_back(cur);
        reverse(path.begin(), path.end());
        return path;
    }

    // 4. Dijkstra shortest path (weighted)
    vector<int> dijkstra_path(int start, int target) {
        vector<int> dist(v, INT_MAX), parent(v, -1);
        dist[start] = 0;

        typedef pair<int,int> pii;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push(make_pair(0, start));

        while (!pq.empty()) {
            int du = pq.top().first;
            int u  = pq.top().second;
            pq.pop();

            if (du > dist[u]) continue;

            for (size_t i = 0; i < adj[u].size(); i++) {
                int nb = adj[u][i].first;
                int w  = adj[u][i].second;
                if (dist[nb] > dist[u] + w) {
                    dist[nb] = dist[u] + w;
                    parent[nb] = u;
                    pq.push(make_pair(dist[nb], nb));
                }
            }
        }

        if (dist[target] == INT_MAX) return vector<int>();

        vector<int> path;
        for (int cur = target; cur != -1; cur = parent[cur])
            path.push_back(cur);
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin >> v >> e;
    Graph g;
    
    // Nhập đồ thị có trọng số (weighted = true)
    g.inputList(v, e, true);

    // 1. BFS shortest distance
    vector<int> dist_bfs = g.bfs_shortest(0);
    cout << "BFS distance: ";
    for (size_t i = 0; i < dist_bfs.size(); i++) cout << dist_bfs[i] << " ";
    cout << "\n";

    // 2. Dijkstra shortest distance
    vector<int> dist_dij = g.dijkstra_shortest(0);
    cout << "Dijkstra distance: ";
    for (size_t i = 0; i < dist_dij.size(); i++) cout << dist_dij[i] << " ";
    cout << "\n";

    // 3. BFS shortest path
    vector<int> path_bfs = g.bfs_path(0, v-1);
    cout << "BFS path: ";
    for (size_t i = 0; i < path_bfs.size(); i++) cout << path_bfs[i] << " ";
    cout << "\n";

    // 4. Dijkstra shortest path
    vector<int> path_dij = g.dijkstra_path(0, v-1);
    cout << "Dijkstra path: ";
    for (size_t i = 0; i < path_dij.size(); i++) cout << path_dij[i] << " ";
    cout << "\n";

    return 0;
}
