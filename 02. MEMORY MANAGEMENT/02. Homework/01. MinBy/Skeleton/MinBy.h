#ifndef DEMO_MINBY_H
#define DEMO_MINBY_H

#include <vector>

std::string minBy(std::vector<std::string> &vec, bool (*p)(const std::string& a, const std::string& b)) {
    std::string result = vec[0];

    for (int i = 1; i < vec.size(); ++i) {
        if (p(vec.at(i), result)) {
            result = vec[i];
        }
    }

    return result;
}

#endif //DEMO_MINBY_H
