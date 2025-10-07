#include "../headers/caesar.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET "abcdefghijklmnopqrstuvwxyz"
char *caesar_encrypt(char *plaintext) {
  printf("%s\n", plaintext);
  char letterinstring;
  char *encryptedstringpointer = (char *)malloc(strlen(plaintext) + 1);
  memset(encryptedstringpointer, 0, strlen(plaintext) + 1);
  for (int i = 0; i < strlen(plaintext); i++) {
    letterinstring = plaintext[i];

    for (int j = 0; j < strlen(ALPHABET); j++) {

      if (letterinstring == ALPHABET[j]) {
        // char brother = ALPHABET[(j + 3) % strlen(ALPHABET)];
        // int brother3 = (j + 3) % strlen(ALPHABET);
        // char brother2 = ALPHABET[1];
        // int brother4 = strlen(ALPHABET);
        encryptedstringpointer[i] = ALPHABET[(j + 3) % strlen(ALPHABET)];
      }
    }
  }
  return encryptedstringpointer;
}

char *caesar_decrypt(char *ciphertext) {
  printf("%s\n", ciphertext);
  char letterinstring;
  char *decryptedstringpointer = (char *)malloc(strlen(ciphertext) + 1);
  memset(decryptedstringpointer, 0, strlen(ciphertext) + 1);

  for (int i = 0; i < strlen(ciphertext); i++) {
    letterinstring = ciphertext[i];
    // char brother = ALPHABET[3];
    for (int j = 0; j < strlen(ALPHABET); j++) {

      if (letterinstring == ALPHABET[j]) {
        // char brother = ALPHABET[(j + 3) % sizeof(ALPHABET)];
        char brother = ALPHABET[(j - 3 + strlen(ALPHABET)) % strlen(ALPHABET)];
        int strlength = strlen(ALPHABET);
        int borther = (j - 3) % (int)strlen(ALPHABET);
        int brother2 = (0 - 3) % (size_t)26;
        decryptedstringpointer[i] = brother;
      }
    }
  }
  return decryptedstringpointer;
}