#include <bits/stdc++.h>

std::string encrypt(const std::string &text, int shift) {
    std::string result = "";

    for (char c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            result += (c - base + shift) % 26 + base;
        } else {
            result += c;
        }
    }
    return result;
}

std::string decrypt(const std::string &text, int shift) {
    return encrypt(text, 26 - (shift % 26));
}

int main() {
    std::string text;
    int shift;
    int choice;

    std::cout << "Caesar Cipher Program\n";
    std::cout << "1. Encrypt\n2. Decrypt\nChoose an option: ";
    std::cin >> choice;
    std::cin.ignore();

    std::cout << "Enter the text: ";
    std::getline(std::cin, text);

    std::cout << "Enter the shift value: ";
    std::cin >> shift;

    if (choice == 1) {
        std::string encryptedText = encrypt(text, shift);
        std::cout << "Encrypted text: " << encryptedText << std::endl;
    } else if (choice == 2) {
        std::string decryptedText = decrypt(text, shift);
        std::cout << "Decrypted text: " << decryptedText << std::endl;
    } else {
        std::cout << "Invalid option chosen!" << std::endl;
    }

    return 0;
}
