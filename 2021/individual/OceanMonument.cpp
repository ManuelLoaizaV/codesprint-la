// https://open.kattis.com/problems/oceanmonument
#include <algorithm>
#include <iostream>
#include <limits>

const int N{42};
int min_memo[N][N];
bool min_done[N][N];
long long cnt_memo[N][N];
bool cnt_done[N][N];

int Min(int g, int e) {
    if (g == 0 && e == 0) return 0;
    if (g <= 2 && e == 0) return 1;
    if (min_done[g][e]) return min_memo[g][e];
    min_memo[g][e] = std::numeric_limits<int>::max();
    if (e > 0) {
        min_memo[g][e] = std::min(
            min_memo[g][e],
            1 + Min(g + 1, e - 1)
        );
    }
    if (g > 1) {
        min_memo[g][e] = std::min(
            min_memo[g][e],
            1 + Min(g - 1, e)
        );
    }
    min_done[g][e] = true;
    return min_memo[g][e];
}

long long Count(int g, int e) {
    if (g == 0 && e == 0) return 1LL;
    if (g <= 2 && e == 0) return 1LL;
    if (cnt_done[g][e]) return cnt_memo[g][e];
    cnt_memo[g][e] = 0LL;
    if (e > 0 && Min(g, e) == 1 + Min(g + 1, e - 1)) {
        cnt_memo[g][e] += Count(g + 1, e - 1);
    }
    if (g > 1 && Min(g, e) == 1 + Min(g - 1, e)) {
        cnt_memo[g][e] += Count(g - 1, e);
    }
    cnt_done[g][e] = true;
    return cnt_memo[g][e];
}

void Solve(void) {
    int g, e;
    std::cin >> g >> e;
    std::cout << Count(g, e) << std::endl;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) Solve();
    return 0;
}