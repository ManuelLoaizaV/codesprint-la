// https://open.kattis.com/problems/speedrun
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int G, N;
    std::cin >> G >> N;
    std::vector<std::pair<int, int>> t(N);
    for (auto& p : t) {
        std::cin >> p.first >> p.second;
    }
    std::sort(
        t.begin(),
        t.end(),
        [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        }
    );
    int cnt{0};
    int last{-1};
    for (int i = 0; i < N; ++i) {
        if (t[i].first >= last) {
            ++cnt;
            last = t[i].second;
        }
    }

    std::cout << (cnt >= G ? "YES" : "NO") << std::endl;
    return 0;
}