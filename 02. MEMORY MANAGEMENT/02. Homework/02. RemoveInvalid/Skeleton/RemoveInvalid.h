#ifndef DEMO_REMOVEINVALID_H
#define DEMO_REMOVEINVALID_H

#include "Company.h"
#include <list>

void removeInvalid(std::list<Company *> &companies) {
    auto i = companies.begin();

    while (i != companies.end()) {
        Company *c = *i;

        if (c->getId() < 0) {
            delete c;
            i = companies.erase(i);
            continue;
        }

        i++;
    }
}

#endif //DEMO_REMOVEINVALID_H
