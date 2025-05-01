// https://open.kattis.com/problems/sharingcandies
#include <iostream>
#include <unordered_map>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    long long n;
    std::cin >> n;

    long long acc{0LL};
    std::unordered_map<int, int> prev;
    prev[0] = 0;
    for (int i = 1; i <= n; ++i) {
        long long c;
        std::cin >> c;
        acc += c;
        int r = acc % n;
        if (prev.count(r) == 0) {
            prev[r] = i;
        } else {
            int from{prev[r] + 1};
            int cnt{i - from + 1};
            std::cout << cnt << std::endl;
            for (int j = from; j <= i; ++j) {
                if (j > from) std::cout << ' ';
                std::cout << j;
            }
            std::cout << std::endl;
            break;
        }
    }
    return 0;
}