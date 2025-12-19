# DM-Viginere 
// * File: vigenere_alt.cpp
// * Purpose: Vigenère Cipher Encryption & Decryption (Alternative Design)
// * Notes: Uses std::string and functions instead of C-style arrays


#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

// Function to generate repeating key
string generateKey(const string& text, const string& key) {
    string fullKey;
    for (size_t i = 0; i < text.length(); i++) {
        fullKey += key[i % key.length()];
    }
    return fullKey;
}

// Encrypt function
string encryptVigenere(const string& text, const string& key) {
    string cipher;
    for (size_t i = 0; i < text.length(); i++) {
        char encryptedChar = (text[i] - 'A' + key[i] - 'A') % 26 + 'A';
        cipher += encryptedChar;
    }
    return cipher;
}

// Decrypt function
string decryptVigenere(const string& text, const string& key) {
    string plain;
    for (size_t i = 0; i < text.length(); i++) {
        char decryptedChar = (text[i] - key[i] + 26) % 26 + 'A';
        plain += decryptedChar;
    }
    return plain;
}

int main() {
    string message, key;
    int option;
    ofstream logFile;

    cout << "Enter a message (letters only, no spaces): ";
    cin >> message;

    cout << "Enter encryption key: ";
    cin >> key;

    // Convert both to uppercase
    transform(message.begin(), message.end(), message.begin(), ::toupper);
    transform(key.begin(), key.end(), key.begin(), ::toupper);

    string expandedKey = generateKey(message, key);

    cout << "Choose an option:\n";
    cout << "1 - Encrypt\n";
    cout << "2 - Decrypt\n";
    cout << "Selection: ";
    cin >> option;

    logFile.open("vigenere_log.txt", ios::app);

    if (option == 1) {
        string encrypted = encryptVigenere(message, expandedKey);
        cout << "\nEncrypted Message: " << encrypted << endl;

        logFile << "\n--- ENCRYPTION ---";
        logFile << "\nMessage: " << message;
        logFile << "\nKey: " << key;
        logFile << "\nExpanded Key: " << expandedKey;
        logFile << "\nEncrypted: " << encrypted << endl;
    }
    else if (option == 2) {
        string decrypted = decryptVigenere(message, expandedKey);
        cout << "\nDecrypted Message: " << decrypted << endl;

        logFile << "\n--- DECRYPTION ---";
        logFile << "\nCipher Text: " << message;
        logFile << "\nKey: " << key;
        logFile << "\nExpanded Key: " << expandedKey;
        logFile << "\nDecrypted: " << decrypted << endl;
    }
    else {
        cout << "Invalid option selected." << endl;
    }

    logFile << "--------------------------\n";
    logFile.close();

    return 0;
}
