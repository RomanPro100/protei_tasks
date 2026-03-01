#include <readargs.hpp>

ArgStore::ArgStore(int argc, char** argv) {
    bool prev_is_flag = false;
    std::string prev_arg;

    for (size_t i = 1; i < argc; i++) {
        const std::string arg = argv[i];
        if (arg[0] == '-') {
            if (prev_is_flag) {
                lonelyFlags.push_back(prev_arg);
            }
            if (i == argc - 1) {
                lonelyFlags.push_back(arg);
            }
            prev_is_flag = true;
        } else {
            if (prev_is_flag) {
                argMap.insert({prev_arg, arg});
            } else {
                lonelyValues.push_back(arg);
            }
            prev_is_flag = false;
        }
        prev_arg = arg;
    }
}

ArgMap ArgStore::getArgMap() { return argMap; };
LonelyVec ArgStore::getLonelyFlags() { return lonelyFlags; };
LonelyVec ArgStore::getLonelyValues() { return lonelyValues; };

std::string ArgStore::get(const char* flag) { return argMap.at(flag); };
std::string ArgStore::get_lonely_value(size_t i) { return lonelyValues.at(i); };
// int ArgStore::get_int(const char* flag) { return std::stoi(argMap.at(flag));
// } int ArgStore::get_value_int(size_t i) { return
// std::stoi(lonelyValues.at(i)); }
