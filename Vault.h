#pragma once

#include <vector>
#include "Credential.h"

class Vault {
    public:
        void addCredential();
        void addCredential(std::string site, std::string username,  std::string password);
        void removeCredential();
        void removeCredential(const std::string &site);
        void listCredentials();
        void saveCredentials(const std::string& filename);
        void loadCredentials(const std::string& filename);

    private:
        std::vector<Credential> credentials;

};
