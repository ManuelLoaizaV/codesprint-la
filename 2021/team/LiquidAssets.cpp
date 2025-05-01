// https://open.kattis.com/problems/liquidassets
#include <iostream>
#include <set>
#include <string>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int N;
    std::cin >> N;
    std::set<char> vowels{'a', 'e', 'i', 'o', 'u'};
    for (int n = 0; n < N; ++n) {
        if (n > 0) std::cout << ' ';
        std::string s;
        std::cin >> s;
        std::string t;
        for (int i = 0; i < s.size(); ++i) {
            if (t.empty() || t.back() != s[i]) {
                t.push_back(s[i]);
            }
        }
        std::string u;
        for (int j = 0; j < t.size(); ++j) {
            if (0 < j && j < t.size() - 1 && vowels.count(t[j])) continue;
            u.push_back(t[j]);
        }
        std::cout << u;
    }
    std::cout << std::endl;
    return 0;
}