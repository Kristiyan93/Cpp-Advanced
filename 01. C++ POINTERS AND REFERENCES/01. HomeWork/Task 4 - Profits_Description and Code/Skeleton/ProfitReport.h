#ifndef PROFIT_REPORT_H
#define PROFIT_REPORT_H

#include "Company.h"
#include "ProfitCalculator.h"

#include <string>
#include <sstream>

std::string getProfitReport(Company *pCompany, Company *to, const std::map<int, ProfitCalculator> &map) {
    std::ostringstream oss;

    for (Company* c = pCompany; c <= to; ++c) {
        int id = c->getId();

        ProfitCalculator profitCalculator = map.find(id)->second;
        oss << c->getName() << " = " << profitCalculator.calculateProfit(*c);

        if (c != to) {
            oss << '\n';
        }
    }

    return oss.str();
}

#endif //PROFIT_REPORT_H
