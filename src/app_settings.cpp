#include <app_settings.hpp>
#include <iostream>
#include <readargs.hpp>
#include <stdexcept>

AppSettings::AppSettings(ArgStore& args) {
    try {
        ipv4 = ip_from_string(args.get("-a"));
        port = std::stoi(args.get("-p"));
        name = args.get("-r");
        idx = std::stoi(args.get("-i"));
        libs = args.get("-L");
    } catch (std::out_of_range& _) {
        std::cerr << "Отсутствуют некоторые аргументы, использованы "
                     "значения по умолчанию"
                  << std::endl;
    }
}

int ip_from_string(std::string s) {
    int res = 0;
    int part = 0;
    int partIdx = 0;
    bool foundPart = false;
    for (char i : s) {
        if (part >= 256) {
            std::cerr
                << "Некорректный флаг: слишком большое значение компоненты"
                << std::endl;
            return -1;
        }
        if ('.' == i) {
            if (!foundPart) {
                std::cerr << "Некорректный флаг: отсутствует компонента"
                          << std::endl;
                return -1;
            }
            if (partIdx >= 4) {
                std::cerr << "Некорректный флаг: указано больше 4 компонент"
                          << std::endl;
                return -1;
            }
            res = res * 256 + part;
            partIdx++;
            part = 0;
            foundPart = false;
        } else if (i >= '0' || i <= '9') {
            foundPart = true;
            part = part * 10 + (i - '0');
        } else {
            std::cerr << "Некорректный флаг: запрещённый символ (" << i << ")"
                      << std::endl;
            return -1;
        }
    }

    return true;
};
