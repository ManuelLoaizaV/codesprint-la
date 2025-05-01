// https://open.kattis.com/problems/cheatingstudents
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

const int N{2000};

struct DisjointSets {
    int parent[N];
    int size[N];
    void MakeSet(int u) {
        parent[u] = u;
        size[u] = 1;
    }
    void Build(int n) { for (int i = 0; i < n; i++) MakeSet(i); }
    int Find(int u) {
        if (parent[u] == u) return u;
        return (parent[u] = Find(parent[u]));
    }
    void Join(int u, int v) {
        u = Find(u);
        v = Find(v);
        if (u != v) {
            if (size[u] > size[v]) std::swap(u, v);
            parent[u] = v;
            size[v] += size[u];
        }
    }
    bool SameSet(int u, int v) { return Find(u) == Find(v); }
    int GetSize(int u) { return size[Find(u)]; }
} dsu;

typedef std::pair<int, std::pair<int, int>> Edge;
std::vector<Edge> edges, mst;

int MST(int n) {
    dsu.Build(n);
    long long cost{0LL};
    std::sort(edges.begin(), edges.end());
    for (const auto& edge : edges) {
        auto w = edge.first;
        auto u = edge.second.first;
        auto v = edge.second.second;
        if (!dsu.SameSet(u, v)) {
            mst.push_back(edge);
            dsu.Join(u, v);
            cost += w;
        }
    }
    return cost;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> p(n);
    for (auto& e : p) {
        std::cin >> e.first >> e.second;
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int d = std::abs(p[i].first - p[j].first) + std::abs(p[i].second - p[j].second);
            edges.push_back({d, {i, j}});
        }
    }

    std::cout << 2 * MST(n) << std::endl;
    return 0;
}