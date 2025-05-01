// https://open.kattis.com/problems/efficiency
#include <iostream>
#include <vector>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    long long P, M;
    std::cin >> P >> M;
    std::vector<std::string> words{
        "Efficiency", "Unbreaking", "Silk", "Touch"
    };
    long long N{0};
    long long w{3};
    long long cnt{0};
    long long i{1};
    while (i <= M) {
        if (w <= 1) {
            if (cnt < N) {
                ++cnt;
            } else {
                ++w;
                cnt = 1;
            }
        } else if (w == 2) {
            ++w;
        } else if (w == 3) {
            if (cnt < N) {
                --w;
                ++cnt;
            } else {
                w = 0;
                cnt = 1;
                ++N;
            }
        }
        ++i;
    }

    i = 0LL;
    long long acc{0LL};
    while (acc < M) {
        ++i;
        acc += 4LL * i;
    }
    long long who{(acc - 1LL) % P + 1LL};

    std::cout << words[w] << std::endl << who << std::endl;
    return 0;
}