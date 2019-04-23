//
// Created by Kristiyan Dimitrov on 2019-04-21.
//

#ifndef DEMO_TRYPARSE_H
#define DEMO_TRYPARSE_H

#include <sstream>

bool tryParse(std::string s, int &digit) {
    std::istringstream iss(s);

    return (bool) (iss >> digit);
}

#endif //DEMO_TRYPARSE_H
