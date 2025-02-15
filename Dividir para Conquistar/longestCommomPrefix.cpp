#include <iostream>
#include <vector>
#include <algorithm>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if (strs.empty()) return "";

    std::sort(strs.begin(), strs.end());
    std::string first = strs.front(), last = strs.back();
    int i = 0;
    while (i < first.size() && first[i] == last[i]) i++;

    return first.substr(0, i);
}

int main() {
    std::vector<std::string> words = {"flower", "flow", "flight"};
    std::cout << "Longest Common Prefix: " << longestCommonPrefix(words) << std::endl;
    return 0;
}
