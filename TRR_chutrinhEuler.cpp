#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100;

int n;
int start;
int graph[MAX][MAX];
int degree[MAX];
vector<int> circuit;

void dfs(int u) {
    for (int v = 0; v < n; v++) {
        if (graph[u][v] > 0) {
            graph[u][v]--;
            graph[v][u]--;
            dfs(v);
        }
    }
    circuit.push_back(u);
}

int main() {;
    cin >> n;
    cin >> start;
    start--;
    int odd_degrees = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            degree[i] += graph[i][j];
        }
        if (degree[i] % 2 == 1) {
            odd_degrees++;
        }
    }
    if (odd_degrees != 0 && odd_degrees != 2) {
        cout << "No Euler circuit or path" << endl;
        return 0;
    }
    dfs(start);
    for (int i = circuit.size() - 1; i >= 0; i--) {
        cout << circuit[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}