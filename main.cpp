#include <iostream>
#include "Vault.h"

int main() {
    Vault vault;

    while (true) {
        std::cout << "\n1. Add Credential\n";
        std::cout << "2. List Credentials\n";
        std::cout << "3. Remove Credential\n";
        std::cout << "4. Save Credentials\n";
        std::cout << "5. Load Credentials\n";
        std::cout << "6. Exit\n";
        std::cout << "Choice: ";

        std::string site;
        std::string username;
        std::string password;
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choice) {
            case 1:
                std::cout << "Site: ";
                std::getline(std::cin, site);
                std::cout << "Username: ";
                std::getline(std::cin, username);
                std::cout << "Password: ";
                std::getline(std::cin, password);

                vault.addCredential(site, username, password);
            break;

            case 2:
                std::cout << vault.listCredentials();
            break;

            case 3:
                std::cout << "\nRemove by:\n";
                std::cout << "2. Site\n";
                std::cout << "3. Username\n";
                std::cout << "4. Password\n";
                std::cin >> choice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                switch (choice) {
                    case 1:
                        std::cout << "\nSite: ";
                        std::getline(std::cin, site);
                        vault.removeCredentialBySite(site);
                    break;
                    case 2:
                        std::cout << "\nUsername: ";
                        std::getline(std::cin, username);
                        vault.removeCredentialByUsername(username);
                    break;
                    case 3:
                        std::cout << "\nPassword: ";
                        std::getline(std::cin, password);
                        vault.removeCredentialByPassword(password);
                    break;
                    default:
                        std::cout << "Invalid choice.\n";
                }
            break;

            case 4:
                vault.saveCredentials("test.json");
            break;

            case 5:
                vault.loadCredentials("test.json");
            break;

            case 6:
                return 0;

            default:
                std::cout << "Invalid option\n";
        }
    }
}
