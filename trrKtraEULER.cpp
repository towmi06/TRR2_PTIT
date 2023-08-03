#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1005;

int T, V, E;
vector<int> graph[MAX];

void add_edge(int u, int v) {
    graph[u].push_back(v);
}

void remove_edge(int u, int v) {
    for (int i = 0; i < graph[u].size(); i++) {
        if (graph[u][i] == v) {
            graph[u].erase(graph[u].begin() + i);
            break;
        }
    }
}

void fleury(int u, vector<int> &path) {
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        remove_edge(u, v);
        fleury(v, path);
    }
    path.push_back(u);
}

bool is_eulerian() {
    // Tính bậc vào và bậc ra của các đỉnh
    int in_degree[MAX] = {0}, out_degree[MAX] = {0};
    for (int u = 1; u <= V; u++) {
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            out_degree[u]++;
            in_degree[v]++;
        }
    }
    // Kiểm tra tính liên thông của đồ thị
    bool visited[MAX] = {false};
    int count = 0;
    for (int u = 1; u <= V; u++) {
        if (!graph[u].empty()) {
            count++;
            if (count > 1) {
                return false;
            }
            vector<int> stack;
            stack.push_back(u);
            visited[u] = true;
            while (!stack.empty()) {
                int v = stack.back();
                stack.pop_back();
                for (int i = 0; i < graph[v].size(); i++) {
                    int w = graph[v][i];
                    if (!visited[w]) {
                        visited[w] = true;
                        stack.push_back(w);
                    }
                }
            }
        }
    }
    // Kiểm tra bậc vào và bậc ra của các đỉnh
    for (int u = 1; u <= V; u++) {
        if (in_degree[u] != out_degree[u]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> V >> E;
        for (int i = 1; i <= V; i++) {
            graph[i].clear();
        }
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            add_edge(u, v);
        }
        if (!is_eulerian()) {
            cout << "0\n";
            continue;
        }
        int start = 1;
        for (int u = 1; u <= V; u++) {
            if (!graph[u].empty()) {
                start = u;
                break;
            }
        }
        vector<int> path;
        fleury(start, path);
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
