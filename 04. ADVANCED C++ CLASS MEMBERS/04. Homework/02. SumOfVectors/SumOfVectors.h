#ifndef SUM_OF_VECTORS_SUMOFVECTORS_H
#define SUM_OF_VECTORS_SUMOFVECTORS_H

#include <vector>
#include <string>

std::vector<std::string> operator+(const std::vector<std::string> &a, const std::vector<std::string> &b) {
    std::vector<std::string> result;

    for (int i = 0; i < a.size(); ++i) {
        std::string in = a[i] + " " + b[i];
        result.push_back(in);
    }

    return result;
}

#endif
