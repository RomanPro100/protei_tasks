#ifndef _APP_SETTINGS_
#define _APP_SETTINGS_
#include <readargs.hpp>

class AppSettings {
    int ipv4_ = -1;
    int port_ = -1;
    int idx_ = -1;
    std::string libs_ = "";

   public:
    std::string name_ = "";
    AppSettings(ArgStore& args);
    void set_name(std::string& name) { name_ = name; };

    int ipv4() { return ipv4_; };
    int port() { return port_; };
    int idx() { return idx_; };
    std::string libs() { return libs_; };
};

int ip_from_string(std::string s);

#endif
