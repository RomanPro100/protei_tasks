#include <readargs.hpp>

ArgStore::ArgStore(int argc, char** argv) {
    bool prev_is_flag = false;
    std::string prev_arg;

    for (size_t i = 1; i < argc; i++) {
        const std::string arg = argv[i];
        if (arg[0] == '-') {
            if (prev_is_flag) {
                lonely_flags_.push_back(prev_arg);
            }
            if (i == argc - 1) {
                lonely_flags_.push_back(arg);
            }
            prev_is_flag = true;
        } else {
            if (prev_is_flag) {
                arg_map_.insert({prev_arg, arg});
            } else {
                lonely_values_.push_back(arg);
            }
            prev_is_flag = false;
        }
        prev_arg = arg;
    }
}

std::string ArgStore::get(const char* flag) { return arg_map_.at(flag); };
std::string ArgStore::get(const std::string& flag) {
    return arg_map_.at(flag);
};
std::string ArgStore::get_lonely_value(size_t i) {
    return lonely_values_.at(i);
};
