#pragma once

#include <vector>
#include "Credential.h"

class Vault {
    public:
        void addCredential();
        void removeCredential();
        void listCredentials();

    private:
        std::vector<Credential> credentials;
};
