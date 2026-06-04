#include "Vault.h"

#include <iostream>

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

void Vault::listCredentials() {
    for (const auto& c : credentials) {
        std::cout << "\nSite: " << c.site
                  << "\nUsername: " << c.username
                  << "\nPassword: " << c.password
                  << "\n";
    }
}

void Vault::removeCredential() {
    std::string site;
    std::cout << "\nSite: ";
    std::getline(std::cin, site);
    std::erase_if(credentials, [&](const Credential& c) {return c.site == site;});
}