//
// Created by Kristiyan Dimitrov on 2019-04-21.
//

#ifndef DEMO_COMPANY_H
#define DEMO_COMPANY_H

#include <istream>
#include <string>

class Company {
    std::string name;
    int id;
public:
    std::string getName() const {
        return this->name;
    }

    int getId() const {
        return this->id;
    }

    friend std::istream& operator>>(std::istream& stream, Company& company);
};

std::istream& operator>>(std::istream& stream, Company& company) {
    return stream >> company.name >> company.id;
}

std::ostream& operator<<(std::ostream& stream, const Company& company) {
    return stream << company.getName() << " " << company.getId();
}

#endif //DEMO_COMPANY_H
