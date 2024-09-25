#include <iostream>
#include <functional>
#include <unordered_set>

int main() {
    std::unordered_set<std::string> set;

    set.insert("hello");
    set.insert("world");

    for (const std::string& str : set) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}