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

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
