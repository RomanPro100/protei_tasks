#include <readargs.hpp>
using namespace readargs;

ArgMap readargs::parse(int argc, char** argv) {
    ArgMap args;

    bool reading_value = false;
    std::string argname;

    for (size_t i = 1; i < argc; i++) {
        const std::string arg = argv[i];
        if (reading_value == (arg[0] != '-')) {
            if (reading_value) {
                args.insert({argname, arg});
            } else {
                argname = arg;
            }
            reading_value = !reading_value;
        } else {
            // Неправильный формат аргументов
            // Сохраняем одно значение без флага, затем выходим
            if (!reading_value) {
                args.insert({"", arg});
            }
            return args;
        }
    }

    return args;
}

int readargs::as_int(ArgMap am, const char* flag) {
    return std::stoi(am.at(flag));
}
