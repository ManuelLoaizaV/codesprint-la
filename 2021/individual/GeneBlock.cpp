// https://open.kattis.com/problems/geneblock
#include <iostream>
#include <utility>
#include <vector>

std::vector<std::pair<int, int>> opt(10);

void Solve(void) {
    int n;
    std::cin >> n;
    auto best = opt[n % 10];
    if (n < best.second) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << best.first << std::endl;
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    for (int i = 1; i <= 10; ++i) {
        int min_value = i * 7;
        int last_digit = min_value % 10;
        opt[last_digit] = {i, min_value};
    }
    int t;
    std::cin >> t;
    while (t--) Solve();
    return 0;
}