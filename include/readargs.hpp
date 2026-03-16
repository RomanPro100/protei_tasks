#ifndef _READARGS_  // Защита от нескольких include
#define _READARGS_

#include <map>
#include <string>
#include <vector>

typedef std::map<const std::string, const std::string> ArgMap;
typedef std::vector<std::string> LonelyVec;

class ArgStore {
    ArgMap arg_map_ = {};
    LonelyVec lonely_flags_ = {};
    LonelyVec lonely_values_ = {};

   public:
    ArgStore(int argc, char** argv);

    const ArgMap& arg_map() const { return arg_map_; };
    const LonelyVec& lonely_flags() const { return lonely_flags_; };
    const LonelyVec& lonely_values() const { return lonely_values_; };

    std::string get(const char* flag);
    std::string get(const std::string& flag);
    std::string get_lonely_value(size_t i);
    bool has_lonely_flag(std::string& flag);
};

#endif
