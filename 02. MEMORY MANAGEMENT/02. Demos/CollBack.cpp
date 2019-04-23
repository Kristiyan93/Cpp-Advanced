#include <iostream>
#include <vector>

std::vector<int> filter(std::vector<int> &vector, bool (*shouldFilter)(const int number));

bool biggerThanTree(const int);

bool isEven(const int);

bool negative(const int);

void getPrint(std::vector<int>&);

int main() {
    std::vector<int> numbers {5, 2 , 3, -2, -4, 6};

    std::vector<int> vec = filter(numbers, negative);

    std::vector<int> vec2 = filter(numbers, isEven);

    std::vector<int> vec3 = filter(numbers, biggerThanTree);

    std::vector<int> vecLamb = filter(numbers, [](const int number) {
        return number % 2 != 0;
    });

    getPrint(vec);
    getPrint(vec2);
    getPrint(vec3);
    getPrint(vecLamb);

    return 0;
}

void getPrint(std::vector<int>& vector) {
    for (int i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] << " ";
    }

    std::cout << std::endl;
}

bool negative(const int number) {
    return number < 1;
}

bool isEven(const int number) {
    return number % 2 == 0;
}

bool biggerThanTree(const int number) {
    return number > 3;
}

std::vector<int> filter(std::vector<int> &vector, bool (*shouldFilter)(const int)) {
    std::vector<int> vec;

    for (int i = 0; i < vector.size(); ++i) {
        if (shouldFilter(vector[i])) {
            vec.push_back(vector[i]);
        }
    }

    return vec;
}