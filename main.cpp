#include <iostream>
#include "Vault.h"

int main() {
    Vault vault;

    while (true) {
        std::cout << "\n1. Add Credential\n";
        std::cout << "2. List Credentials\n";
        std::cout << "3. Remove Credential\n";
        std::cout << "4. Exit\n";
        std::cout << "Choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                vault.addCredential();
            break;

            case 2:
                vault.listCredentials();
            break;

            case 3:
                vault.removeCredential();
            break;

            case 4:
                return 0;

            default:
                std::cout << "Invalid option\n";
        }
    }
}
