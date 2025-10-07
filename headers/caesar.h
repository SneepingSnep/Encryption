/**
 * @brief Takes a pointer to a string, and returns a pointer to a encrypted
string
 *
 * This function takes a pointer to a string and encrypts it with a shift of 3
to the right in the alphabet
 * and then returns a pointer of the new encrypted string

 *
 * @param plaintext the string to be encrypted
 * @return A pointer to a new string that is the encrypted form of plaintext.
 */
char *caesar_encrypt(char *plaintext);

/**
 * @brief Takes a pointer to a string, and returns a pointer to a decrypted
string
 *
 * This function takes a pointer to a string and decrypts it with a shift of 3
to the left in the alphabet
 * and then returns a pointer of the new encrypted string

 *
 * @param plaintext the string to be decrypted
 * @return A pointer to a new string that is the decrypted form of plaintext.
 */
char *caesar_decrypt(char *ciphertext);