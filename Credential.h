#pragma once
#include <string>
#include <nlohmann/json.hpp>

struct Credential {
    std::string site;
    std::string username;
    std::string password;
};

void to_json(nlohmann::json &j, const Credential& c);
void from_json(const nlohmann::json &j, Credential& c);
