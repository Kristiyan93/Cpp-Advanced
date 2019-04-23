#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> split(std::string text, char separator) {
    std::vector<std::string> vec;

    std::ostringstream oss;

    for (char c : text) {
        if (c == separator) {
            vec.push_back(oss.str());

            oss.str("");
            oss.clear();
        } else {
            oss << c;
        }
    }

    return vec;
}

int main() {
    std::vector<std::string> (*p)(std::string, char) = split;

    // p = split also works, the & is optional in this case

    std::vector<std::string> words = p("the quick brown fox jumps over the lazy dog", ' ');

    for (std::string w : words) {
        std::cout << w << std::endl;
    }

    return 0;
}