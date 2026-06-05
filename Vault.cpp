#include "Vault.h"

#include <iostream>
#include <utility>

void Vault::addCredential() {
    Credential c;

    std::cout << "Site: ";
    std::getline(std::cin, c.site);

    std::cout << "Username: ";
    std::getline(std::cin, c.username);

    std::cout << "Password: ";
    std::getline(std::cin, c.password);

    credentials.push_back(c);
}

void Vault::addCredential(std::string site, std::string username, std::string password) {
    Credential c;
    c.site = std::move(site);
    c.username = std::move(username);
    c.password = std::move(password);
    credentials.push_back(c);
}

void Vault::removeCredential() {
    std::string site;
    std::cout << "\nSite: ";
    std::getline(std::cin, site);
    std::erase_if(credentials, [&](const Credential& c) {return c.site == site;});
}

void Vault::removeCredential(const std::string &site) {
    std::erase_if(credentials, [&](const Credential& c) {return c.site == site;});
}

void Vault::listCredentials() {
    for (const auto& c : credentials) {
        std::cout << "\nSite: " << c.site
                  << "\nUsername: " << c.username
                  << "\nPassword: " << c.password
                  << "\n";
    }
}

void Vault::saveCredentials() {

}
