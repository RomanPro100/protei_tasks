#include <iostream>
#include <readargs.hpp>
#include <vec.hpp>

int main(int argc, char** argv) {
    ArgStore args = ArgStore(argc, argv);

    std::string pseudonym;
    std::cout << "Введите псевдоним программы: ";
    std::cin >> pseudonym;

    std::array<SomeVectorType, VECTOR_SIZE> v;
    std::string vector_type;
    while (true) {
        std::cout << "Введите тип вектора (int, long, float или double): ";
        std::cin >> vector_type;
        std::cin.ignore();

        if (vector_type == "int") {
            enter_vector<int>(v);
        } else if (vector_type == "long") {
            enter_vector<long>(v);
        } else if (vector_type == "float") {
            enter_vector<float>(v);
        } else if (vector_type == "double") {
            enter_vector<double>(v);
        } else {
            std::cerr << "Неправильный тип вектора" << std::endl;
            continue;
        }
        break;
    }

    return 0;
}
