#ifndef _READARGS_  // Защита от нескольких include
#define _READARGS_

#include <map>
#include <string>
#include <vector>

typedef std::map<const std::string, const std::string> ArgMap;
typedef std::vector<std::string> LonelyVec;

class ArgStore {
    ArgMap argMap = {};
    LonelyVec lonelyFlags = {};
    LonelyVec lonelyValues = {};

   public:
    ArgStore(int argc, char** argv);

    ArgMap getArgMap();
    LonelyVec getLonelyFlags();
    LonelyVec getLonelyValues();

    std::string get(const char* flag);
    std::string get_lonely_value(size_t i);
    bool has_lonely_flag(const char* flag);
    // int get_int(const char* flag);
    // int get_value_int(size_t i);
};

#endif
