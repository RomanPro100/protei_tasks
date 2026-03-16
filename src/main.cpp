#include <app_settings.hpp>
#include <cassert>
#include <iostream>
#include <menu.hpp>
#include <readargs.hpp>
#include <string>
#include <vec.hpp>

int main(int argc, char** argv) {
    ArgStore args = ArgStore(argc, argv);
    AppSettings settings = AppSettings(args);

    Menu main_menu = Menu();
    MenuItem enter_name = MenuItem("Ввести новое имя", [&settings]() {
        std::cout << "Ваше имя - " << settings.name()
                  << ", Введите новое имя: ";
        std::string new_name;
        std::getline(std::cin, new_name);
        settings.set_name(new_name);
        std::cout << "Новое имя " << settings.name() << " принято."
                  << std::endl;
    });
    main_menu.AddItem(enter_name);

    std::string vector_type;
    MenuItem enter_vector_type =
        MenuItem("Ввести тип вектора", [&vector_type]() {
            while (true) {
                std::cout << "Введите тип вектора (";
                for (const std::string& t : VECTOR_TYPES) {
                    std::cout << t << ", ";
                }
                std::cout << "\b\b): ";
                std::getline(std::cin, vector_type);
                for (const std::string& t : VECTOR_TYPES) {
                    if (t == vector_type) {
                        std::cout << "Введён тип " << t << std::endl;
                        return;
                    }
                }
                std::cerr << "Неправильный тип вектора: " << vector_type
                          << std::endl;
            }
        });
    main_menu.AddItem(enter_vector_type);

    std::array<SomeVectorType, VECTOR_SIZE> v;
    MenuItem enter_vector = MenuItem("Ввести вектор", [&vector_type, &v]() {
        if (vector_type == "int") {
            EnterVector<int>(v);
        } else if (vector_type == "long") {
            EnterVector<long>(v);
        } else if (vector_type == "float") {
            EnterVector<float>(v);
        } else if (vector_type == "double") {
            EnterVector<double>(v);
        } else {
            assert("" == vector_type && "Неожиданное значение типа вектора");
            std::cerr << "Тип вектора не установлен!" << std::endl;
        }
    });
    main_menu.AddItem(enter_vector);

    main_menu.Run();

    return 0;
}
