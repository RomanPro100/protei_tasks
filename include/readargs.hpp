#ifndef _READARGS_  // Защита от нескольких include
#define _READARGS_

#include <map>
#include <string>
namespace readargs {

typedef std::map<const std::string, const std::string> ArgMap;

ArgMap parse(int argc, char** argv);

int as_int(ArgMap am, const char* flag);

}  // namespace readargs
#endif
