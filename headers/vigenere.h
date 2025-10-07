/**
 * @brief Takes a pointer to a string and a key, and returns a pointer to a
encrypted string
 *
 * This function takes a pointer to a string and a key and encrypts the whole
string with the key provided

 * and then returns a pointer of the new encrypted string

 *
 * @param plaintext the string to be encrypted, @param key the string you want
to encrypt with. Both pointers
 * @return A pointer to a new string that is the encrypted form of plaintext.
 */
char *vigenere_encrypt(char *plaintext, char *key);
/**
 * @brief Takes a pointer to a string and a key, and returns a pointer to a
decrypted string
 *
 * This function takes a pointer to a string and a key and then decrypts the
whole string with the key provided

 * and then returns a pointer of the new encrypted string

 *
 * @param plaintext the string to be decrypted, @param key the string you want
to decrypt with. Both pointers
 * @return A pointer to a new string that is the decrypted form of plaintext.
 */
char *vigenere_decrypt(char *ciphertext, char *key);