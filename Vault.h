#pragma once

#include <vector>
#include "Credential.h"

class Vault {
    public:
        void addCredential(std::string site, std::string username,  std::string password);
        void removeCredentialBySite(const std::string &site);
        void removeCredentialByUsername(const std::string &username);
        void removeCredentialByPassword(const std::string &password);
        std::string listCredentials();
        void saveCredentials(const std::string& filename);
        void loadCredentials(const std::string& filename);

    private:
        std::vector<Credential> credentials;

};
