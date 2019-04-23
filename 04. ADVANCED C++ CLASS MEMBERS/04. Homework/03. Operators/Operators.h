#ifndef INC_03__OPERATORS_OPERATORS_H
#define INC_03__OPERATORS_OPERATORS_H

#include <sstream>
#include <ostream>
#include <vector>
#include <string>

std::ostream &operator<<(std::ostream &out, const std::vector<std::string> &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        out << vec[i] << "\n";
    }

    return out;
}

std::vector<std::string> &operator<<(std::vector<std::string>& v, const std::string& s) {
    v.push_back(s);

    return v;
}
std::string &operator+(std::string s, int i) {
    std::ostringstream oss;

    oss << s << i;

    oss.str();
}


#endif //INC_03__OPERATORS_OPERATORS_H
