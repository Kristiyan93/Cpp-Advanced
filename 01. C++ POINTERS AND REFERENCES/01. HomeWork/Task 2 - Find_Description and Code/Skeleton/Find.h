//
// Created by Kristiyan Dimitrov on 2019-04-21.
//

#ifndef DEMO_FIND_H
#define DEMO_FIND_H

#include "Company.h"

#include <vector>

Company* find(const std::vector<Company *> &companies, int searchId) {
    for (Company* company : companies) {
        if (company->getId() == searchId) {
            return company;
        }
    }

    return nullptr;
}

#endif //DEMO_FIND_H
