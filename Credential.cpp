#include "Credential.h"

void to_json(nlohmann::json &j, const Credential& c) {
    j = nlohmann::json{
            {"site", c.site},
            {"username", c.username},
            {"password", c.password}
    };
}

void from_json(const nlohmann::json &j, Credential& c) {
    j.at("site").get_to(c.site);
    j.at("username").get_to(c.username);
    j.at("password").get_to(c.password);
}