#include <iostream>
#include <readargs.hpp>
const size_t VECTOR_SIZE = 4;

template <typename T>
void enter_vector(T* v) {
    for (size_t i = 0; i < VECTOR_SIZE; i++) {
        std::cin >> v[i];
    }
}

int main(int argc, char** argv) {
    readargs::ArgMap args = readargs::parse(argc, argv);
    for (auto& [k, m] : args) {
        std::cout << "Флаг: " << k << ", значение: " << m << std::endl;
    }
    // if (args.find("-qwerty") == args.end()) {
    //     args.insert({"-qwerty", "67"});
    // }
    // std::cout << readargs::as_int(args, "-p");

    std::string pseudonym;
    std::cout << "Введите псевдоним программы: ";
    std::cin >> pseudonym;

    std::string vector_type;
    std::cout << "Введите тип вектора (float или int): ";
    std::cin >> vector_type;

    std::cout << "Введите координаты вектора: ";
    if (vector_type == "float") {
        float v[VECTOR_SIZE];
        enter_vector<float>(v);
    } else if (vector_type == "int") {
        int v[VECTOR_SIZE];
        enter_vector<int>(v);
    }

    return 0;
}
