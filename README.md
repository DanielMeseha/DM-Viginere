Vigenère Cipher – C++ Encryption & Decryption

Project Description
In this Project, we implement the "Vigenere Cipher", which is a classical technique used to securely encode and decode text messages. It is made to allow a user to input a message and an encryption key, then to choose whether to encrypt or decrypt a text message or messages. The purpose of this project is to demonstrate fundamental cryptography concepts while applying discrete structures and algorithmic logic using C++. 

The program is designed for educational use and helps users understand how repeating keys and modular arithmetic are used in substitution-based encryption systems.

Programming Approach
- We write this program in C++ using modern features such as std::string.
- Functions are used to separate logic for:
  - Key expansion
  - Encryption
  - Decryption
  - Input validation
- All characters are converted to uppercase to ensure consistent encryption.
- Then, modular arithmetic mod 26 is used to keep characters within the alphabet range.
- The program then uses loops and conditionals to process user input and control program flow for the functionality of the program.
- Encryption and decryption results are logged to a text file for record keeping.

---

Authors
- Daniel Meseha

Date Published
- 12/18/25

How to Use the Program
1. Run the program.
2. Enter a message containing letters only.
3. Enter an encryption key containing letters only.
4. Then choose one of the following options:
   - `1` to encrypt the message
   - `2` to decrypt the message
5. The result will end up being displayed on the screen.
6. A log of the operation will be saved to `vigenere_log.txt`.
