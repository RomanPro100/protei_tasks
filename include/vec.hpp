#ifndef _VEC_
#define _VEC_
#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <variant>

const size_t VECTOR_SIZE = 4;
const char COORDINATE_LETTERS[VECTOR_SIZE] = {'x', 'y', 'z', 'w'};
const std::string VECTOR_TYPES[] = {"int", "long", "float", "double"};

typedef std::variant<int, long, float, double> SomeVectorType;
typedef std::array<SomeVectorType, VECTOR_SIZE> Vector;

template <typename T>
T EnterValue(T& elem) {
    std::string input;
    std::getline(std::cin, input);
    std::stringstream str_in(input);
    str_in >> elem;
    return elem;
}

template <typename T>
bool EnterVector(Vector& v) {
    std::cout << "Введите координаты вектора\n";
    size_t i = 0;
    while (i < VECTOR_SIZE) {
        T elem = 0;

        std::cout << COORDINATE_LETTERS[i] << ": ";
        EnterValue<T>(elem);
        if (VECTOR_SIZE - 1 == i && 0 == elem) {
            std::cerr << "Последняя координата не может быть равна 0"
                      << std::endl;
            continue;
        }

        v[i] = elem;
        i++;
    }

    std::cout << "Ваш вектор: [";
    for (size_t i = 0; i < VECTOR_SIZE; i++) {
        std::cout << std::get<T>(v[i]) << ", ";
    }
    std::cout << "\b\b]" << std::endl;
    return true;
}

#endif
