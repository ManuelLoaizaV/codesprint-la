// https://open.kattis.com/problems/upandaway
#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

const int INF{std::numeric_limits<int>::max()};
const int N{101};
int h[N];
int d[N][N];
int w[N][N];

void Dijkstra(int s, int k, int n) {
    for (int u = 0; u < n; ++u) {
        for (int c = 0; c <= k; ++c) {
            d[u][c] = INF;
        }
    }
    d[s][k] = 0;
    std::priority_queue<
        std::pair<int, std::pair<int, int>>,
        std::vector<std::pair<int, std::pair<int, int>>>,
        std::greater<std::pair<int, std::pair<int, int>>>
    > q;
    q.push({0, {s, k}});

    while (!q.empty()) {
        auto cur{q.top()};
        q.pop();
        int best = cur.first;
        int u = cur.second.first;
        int c = cur.second.second;
        if (best != d[u][c]) continue;
        for (int v = 0; v < n; ++v) {
            if (u == v) continue;
            int nxt_best = best + w[u][v];
            int up = h[v] - h[u];
            if (up <= 0 && nxt_best < d[v][c]) {
                d[v][c] = nxt_best;
                q.push({nxt_best, {v, c}});
            }
            if (up > 0 && c >= up && nxt_best < d[v][c - up]) {
                d[v][c - up] = nxt_best;
                q.push({nxt_best, {v, c - up}});
            }
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, x, k;
    std::cin >> n >> x >> k;
    --x;
    for (int i = 0; i < n; ++i) std::cin >> h[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> w[i][j];
        }
    }

    Dijkstra(0, k, n);

    int mn = INF;
    for (int c = 0; c <= k; ++c) {
        mn = std::min(mn, d[x][c]);
    }

    std::cout << (mn < INF ? mn : -1) << std::endl;
    return 0;
}