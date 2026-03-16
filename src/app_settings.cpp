#include <app_settings.hpp>
#include <iostream>
#include <readargs.hpp>
#include <stdexcept>

AppSettings::AppSettings(ArgStore& args) {
    try {
        ipv4_ = ip_from_string(args.get("-a"));
        port_ = std::stoi(args.get("-p"));
        name_ = args.get("-r");
        idx_ = std::stoi(args.get("-i"));
        libs_ = args.get("-L");
    } catch (const std::out_of_range& _) {
        std::cerr << "Отсутствуют некоторые аргументы, использованы "
                     "значения по умолчанию"
                  << std::endl;
    }
}

int ip_from_string(const std::string& s) {
    int res = 0;
    int part = 0;
    int part_idx = 0;
    bool found_part = false;
    for (char i : s) {
        if (part >= 256) {
            std::cerr
                << "Некорректный флаг: слишком большое значение компоненты"
                << std::endl;
            return -1;
        }
        if ('.' == i) {
            if (!found_part) {
                std::cerr << "Некорректный флаг: отсутствует компонента"
                          << std::endl;
                return -1;
            }
            if (part_idx >= 4) {
                std::cerr << "Некорректный флаг: указано больше 4 компонент"
                          << std::endl;
                return -1;
            }
            res = res * 256 + part;
            part_idx++;
            part = 0;
            found_part = false;
        } else if (i >= '0' && i <= '9') {
            found_part = true;
            part = part * 10 + (i - '0');
        } else {
            std::cerr << "Некорректный флаг: запрещённый символ (" << i << ")"
                      << std::endl;
            return -1;
        }
    }

    return true;
};
