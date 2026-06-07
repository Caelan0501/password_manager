#include "Vault.h"

#include <iostream>
#include <utility>
#include <fstream>
#include "nlohmann/json.hpp"

void Vault::addCredential(std::string site, std::string username, std::string password) {
    Credential c;
    c.site = std::move(site);
    c.username = std::move(username);
    c.password = std::move(password);
    credentials.push_back(c);
}

void Vault::removeCredentialBySite(const std::string &site) {
    std::erase_if(credentials, [&](const Credential& c) {return c.site == site;});
}

void Vault::removeCredentialByUsername(const std::string &username) {
    std::erase_if(credentials, [&](const Credential& c) {return c.username == username;});
}

void Vault::removeCredentialByPassword(const std::string &password) {
    std::erase_if(credentials, [&](const Credential& c) {return c.password == password;});
}

std::string Vault::listCredentials() {
    std::string s;
    for (const auto&[site, username, password] : credentials) {
        s += "\nSite: " + site;
        s += "\nUsername: " + username;
        s += "\nPassword: " + password;
        s += "\n";
    }
    return s;
}

void Vault::saveCredentials(const std::string& filename) {
    nlohmann::json j;
    j["Credentials"] = credentials;
    std::ofstream file(filename);
    file << j.dump(4);
}

void Vault::loadCredentials(const std::string& filename) {
    std::ifstream file(filename);
    nlohmann::json j = nlohmann::json::parse(file);
    credentials = j.at("Credentials").get<std::vector<Credential>>();
}