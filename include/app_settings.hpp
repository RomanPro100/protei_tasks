#ifndef _APP_SETTINGS_
#define _APP_SETTINGS_
#include <readargs.hpp>

class AppSettings {
    int ipv4 = -1;
    int port = -1;
    int idx = -1;
    std::string libs = "";

   public:
    std::string name = "";
    AppSettings(ArgStore& args);
    void set_name(std::string name_) { name = name_; };

    int Ipv4() { return ipv4; };
    int Port() { return port; };
    int Idx() { return idx; };
    std::string Libs() { return libs; };
};

int ip_from_string(std::string s);

#endif
