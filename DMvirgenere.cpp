#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cctype>

using namespace std;

bool lettersOnly(const string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isalpha(static_cast<unsigned char>(c))) return false;
    }
    return true;
}

string toUpperCopy(string s) {
    transform(s.begin(), s.end(), s.begin(),
        [](unsigned char ch) { return static_cast<char>(toupper(ch)); });
    return s;
}

string expandKey(const string& text, const string& key) {
    string fullKey;
    fullKey.reserve(text.size());
    for (size_t i = 0; i < text.size(); ++i) {
        fullKey.push_back(key[i % key.size()]);
    }
    return fullKey;
}

string vigenereEncrypt(const string& plain, const string& fullKey) {
    string out;
    out.reserve(plain.size());
    for (size_t i = 0; i < plain.size(); ++i) {
        char enc = static_cast<char>(((plain[i] - 'A') + (fullKey[i] - 'A')) % 26 + 'A');
        out.push_back(enc);
    }
    return out;
}

string vigenereDecrypt(const string& cipher, const string& fullKey) {
    string out;
    out.reserve(cipher.size());
    for (size_t i = 0; i < cipher.size(); ++i) {
        char dec = static_cast<char>(((cipher[i] - 'A') - (fullKey[i] - 'A') + 26) % 26 + 'A');
        out.push_back(dec);
    }
    return out;
}

int main() {
    string message, key;
    int choice = 0;

    cout << "Enter message (letters only, no spaces): ";
    cin >> message;

    cout << "Enter key (letters only): ";
    cin >> key;

    if (!lettersOnly(message) || !lettersOnly(key)) {
        cout << "\nError: Message and key must contain letters only (A-Z).\n";
        return 0;
    }

    message = toUpperCopy(message);
    key = toUpperCopy(key);

    string fullKey = expandKey(message, key);

    cout << "\nChoose:\n";
    cout << "1) Encrypt\n";
    cout << "2) Decrypt\n";
    cout << "Selection: ";
    cin >> choice;

    ofstream log("vigenere_log.txt", ios::app);

    if (choice == 1) {
        string encrypted = vigenereEncrypt(message, fullKey);

        cout << "\nOriginal : " << message;
        cout << "\nKey      : " << key;
        cout << "\nFull Key : " << fullKey;
        cout << "\nEncrypted: " << encrypted << "\n";

        log << "\n=== ENCRYPT ===\n";
        log << "Original : " << message << "\n";
        log << "Key      : " << key << "\n";
        log << "Full Key : " << fullKey << "\n";
        log << "Encrypted: " << encrypted << "\n";
        log << "-----------------------------\n";
    }
    else if (choice == 2) {
        string decrypted = vigenereDecrypt(message, fullKey);

        cout << "\nCipher   : " << message;
        cout << "\nKey      : " << key;
        cout << "\nFull Key : " << fullKey;
        cout << "\nDecrypted: " << decrypted << "\n";

        log << "\n=== DECRYPT ===\n";
        log << "Cipher   : " << message << "\n";
        log << "Key      : " << key << "\n";
        log << "Full Key : " << fullKey << "\n";
        log << "Decrypted: " << decrypted << "\n";
        log << "-----------------------------\n";
    }
    else {
        cout << "\nInvalid selection.\n";
        log << "\nInvalid selection entered.\n";
        log << "-----------------------------\n";
    }

    log.close();
    return 0;
}
