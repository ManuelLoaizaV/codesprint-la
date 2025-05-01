// https://open.kattis.com/problems/babypanda
#include <iostream>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    long long n, m;
    std::cin >> n >> m;
    long long cnt{0LL};
    while (m > 0) {
        if (m & 1LL) {
            ++cnt;
        }
        m >>= 1LL;
    }
    std::cout << cnt << std::endl;
    return 0;
}