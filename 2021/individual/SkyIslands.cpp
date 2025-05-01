// https://open.kattis.com/problems/skyislands
#include <iostream>
#include <vector>

const int N{900};

bool visited[N];
std::vector<int> adj[N];

void DFS(int u) {
    visited[u] = true;
    for (const auto& v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, m;
    std::cin >> n >> m;

    while (m--) {
        int u, v;
        std::cin >> u >> v;
        adj[u - 1].push_back(v - 1);
    }

    DFS(0);

    bool connected{true};
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            connected = false;
            break;
        }
    }

    std::cout << (connected ? "YES" : "NO") << std::endl;
    return 0;
}