#ifndef CAR_CAR_H
#define CAR_CAR_H

class Car {
private:
    std::string brand;
    std::string model;
    int year;
public:
    Car(std::string brand, std::string model, int year)
    : brand(brand), model(model), year(year) {}

    std::string GetBrand() const {
        return brand;
    }

    std::string GetModel() const {
        return model;
    }

    int GetYear() const {
        return year;
    }
};

#endif //CAR_CAR_H
