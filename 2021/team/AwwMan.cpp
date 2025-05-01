// https://open.kattis.com/problems/awwman
#include <iostream>

void Solve(void) {
    long long N, M;
    std::cin >> N >> M;
    long long a, b, d;
    std::cin >> a >> b >> d;

    long long T{b - a};
    if (T <= 0) T += N;

    long long when{(b - 1LL + d + T) % N + 1};
    std::cout << (when <= N - M ? "YES" : "NO") << std::endl;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) Solve();
    return 0;
}